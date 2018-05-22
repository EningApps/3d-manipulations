#include <SDL.h>
#include <math.h>
#include <stdio.h>
#include <sstream>
#include "utils.h"

#include <vector>

#define a 100




int main(int argc, char *args[])
{
    
    
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event event;
    
    SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &window, &renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    
    ZBuffer * zBuffer = new ZBuffer(SCREEN_WIDTH,SCREEN_HEIGHT);
    
    Cube * cube1 = new Cube(a,Xcentr, Ycentr, 0, zBuffer);
    Cube * cube2 = new Cube(a,Xcentr-a, Ycentr+a*2,-a,zBuffer);
    Cube * cube3 = new Cube(a,Xcentr+a, Ycentr+a*2,-a,zBuffer);

    //rotateCube(cube1);
    //rotateCube(cube2);
    //rotateCube(cube3);
    
    drawCube(cube1, renderer);
    drawCube(cube2, renderer);
    drawCube(cube3, renderer);

    SDL_RenderPresent(renderer);
  

    bool done = false;
    while (!done)
    {
        while(SDL_PollEvent(&event)) {
            switch(event.type)
            {
                case SDL_KEYDOWN:
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
                    SDL_RenderClear(renderer);
                    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                    
                    cube1->rotateCube(rotateMatrix);
                    cube2->rotateCube(rotateMatrix);
                    cube3->rotateCube(rotateMatrix);
                    
                    drawCube(cube1, renderer);
                    drawCube(cube2, renderer);
                    drawCube(cube3, renderer);
                
                    SDL_RenderPresent(renderer);
                    break;
            }
        }
    }
    return 0;
}
