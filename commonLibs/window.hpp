#include <iostream>
#include <SDL2/SDL.h>
#include "vector.hpp"

class WindowSDL {
	public:	
	WindowSDL(int width, int height){
		initializeSDL();
		this->window = SDL_CreateWindow(
				"CG WORK",
				SDL_WINDOWPOS_UNDEFINED,
				SDL_WINDOWPOS_UNDEFINED,
				width,
				height,
				SDL_WINDOW_SHOWN);
		if (!window){
			SDL_Log("Window Creation failed.\nSDL_ERROR: %s", SDL_GetError());
			SDL_Quit();
			return;
		}
		else{
			initializeRenderer();
			if (!renderer){
				SDL_Log("Renderer Creation failed.\nSDL_ERROR: %s", SDL_GetError());
				SDL_Quit();
			}
		}
	}
	void renderScene(Vec4** colorMatrix,int height, int width){
		bool isRunning = true;
		SDL_Event event;
		while (isRunning){
			while(SDL_PollEvent(&event)){
				if (event.type == SDL_QUIT){
					isRunning = false;
					cleanSDLBuffer();
				}
			}
			for (int lines = 0; lines < height;lines++){
				for (int collumns = 0; collumns < width;collumns++){
					SDL_SetRenderDrawColor(this->renderer,colorMatrix[l][c].x,colorMatrix[l][c].y,colorMatrix[l][c].z,colorMatrix[l][c].a);
					SDL_RenderDrawPoint(renderer,lines,collumns);
				}
			}
		}
	}
	void cleanSDLBuffer(){
	 	SDL_DestroyRenderer(renderer);
   		SDL_DestroyWindow(window);
    	SDL_Quit();
    	delete(window);
    	delete(renderer);
	}
	private:
	
	~WindowSDL(){}
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
