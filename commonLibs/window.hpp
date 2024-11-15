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
				SDL_WINDOWPOS_CENTERED,
				SDL_WINDOWPOS_CENTERED,
				wCanvas,
				hCanvas,
				0);
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
			texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, wCanvas, hCanvas);
	    	SDL_SetWindowResizable(window, SDL_FALSE);
			std::cout << "Renderer created\n";
		}
	}
	void renderScene(uint32_t* pixels){
		bool isRunning = true;
		SDL_Event event;
		while (isRunning){
			while(SDL_PollEvent(&event)){
				if (event.type == SDL_QUIT){
					isRunning = false;
					cleanSDLBuffer(); 
				}
			}/*
			for (int l = 0; l < this->hCanvas;l++){
				for (int c = 0; c < this->wCanvas;c++){
					SDL_SetRenderDrawColor(	this->renderer,
											colorMatrix[l][c].x*255.0f,
											colorMatrix[l][c].y*255.0f,
											colorMatrix[l][c].z*255.0f,
											255.0f);
					SDL_RenderDrawPoint(renderer,l,c);
				}
			}*/
			SDL_UpdateTexture(texture,NULL,pixels,wCanvas*sizeof(uint32_t));
			SDL_RenderCopy(renderer, texture, NULL, NULL);
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
		if (SDL_Init(SDL_INIT_VIDEO) <0) {
			std::cout << "Error SDL Initialization: " << SDL_GetError();
			return 0;
		}
		return 1;
	}
	void initializeRenderer() {
		this->renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

	}
	SDL_Texture* texture;
	SDL_Window* window;
	SDL_Renderer* renderer;
};
