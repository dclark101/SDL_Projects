#include <iostream>
#include <SDL.h>
#include "Window.h"
using namespace std;



int main(int argc, char* argv[]) {
    Window GameWindow;
    SDL_Event Event;
    bool quit = false;

    GameWindow.loadBMP(R"(C:\Users\Dante Clark\CLionProjects\sdl_projects\key_press_proj\images\press.bmp)");

    while (!quit) {
        GameWindow.render();
        while (SDL_PollEvent(&Event) != 0) {
            if (Event.type == SDL_QUIT) {
                quit = true;
            } else if (Event.type == SDL_KEYDOWN) {
                GameWindow.key_pressed(Event.key.keysym.sym);
            }
        }
    }

    GameWindow.close();
    return 0;
}