#include <SDL.h>
#include <math.h>
#include <stdio.h>
#include <sstream>
#include "utils.h"

#include <vector>

#define a 80


int getMaxZ(Cube *cube){
    
    int zMax=-10000;
    for(int j=0;j<6;j++){
        for(int i=0;i<4;i++){
            if(zMax<=cube->faces[j].coordinates[i][2])
                zMax=cube->faces[j].coordinates[i][2];
        }
    }
    return zMax;
}


void orderCubes(Cube ** cubes, int n){
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1 ; j++)
        {
            int zMaxJ1 = getMaxZ(cubes[j+1]);
            int zMaxj = getMaxZ(cubes[j]);
            if (zMaxJ1 > zMaxj)
            {
                Cube * temp = cubes[j];
                cubes[j] = cubes[j + 1];
                cubes[j + 1] = temp;
            }
        }
    }
}





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
    
    Cube *cube1 = new Cube(a,Xcentr, Ycentr+100, Zcentr+160, zBuffer, renderer , 40);
    Cube *cube2 = new Cube(a,Xcentr-a, Ycentr+100+a*2,-a+160,zBuffer,renderer,100);
    Cube *cube3 = new Cube(a,Xcentr+a, Ycentr+100+a*2,-a+160,zBuffer,renderer,80);

    Cube ** cubes =(Cube**) malloc(sizeof(Cube*)*3);
    cubes[0]= cube1;
    cubes[1]=cube2;
    cubes[2]=cube3;
    
    int n =3;
    orderCubes(cubes, n);
    
    cubes[0]->drawCube(renderer);
    cubes[1]->drawCube(renderer);
    cubes[2]->drawCube(renderer);
    
    
    
    SDL_RenderPresent(renderer);
  

    bool done = false;
    while (!done)
    {
        while(SDL_PollEvent(&event)) {
            switch(event.type)
            {
                case SDL_KEYDOWN:
                    
                    
                    printf("%d\n",event.key.keysym.sym);
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
                    SDL_RenderClear(renderer);
                    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                    
                    switch (event.key.keysym.sym) {
                        case SDLK_q:
                            
                            cube1->rotateCube(Y_RotateMatrixR, moveToStartMatrix,moveToCenterMatrix);
                            cube2->rotateCube(Y_RotateMatrixR, moveToStartMatrix,moveToCenterMatrix);
                            cube3->rotateCube(Y_RotateMatrixR, moveToStartMatrix,moveToCenterMatrix);
                            
                            break;
                            
                            
                        case SDLK_z:
                            cube1->rotateCube(Y_RotateMatrixL, moveToStartMatrix,moveToCenterMatrix);
                            cube2->rotateCube(Y_RotateMatrixL, moveToStartMatrix,moveToCenterMatrix);
                            cube3->rotateCube(Y_RotateMatrixL, moveToStartMatrix,moveToCenterMatrix);
                            break;
                            
                        case SDLK_a:
                            
                            cube1->rotateCube(Z_RotateMatrixR, moveToStartMatrix,moveToCenterMatrix);
                            cube2->rotateCube(Z_RotateMatrixR, moveToStartMatrix,moveToCenterMatrix);
                            cube3->rotateCube(Z_RotateMatrixR, moveToStartMatrix,moveToCenterMatrix);
                            
                            break;
                            
                            
                        case SDLK_d:
                            cube1->rotateCube(Z_RotateMatrixL, moveToStartMatrix,moveToCenterMatrix);
                            cube2->rotateCube(Z_RotateMatrixL, moveToStartMatrix,moveToCenterMatrix);
                            cube3->rotateCube(Z_RotateMatrixL, moveToStartMatrix,moveToCenterMatrix);
                            break;
                            
                        case SDLK_w:
                            
                            cube1->rotateCube(X_RotateMatrixR, moveToStartMatrix,moveToCenterMatrix);
                            cube2->rotateCube(X_RotateMatrixR, moveToStartMatrix,moveToCenterMatrix);
                            cube3->rotateCube(X_RotateMatrixR, moveToStartMatrix,moveToCenterMatrix);
                            
                            break;
                            
                            
                        case SDLK_s:
                            
                            cube1->rotateCube(X_RotateMatrixL, moveToStartMatrix,moveToCenterMatrix);
                            cube2->rotateCube(X_RotateMatrixL, moveToStartMatrix,moveToCenterMatrix);
                            cube3->rotateCube(X_RotateMatrixL, moveToStartMatrix,moveToCenterMatrix);
                            break;
                            
                            
                        default:
                            break;
                    }
                
                    
                   

                    orderCubes(cubes, n);
                    
                    cubes[0]->drawCube(renderer);
                    cubes[1]->drawCube(renderer);
                    cubes[2]->drawCube(renderer);
                    
                    
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
