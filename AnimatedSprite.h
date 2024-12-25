#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace std;

class AnimatedSprite {
public:
	AnimatedSprite(SDL_Renderer*& renderer, string file_path);
	
	~AnimatedSprite();

	void Draw(int x, int y, int w, int h);

	void PlayFrame(int x, int y, int w, int h, int frame);

	void Update();

	void Render(SDL_Renderer*& renderer);

private:
	SDL_Rect m_src;
	SDL_Rect m_dst;
	SDL_Texture* m_texture = nullptr;

};