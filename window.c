#include <stdio.h>
#include <SDL2/SDL.h>
#include "types.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

SDL_Window* window;
SDL_Renderer* renderer;

int initWindow() {

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL initialization failed. SDL Error: %s\n", SDL_GetError());
		return -1;
	}

	window = SDL_CreateWindow("Test",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		SCREEN_WIDTH,
		SCREEN_HEIGHT,
		SDL_WINDOW_SHOWN);

	if (window == NULL) {
		printf("Could not create window. SDL Error: %s\n", SDL_GetError());
		return -1;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	return 0;
}

void close()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	//Quit SDL subsystems
	SDL_Quit();
}
