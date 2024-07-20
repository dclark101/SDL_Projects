//
// Created by Dante Clark on 7/18/2024.
//
#include <SDL.h>
#include <iostream>

#ifndef KEY_PRESS_PROJ_WINDOW_H
#define KEY_PRESS_PROJ_WINDOW_H

class Window {
private:
    SDL_Window* SDLWindow = nullptr;
    SDL_Surface* SDLWindowSurface = nullptr;
    SDL_Surface* SDLImageSurface = nullptr;
public:
    Window() {
        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            SDL_Log("Error associated with SDL_INIT_VIDEO\nError: %s", SDL_GetError());
        } else {
            SDLWindow = SDL_CreateWindow("key press", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 600, 450, 0);
            SDLWindowSurface = SDL_GetWindowSurface(SDLWindow);
            SDL_FillRect(SDLWindowSurface, nullptr, SDL_MapRGB(SDLWindowSurface->format, 255, 255, 255));
        }
    }
    void render() {
        SDL_BlitSurface(SDLImageSurface, nullptr, SDLWindowSurface, nullptr);
        SDL_UpdateWindowSurface(SDLWindow);
    }

    void loadBMP(std::string path) {
        SDLImageSurface = SDL_LoadBMP(path.c_str());
    }

    void key_pressed(int key) {
        if (SDLImageSurface == nullptr) {
            SDL_FreeSurface(SDLImageSurface);
            SDL_Log("Freed!");
        }

        switch (key) {
            case SDLK_UP: loadBMP(R"(C:\Users\Dante Clark\CLionProjects\sdl_projects\key_press_proj\images\up.bmp)");
            break;
            case SDLK_DOWN: loadBMP(R"(C:\Users\Dante Clark\CLionProjects\sdl_projects\key_press_proj\images\down.bmp)");
                break;
            case SDLK_LEFT: loadBMP(R"(C:\Users\Dante Clark\CLionProjects\sdl_projects\key_press_proj\images\left.bmp)");
                break;
            case SDLK_RIGHT: loadBMP(R"(C:\Users\Dante Clark\CLionProjects\sdl_projects\key_press_proj\images\right.bmp)");
                break;
            default:
                break;
        }
    }

    void close() {
        SDL_FreeSurface(SDLWindowSurface);
        SDL_DestroyWindow(SDLWindow);
        SDL_Quit();
    };
};


#endif //KEY_PRESS_PROJ_WINDOW_H
