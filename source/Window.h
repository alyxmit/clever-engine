#pragma once
#include <SDL3/SDL.h>
#include <iostream>
#include <memory>

class Window
{
public:
    Window()
    {
        SDLWindow = SDL_CreateWindow(
            "Clever Engine",
            1280, 800,
            SDL_WINDOW_RESIZABLE
        );
        if (!SDLWindow)
        {
            std::cerr << "Failed to create window: " << SDL_GetError() << std::endl;
            throw std::runtime_error("SDL_CreateWindow failed!");
        }

        SDLWindowIcon("icon.bmp");
    }

    Window(const Window &) = delete;
    Window &operator=(const Window &) = delete;

    ~Window()
    {
        if (SDLWindow && SDL_WasInit(SDL_INIT_VIDEO))
        {
            SDL_DestroyWindow(SDLWindow);
            std::cout << "Window destroyed (SDL_DestroyWinow)\n";
        }
    }

private:
    SDL_Window *SDLWindow{nullptr};

    void SDLWindowIcon(const char *path)
    {
        SDL_Surface *Icon = SDL_LoadBMP(path);
        if (!Icon)
        {
            std::cerr << "Failed to load icon: " << SDL_GetError() << std::endl;
            return;
        }
        SDL_SetWindowIcon(SDLWindow, Icon);
        SDL_DestroySurface(Icon);
    }
};
