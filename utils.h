#pragma once

#include "structures.h"

#define M 5
#define N 3
const int SCREEN_WIDTH = 1080;
const int SCREEN_HEIGHT = 1080;
const float Xcentr = SCREEN_HEIGHT / 2 ;
const float Ycentr = SCREEN_WIDTH / 2 - 300;



const float deltaRad = M_PI/36;

float rotateMatrix[3][3]={  {cos(deltaRad),sin(deltaRad),0},
    {-1*sin(deltaRad),cos(deltaRad),0},
    {0,0,1}};

float moveToStartMatrix[N][N]={ {1.,0.,0.},
    {0.,1.,0.},
    {-Xcentr,-Ycentr,1.}};
float moveToCenterMatrix[N][N]={ {1.,0.,0.},
    {0.,1.,0.},
    {Xcentr,Ycentr,1.}};





void drawDashedLine(int x1, int y1, int x2, int y2, SDL_Renderer *renderer)//Interpritation of resenham's line algo for dashed line
{
    float dx,dy,len,x,y;
    int i;
    dx = abs(x2-x1);
    dy = abs(y2-y1);
    if(dx>=dy)
        len=dx;
    else
        len=dy;
    dx = (x2-x1)/len;
    dy = (y2-y1)/len;
    x = x1 + 0.5;
    y = y1 + 0.5;
    SDL_RenderDrawPoint(renderer, x1, y1);
    SDL_RenderDrawPoint(renderer, x2, y2);
    for(i=0;i<=len;i++){
        if(i%9>4)
            SDL_RenderDrawPoint(renderer, x, y);
        x += dx;
        y += dy;
        
    }
}

void drawFace(Face face, SDL_Renderer *renderer){
    
    for(int i=0;i< 3;i ++){
       SDL_RenderDrawLine(renderer, face.coordinates[i][0], face.coordinates[i][1], face.coordinates[i+1][0], face.coordinates[i+1][1]);
    }
    SDL_RenderDrawLine(renderer,face.coordinates[3][0], face.coordinates[3][1], face.coordinates[0][0], face.coordinates[0][1]);
}

void drawCube(Cube *cube, SDL_Renderer *renderer){
    
    for(int i=0;i<6;i++){
        drawFace(cube->faces[i],renderer);
    }
    
    
}





