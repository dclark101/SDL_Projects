#define SDL_MAIN_HANDLED
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "TextureRectangle.h"
#include "AnimatedSprite.h"

using namespace std;

int main(int argc, char** argv) {
	SDL_Window* main_window = SDL_CreateWindow("SDL Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(main_window, -1, SDL_RENDERER_ACCELERATED);
	//TextureRectangle rect{ renderer, "C:\\Users\\Dante Clark\\OneDrive\\Documents\\file.png" };
	//rect.SetRectangleProperties(0, 0, 640, 480);


	AnimatedSprite animated_sprite(renderer, "C:\\Users\\Dante Clark\\OneDrive\\Documents\\edited.png");

	animated_sprite.Draw(200, 200, 150, 150);

	bool is_running = true;

	while (is_running) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				is_running = false;
			}
		}

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
		SDL_RenderClear(renderer);
		SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, SDL_ALPHA_OPAQUE);
		static int frame_num = 0;

		animated_sprite.PlayFrame(0, 0, 137, 114, frame_num);
		animated_sprite.Render(renderer);
		frame_num++;
		if (frame_num > 6) {
			frame_num = 0;
		}


		SDL_RenderPresent(renderer);
		SDL_Delay(100);
	}

	SDL_DestroyWindow(main_window);
	SDL_Quit();

	return 0;
}

