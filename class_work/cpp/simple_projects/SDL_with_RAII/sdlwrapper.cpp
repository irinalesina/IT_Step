#include <iostream>
#include "sdlwrapper.h"
#include <exception>
#include <cstring>
#include <cstdio>

using namespace std;

class SDLExeption: public exception
{
public:
    SDLExeption(char *message)
    {
        strncpy(this->message, message, 512);
    }
    const char *what() const noexcept override
    {
        return message;
    }
private:
    char message[512];
};

SDLWrapper::SDLWrapper()
{
    clog << "ctor sdl wropper\n";
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        char message[512];
        sprintf(message, "SDL_Init: %s", SDL_GetError());
        throw SDLExeption(message);
    }
}

SDLWrapper::~SDLWrapper()
{
    SDL_Quit();
    clog << "dtor sdl wropper\n";
}



SDLWindowWrapper::SDLWindowWrapper(const char *title, int x, int y, int w, int h, Uint32 flags):
    win_(nullptr)
{
    clog << "ctor sdl window wropper\n";
    win_ = SDL_CreateWindow(title, x, y, w, h, flags);
    if(win_ == nullptr)
    {
        char message[512];
        sprintf(message, "SDL CreatewONDOW: %s", SDL_GetError());
        throw SDLExeption(message);
    }
}

SDLWindowWrapper::~SDLWindowWrapper()
{
    SDL_DestroyWindow(win_);
    clog << "dtor sdl window wropper\n";
}


SDLRendererWrapper::SDLRendererWrapper(SDL_Window *win, int index, Uint32 flags):
    ren_(nullptr)
{
    clog << "ctor sdl renderer wropper\n";
    ren_ = SDL_CreateRenderer(win, index, flags);
    if(ren_ == nullptr)
    {
        char message[512];
        sprintf(message, "SDL CreateRenderer: %s", SDL_GetError());
        throw SDLExeption(message);
    }
}

SDLRendererWrapper::~SDLRendererWrapper()
{
    SDL_DestroyRenderer(ren_);
    clog << "dtor sdl renderer wropper\n";
}
