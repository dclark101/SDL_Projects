#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace std;

class TextureRectangle {
public:
	// Constructor
	TextureRectangle(SDL_Renderer*& renderer, string file_path);
	// Destructor
	~TextureRectangle();
	// Setting rectangle properties
	void SetRectangleProperties(int x, int y, int w, int h);
	// Update every frame
	void Update();
	// rendering TextureRectangle
	void Render(SDL_Renderer*& renderer);

private:
	SDL_Rect m_rect;
	SDL_Texture* m_texture = nullptr;
};