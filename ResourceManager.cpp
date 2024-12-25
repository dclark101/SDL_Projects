#include "ResourceManager.h";
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace std;

ResourceManager::ResourceManager() {}

ResourceManager::ResourceManager(ResourceManager const&) {}

ResourceManager ResourceManager::operator=(ResourceManager const& rhs) {
	return *this;
}

// Instantiate one instance of our class
ResourceManager& ResourceManager::GetInstance() {
	static ResourceManager* s_instance = new ResourceManager;
	return *s_instance;
}

SDL_Surface* ResourceManager::GetSurface(string file_path) {
	auto search = m_surfaces.find(file_path);

	if (search != m_surfaces.end()) {
		return m_surfaces[file_path];
		cout << "if\n";
	}
	else {
		cout << "else\n";
		SDL_Surface* surface = IMG_Load(file_path.c_str());
		m_surfaces.insert(make_pair(file_path, surface));

		return m_surfaces[file_path];
	}

	return nullptr;
}

