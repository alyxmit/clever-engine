#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_ttf/SDL_ttf.h>
#include "Window.h"

int main(int, char **)
{
    SDL_Init(SDL_INIT_VIDEO);
    Window Window;

    bool IsRunning = true;
    SDL_Event Event;
    while (IsRunning)
    {
        while (SDL_PollEvent(&Event))
        {
            if (Event.type == SDL_EVENT_QUIT)
            {
                IsRunning = false;
            }
        }
    }

    SDL_Quit();

    return 0;
}