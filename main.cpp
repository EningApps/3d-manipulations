#include <SDL.h>
#include <math.h>
#include <stdio.h>
#include <sstream>
#include "utils.h"

#include <vector>

#define a 80




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
    
    Cube * cube1 = new Cube(a,Xcentr, Ycentr+100, 0, zBuffer, renderer);
    Cube * cube2 = new Cube(a,Xcentr-a, Ycentr+100+a*2,-a,zBuffer,renderer);
    Cube * cube3 = new Cube(a,Xcentr+a, Ycentr+100+a*2,-a,zBuffer,renderer);

 
    
    cube1->drawCube(renderer);
    cube2->drawCube(renderer);
    cube3->drawCube(renderer);

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
                    
                    
                
                    cube1->rotateCube(Z_RotateMatrix, moveToStartMatrix,moveToCenterMatrix);
                    cube2->rotateCube(Z_RotateMatrix, moveToStartMatrix,moveToCenterMatrix);
                    cube3->rotateCube(Z_RotateMatrix, moveToStartMatrix,moveToCenterMatrix);
//

                    cube1->drawCube(renderer);
                    cube2->drawCube(renderer);
                    cube3->drawCube(renderer);
                
                    SDL_RenderPresent(renderer);
                    break;
                case SDL_MOUSEMOTION:
                    
                   
                    int mouseX = event.motion.x;
                    int mouseY = event.motion.y;
                    std::stringstream ss;
                    ss << "X: " << mouseX << " Y: " << mouseY;
                    SDL_SetWindowTitle(window, ss.str().c_str());
                    
                    break;
            }
        }
    }
    return 0;
}
