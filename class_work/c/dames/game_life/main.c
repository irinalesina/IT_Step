#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include "life.h"

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

    SDL_Window *win = SDL_CreateWindow("Life Game", 100, 100, SCREEN_WIDTH, SCREEN_HIGHT, SDL_WINDOW_OPENGL);

    if(!win)
    {
        fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        exit(1);
    }

    SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if(!ren)
    {//Создание рендерера
        SDL_DestroyWindow(win);
        fprintf(stderr, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
        SDL_Quit();
        exit(1);
    }

    SDL_RenderClear(ren);

    //update the screen
    SDL_RenderPresent(ren);

    bool quit = false;
    SDL_Event e;

    SDL_Rect rect;
    rect.x = 0;
    rect.y = 0;
    rect.h = 10;
    rect.w = 10;

    while(!quit)
    {
        while(SDL_PollEvent(&e))//о
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
                    rect.x = (rect.x - 10 + SCREEN_WIDTH) % SCREEN_WIDTH;
                    break;
                case SDL_SCANCODE_D:
                    rect.x = (rect.x + 10 + SCREEN_WIDTH) % SCREEN_WIDTH;
                    break;
                case SDL_SCANCODE_W:
                    rect.y = (rect.y -10 + SCREEN_HIGHT) % SCREEN_HIGHT;
                    break;
                case SDL_SCANCODE_S:
                    rect.y = (rect.y + 10 + SCREEN_HIGHT) % SCREEN_HIGHT;
                    break;
                }

            }

        }

        SDL_SetRenderDrawColor(ren, 0x55, 0x00, 0x00, 0xFF);
        //SDL_RenderClear(ren);
        SDL_SetRenderDrawColor(ren, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderFillRect(ren, &rect);
        SDL_RenderPresent(ren);


    }
    //очистка экрана
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 0;
}
