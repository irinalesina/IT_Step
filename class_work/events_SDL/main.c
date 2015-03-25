#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <stdbool.h>
#define SCREEN_WIDTH 640
#define SCREEN_HIGHT 480


int main()
{
    //проинициализировать SDL
    if(SDL_Init(SDL_INIT_VIDEO))
    {
        fprintf(stderr, "SDL_INIT Error: %s\n", SDL_GetError());
        exit(1);

    }

    SDL_Window *win = SDL_CreateWindow("Hello World ^_^", 100, 100, SCREEN_WIDTH, SCREEN_HIGHT, SDL_WINDOW_SHOWN);

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

    SDL_Surface *bmp = SDL_LoadBMP("../sdl/hello.bmp");

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
    bool quit = false;

    SDL_Event e;

    int x = 10, y = 10;//координаты точки, которую рисуем

    while(!quit)
    {
        while(SDL_PollEvent(&e))//user requests quit
        {
            if(e.type == SDL_QUIT)
            {
                quit = true;
            }
            if(e.type == SDL_KEYDOWN)
            {
                SDL_KeyboardEvent k_event = e.key;
                switch(k_event.keysym.scancode)
                {
                case SDL_SCANCODE_A:
                    x = (x-10+SCREEN_WIDTH) % SCREEN_WIDTH;
                    break;
                case SDL_SCANCODE_D:
                    x = (x+10+SCREEN_WIDTH) % SCREEN_WIDTH;
                    break;
                case SDL_SCANCODE_W:
                    y = (y-10+SCREEN_HIGHT) % SCREEN_HIGHT;
                    break;
                case SDL_SCANCODE_S:
                    y = (y+10+SCREEN_HIGHT) % SCREEN_HIGHT;
                    break;

                }

            }
            /*if(e.type == SDL_MOUSEBUTTONDOWN)
            {
                quit = true;
            }*/
        }
        SDL_SetRenderDrawColor(ren, 0x00, 0x00, 0x00, 0xFF);
        SDL_RenderClear(ren);
        SDL_SetRenderDrawColor(ren, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderDrawLine(ren, x, y, SCREEN_WIDTH / 2, SCREEN_HIGHT / 2);
        SDL_RenderPresent(ren);
    }

    SDL_DestroyTexture(tex);
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();

    return 0;
}



