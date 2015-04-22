#define _POSIX_C_SOURCE 200112L
#define ALSA_PCM_NEW_HW_PARAMS_API


#include <stdio.h>
#include <alsa/asoundlib.h>//работа со звук библиотекой альса
#include <alloca.h>
#include <unistd.h>



//pcm - используется для оцифровки аналоговых сигналов

int main()
{
    long loops;
    int rc, size;
    snd_pcm_t *handle;
    snd_pcm_hw_params_t *params;
    unsigned int val;
    int dir;
    snd_pcm_uframes_t frames;
    char *buffer;

    /* Open PCM device for playback */
    rc = snd_pcm_open(&handle, "default", SND_PCM_STREAM_PLAYBACK, 0);

    if(rc < 0)
    {
        fprintf(stderr, "Unable to open pcm device: %s\n", snd_strerror(rc));
        exit(1);
    }

    /* Allocate a hardware parameters object */
    snd_pcm_hw_params_alloca(&params);

    /* Fill it in with default values */
    snd_pcm_hw_params_any(handle, params);

    /* Set the desired hardware parameters */

    /* Interleaved mode */
    snd_pcm_hw_params_set_access(handle, params, SND_PCM_ACCESS_RW_INTERLEAVED);

    /* Signed 16-bit little-endian format */
    snd_pcm_hw_params_set_format(handle, params, SND_PCM_FORMAT_S16_LE);

    /* Two channels (stereo) */
    snd_pcm_hw_params_set_channels(handle, params, 1);

    /* 44100 bets/second sampling rate (CD quality) */
    val = 44100;
    snd_pcm_hw_params_set_rate_near(handle, params, &val, &dir);

    /* Set period size to 32 frames */
    frames = 32;
    snd_pcm_hw_params_set_period_size_near(handle, params, &frames, &dir);

    /* Write the parameters to the driver */
    rc = snd_pcm_hw_params(handle, params);
    if(rc < 0)
    {
        fprintf(stderr, "Unable to set hw parameters: %s\n", snd_strerror(rc));
        exit(1);
    }

    /* Use a buffer large enough to hold one period */
    snd_pcm_hw_params_get_period_size(params, &frames, &dir);

    snd_pcm_prepare(handle);

    size = frames * 2; // 2 bytes/sample, 2channels
    buffer = (char *)malloc(size);

    /* We want to lop for 5 seconds */
    snd_pcm_hw_params_get_period_time(params, &val, &dir);

    /* 5 seconds in microseconds divided by *period time */
    loops = 5000000 / val;

    while(loops > 0)
    {
        loops--;
        rc = read(0, buffer, size);
        if(rc == 0)
        {
            fprintf(stderr, "End of file on input\n");
            break;
        }
        else if(rc != size)
        {
            fprintf(stderr, "Short read: read %d bytes\n", rc);
        }
        rc = snd_pcm_writei(handle, buffer, frames);//пишем чередованием
        if(rc == -EPIPE)//не успели записать данные в буфер перед указателем звуковой карты
        {
            /* EPIPE means unerrun */
            fprintf(stderr, "underrun occurred\n");
            snd_pcm_prepare(handle);
        }
        else if(rc < 0)
        {
            fprintf(stderr, "Error from writei: %s\n", snd_strerror(rc));
        }
        else if(rc != (int)frames)
        {
            fprintf(stderr, "short write, write %d frames\n", rc);
        }
    }

    snd_pcm_drain(handle);
    snd_pcm_close(handle);
    free(buffer);

    return 0;
}
