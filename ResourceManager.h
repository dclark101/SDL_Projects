#pragma once
#include <string>
#include <SDL2/SDL.h>
#include <unordered_map>
using namespace std;


class ResourceManager {
private:
	ResourceManager();
	ResourceManager(ResourceManager const&);
	ResourceManager operator=(ResourceManager const&);

	unordered_map<string, SDL_Surface*> m_surfaces;

public:
	static ResourceManager& GetInstance();

	SDL_Surface* GetSurface(string file_path);
};
