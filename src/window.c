#include <stdio.h>
#include <SDL2/SDL.h>

#include "types.h"
#include "cpu.h"
#include "window.h"
#include "memory.h"
#include "graphics.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define MAX_CYCLES 66905

SDL_Window* window;
SDL_Renderer* renderer;
int updateCycles = 0;

int main(int argc, char** argv) {
	initCpu();
	initMemory(argv);

	while(updateCycles < MAX_CYCLES) {
		int cycles = cpuStep();
		updateCycles += cycles;
		graphicsStep(cycles);
	}

	return 0;
}

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
	if (renderer == NULL) {
		printf("Could not create window. SDL Error: %s\n", SDL_GetError());
		return -1;
	}

	return 0;
}

void destroy()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	//Quit SDL subsystems
	SDL_Quit();
}
