#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define SCREEN_HEIGHT 640
#define SCREEN_WIDTH 640

int main()
{
    if(SDL_Init(SDL_INIT_VIDEO))
    {
        fprintf(stderr, "SDL_Init Error: %s\n", SDL_GetError());
        exit(1);
    }

    SDL_Window *win = SDL_CreateWindow("Moving start", 100, 100, SCREEN_HEIGHT, SCREEN_WIDTH, SDL_WINDOW_SHOWN);

    if(!win)
    {
        fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        exit(1);
    }

    if(!IMG_Init(IMG_INIT_PNG)) //***
    {
        fprintf(stderr, "IMG_Init Error: %s\n", IMG_GetError());
        SDL_DestroyWindow(win);
        SDL_Quit();
        exit(1);
    }

    SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if(!ren)
    {
        fprintf(stderr, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
        IMG_Quit(); //***
        SDL_DestroyWindow(win);
        SDL_Quit();
        exit(1);
    }

    //SDL_Surface *png = IMG_Load("../../MediaResources/star.png"); //***
    SDL_Surface *png = IMG_Load("spiral.png");

    if(!png)
    {
        fprintf(stderr, "IMG_Load Error: %s\n", IMG_GetError());
        SDL_DestroyRenderer(ren);
        IMG_Quit(); //***
        SDL_DestroyWindow(win);
        SDL_Quit();
        exit(1);
    }

    SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, png);
    SDL_FreeSurface(png);

    if(!tex)
    {
        fprintf(stderr, "SDL_CreateTextureFromSurface Error: %s\n", SDL_GetError());
        SDL_DestroyRenderer(ren);
        IMG_Quit(); //***
        SDL_DestroyWindow(win);
        SDL_Quit();
        exit(1);
    }
/*
    SDL_Rect dstRect = {SCREEN_HEIGHT / 2 - 32, SCREEN_WIDTH / 2 - 32, 64, 64};

    SDL_SetRenderDrawColor(ren, 0x00, 0xFF, 0xFF, 0xFF);
*/
/*
    SDL_RenderClear(ren);

    SDL_RenderCopy(ren, tex, NULL, &dstRect);

    SDL_RenderPresent(ren);

    SDL_Delay(4000);
*/
/*
    for(int i = 0; i < 10; ++i)
    {
        dstRect.h *= 1.5;
        dstRect.w *= 1.5;
        dstRect.x = SCREEN_HEIGHT / 2 - dstRect.h / 2;
        dstRect.y = SCREEN_WIDTH / 2 - dstRect.w / 2;
        SDL_RenderClear(ren);
        SDL_RenderCopy(ren, tex, NULL, &dstRect);
        SDL_RenderPresent(ren);
        SDL_Delay(50);
    }
*/

    bool quit = false;

    SDL_Rect dest_rect = {0, 0, 64*4, 128*4};
    SDL_Rect position_in_imeg = {192, 0, 64, 128};

    SDL_SetRenderDrawColor(ren, 0x00, 0xFF, 0xFF, 0xFF);
    SDL_Event e;

    while(!quit)
    {
        while(SDL_PollEvent(&e))//о
        {
            switch(e.type)
            {
            case SDL_MOUSEBUTTONDOWN:
            case SDL_QUIT:
            case SDL_KEYDOWN:
                quit = true;
            }

        }
        SDL_RenderClear(ren);
        SDL_RenderCopy(ren, tex, &position_in_imeg, &dest_rect);
        SDL_RenderPresent(ren);
        SDL_Delay(80);
        if(position_in_imeg.x < 0)
        {
            position_in_imeg.x = 192;
        }
        else
        {
            position_in_imeg.x -= 64;
        }

    }



    SDL_DestroyTexture(tex);
    SDL_DestroyRenderer(ren);
    IMG_Quit(); //***
    SDL_DestroyWindow(win);
    SDL_Quit();

    return 0;
}
