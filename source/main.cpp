#include <SDL3/SDL.h>
#include <iostream>

int main(int, char**) {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* Window{SDL_CreateWindow(
        "Clever Engine", 1800, 1080, 0
    )};

    SDL_Surface* icon = SDL_LoadBMP("icon.bmp");
    if (icon) {
        SDL_SetWindowIcon(Window, icon);
        SDL_DestroySurface(icon);
    }

    bool IsRunning = true;
    SDL_Event Event;
    while (IsRunning) {
        while (SDL_PollEvent(&Event)) {
            if (Event.type == SDL_EVENT_QUIT) {
                IsRunning = false;
            }
            
        }
        
    }

    SDL_DestroyWindow(Window);
    SDL_Quit();

    return 0;
    
}