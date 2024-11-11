#include <iostream>
#include <SDL2/SDL.h>
#include "raycasting.hpp"

class WindowSDL {
	public:
	int wCanvas,hCanvas;
	WindowSDL(int wCanvas, int hCanvas) : wCanvas(wCanvas),
										  hCanvas(hCanvas)
		{
		initializeSDL();
		this->window = SDL_CreateWindow(
				"CG WORK",
				SDL_WINDOWPOS_UNDEFINED,
				SDL_WINDOWPOS_UNDEFINED,
				wCanvas,
				hCanvas,
				SDL_WINDOW_SHOWN);
		if (!window){
			SDL_Log("Window Creation failed.\nSDL_ERROR: %s", SDL_GetError());
			SDL_Quit();
			return;
		}
		else{
			std::cout << "Window created\n";
			initializeRenderer();
			if (!renderer){
				SDL_Log("Renderer Creation failed.\nSDL_ERROR: %s", SDL_GetError());
				SDL_Quit();
			}
			std::cout << "Renderer created\n";		}
	}
	void renderScene(Vec4** colorMatrix){
		bool isRunning = true;
		SDL_Event event;
		while (isRunning){
			while(SDL_PollEvent(&event)){
				if (event.type == SDL_QUIT){
					isRunning = false;
					cleanSDLBuffer();
				}
			}
			for (int l = 0; l < this->hCanvas;l++){
				for (int c = 0; c < this->wCanvas;c++){
					SDL_SetRenderDrawColor(this->renderer,colorMatrix[l][c].x,colorMatrix[l][c].y,colorMatrix[l][c].z,colorMatrix[l][c].a);
					SDL_RenderDrawPoint(renderer,l,c);
				}
			}
			SDL_RenderPresent(renderer);
		}
	}
	void cleanSDLBuffer(){
	 	SDL_DestroyRenderer(renderer);
   		SDL_DestroyWindow(window);
    	SDL_Quit();
	}
	
	
	private:
	int initializeSDL (){
		if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_EVENTS) <0) {
			std::cout << "Error SDL Initialization: " << SDL_GetError();
			return 0;
		}
		return 1;
	}
	void initializeRenderer() {
		this->renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

	}
	SDL_Window* window;
	SDL_Renderer* renderer;
};
