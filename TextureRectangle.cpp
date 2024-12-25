#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "TextureRectangle.h"
#include "ResourceManager.h"
using namespace std;

TextureRectangle::TextureRectangle(SDL_Renderer*& renderer, string file_path) {
	SDL_Surface* retrieve_surface = ResourceManager::GetInstance().GetSurface("C:\\Users\\Dante Clark\\OneDrive\\Documents\\file.png");
	m_texture = SDL_CreateTextureFromSurface(renderer, retrieve_surface);

	if (retrieve_surface == nullptr) {
		cout << "image failed to load onto surface.\n" << IMG_GetError();
	}

	m_texture = SDL_CreateTextureFromSurface(renderer, retrieve_surface);

	if (m_texture == nullptr) {
		cout << "texture failed to load from surface.\n" << SDL_GetError();
	}
}
TextureRectangle::~TextureRectangle() {
	SDL_DestroyTexture(m_texture);
}

void TextureRectangle::SetRectangleProperties(int x, int y, int w, int h) {
	m_rect = { x, y, w, h };
}

void TextureRectangle::Update() {}

void TextureRectangle::Render(SDL_Renderer*& renderer) {
	SDL_RenderCopy(renderer, m_texture, nullptr, &m_rect);
}