#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "AnimatedSprite.h"
#include "ResourceManager.h"

using namespace std;

AnimatedSprite::AnimatedSprite(SDL_Renderer*& renderer, string file_path) {
	SDL_Surface* retrieve_surface = ResourceManager::GetInstance().GetSurface(file_path.c_str());
	m_texture = SDL_CreateTextureFromSurface(renderer, retrieve_surface);
}

AnimatedSprite::~AnimatedSprite() {
	SDL_DestroyTexture(m_texture);
}

void AnimatedSprite::Draw(int x, int y, int w, int h) {
	m_dst = { x, y, w, h };
}

void AnimatedSprite::PlayFrame(int x, int y, int w, int h, int frame) {
	m_src.x = x + w * frame;
	m_src.y = y;
	m_src.w = w;
	m_src.h = h;
}

void AnimatedSprite::Update() {}

void AnimatedSprite::Render(SDL_Renderer*& renderer) {
	SDL_RenderCopy(renderer, m_texture, &m_src, &m_dst);
}
