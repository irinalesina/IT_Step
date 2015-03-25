#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

int main()
{
    //проинициализировать SDL
    if(SDL_Init(SDL_INIT_VIDEO))
    {
        fprintf(stderr, "SDL_INIT Error: %s\n", SDL_GetError());
        exit(1);

    }

    SDL_Window *win = SDL_CreateWindow("Hello World ^_^", 100, 100, 640, 480, SDL_WINDOW_SHOWN);

    if(!win)
    {
        fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        exit(1);
    }

    SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if(!ren)
    {
        SDL_DestroyWindow(win);
        fprintf(stderr, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
        SDL_Quit();
        exit(1);
    }

    SDL_Surface *bmp = SDL_LoadBMP("hello.bmp");

    if(!bmp)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        fprintf(stderr, "SDL_LoadBMP Error: %s\n", SDL_GetError());
        SDL_Quit();
        exit(1);
    }

    SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, bmp);
    SDL_FreeSurface(bmp);

    if(!tex)
    {
        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        fprintf(stderr, "SDL_CreateTextureFromSurface Error: %s\n", SDL_GetError());
        SDL_Quit();
        exit(1);
    }

    //Now lets draw our image
    //first clear the renderer
    SDL_RenderClear(ren);
    //draw the texture
    SDL_RenderCopy(ren, tex, NULL, NULL);
    //update the screen
    SDL_RenderPresent(ren);
    //have the program wait for 4000ms so we get a chance to see the screen
    SDL_Delay(4000);

    SDL_DestroyTexture(tex);
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();


    return 0;
}










