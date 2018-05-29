//  Created by Artsiom on 20.05.18.
//  Copyright © 2018 Artsiom. All rights reserved.
//
#pragma once

#ifndef structures_h
#define structures_h

#include "ZBuffer.hpp"
#include "utils.h"



#endif /* structures_h */

struct Point{
    
    float x,y,z;
};

struct Face{
    Face(){
        coordinates= (float**)calloc(4,sizeof(float*));
        for(int i=0; i< 4 ;i++){
            coordinates[i]= (float*)calloc(4,sizeof(float));
        }
    }
    
    ~Face(){
       
    }
    
    float **coordinates;

};

struct Cube{
    public:
    
        float a;
        Face *faces;
    
    
    
        Cube(float da,float xCenter, float yCenter, float zCenter, ZBuffer * zBuffer, SDL_Renderer *renderer){
            this->a = da*sqrt(2);
            this->faces = new Face[6];
            this->zBuffer = zBuffer ;
            
            
            //top face
            faces[0].coordinates[0][0] = xCenter-da; // x-coordinate
            faces[0].coordinates[0][1] = yCenter-2*da; // y- coordinate
            faces[0].coordinates[0][2] = zCenter+da; //z-coordinate
            
            faces[0].coordinates[1][0] = xCenter;
            faces[0].coordinates[1][1] = yCenter-da;
            faces[0].coordinates[1][2] = zCenter;
            
            faces[0].coordinates[2][0] = xCenter+da;
            faces[0].coordinates[2][1] = yCenter-2*da;
            faces[0].coordinates[2][2] = zCenter+da;
            
            faces[0].coordinates[3][0] = xCenter;
            faces[0].coordinates[3][1] = yCenter-3*da;
            faces[0].coordinates[3][2] = zCenter+2*da;
            
    
        
            //calculating coordinates of other faces
            
            faces[1].coordinates[0][0] = xCenter-da;;
            faces[1].coordinates[0][1] = yCenter-da;
            faces[1].coordinates[0][2] = zCenter+da;
            
            faces[1].coordinates[1][0] = xCenter;
            faces[1].coordinates[1][1] = yCenter;
            faces[1].coordinates[1][2] = zCenter;
        
            faces[1].coordinates[2][0] = xCenter;
            faces[1].coordinates[2][1] = yCenter - da;
            faces[1].coordinates[2][2] = zCenter;
            
            faces[1].coordinates[3][0] = xCenter-da;
            faces[1].coordinates[3][1] = yCenter-2*da;
            faces[1].coordinates[3][2] = zCenter+da;
            
        
            
            
            faces[2].coordinates[0][0] = xCenter;
            faces[2].coordinates[0][1] = yCenter;
            faces[2].coordinates[0][2] = zCenter;
            
            faces[2].coordinates[1][0] = xCenter+da;
            faces[2].coordinates[1][1] = yCenter-da;
            faces[2].coordinates[1][2] = zCenter+da;
            
            faces[2].coordinates[2][0] = xCenter+da;
            faces[2].coordinates[2][1] = yCenter-2*da;
            faces[2].coordinates[2][2] = zCenter+da;
            
            faces[2].coordinates[3][0] = xCenter;
            faces[2].coordinates[3][1] = yCenter-da;
            faces[2].coordinates[3][2] = zCenter;
            
            
            
            faces[3].coordinates[0][0] = xCenter;
            faces[3].coordinates[0][1] = yCenter-2*da;
            faces[3].coordinates[0][2] = zCenter+2*da;
            
            faces[3].coordinates[1][0] = xCenter+da;
            faces[3].coordinates[1][1] = yCenter-da;
            faces[3].coordinates[1][2] = zCenter+da;
            
            faces[3].coordinates[2][0] = xCenter+da;
            faces[3].coordinates[2][1] = yCenter-2*da;
            faces[3].coordinates[2][2] = zCenter+da;
            
            faces[3].coordinates[3][0] = xCenter;
            faces[3].coordinates[3][1] = yCenter-3*da;
            faces[3].coordinates[3][2] = zCenter+2*da;
            
            

            
            faces[4].coordinates[0][0] = xCenter-da;
            faces[4].coordinates[0][1] = yCenter-da;
            faces[4].coordinates[0][2] = zCenter+da;
    
            faces[4].coordinates[1][0] = xCenter;
            faces[4].coordinates[1][1] = yCenter-2*da;
            faces[4].coordinates[1][2] = zCenter+2*da;
            
            faces[4].coordinates[2][0] = xCenter;
            faces[4].coordinates[2][1] = yCenter-3*da;
            faces[4].coordinates[2][2] = zCenter+2*da;
            
            faces[4].coordinates[3][0] = xCenter-da;
            faces[4].coordinates[3][1] = yCenter-2*da;
            faces[4].coordinates[3][2] = zCenter+da;
            
            
            
            
            faces[5].coordinates[0][0] = xCenter-da;
            faces[5].coordinates[0][1] = yCenter-da;
            faces[5].coordinates[0][2] = zCenter+da;

            faces[5].coordinates[1][0] = xCenter;
            faces[5].coordinates[1][1] = yCenter;
            faces[5].coordinates[1][2] = zCenter;

            faces[5].coordinates[2][0] = xCenter+da;
            faces[5].coordinates[2][1] = yCenter-da;
            faces[5].coordinates[2][2] = zCenter+da;

            faces[5].coordinates[3][0] = xCenter;
            faces[5].coordinates[3][1] = yCenter-2*da;
            faces[5].coordinates[3][2] = zCenter+2*da;
            
            
            for(int i=0;i<5;i++){//initializing additional dimension coordinates as ones for 3d operations
                for(int j=0;j<4;j++){
                    faces[i].coordinates[j][3] = 1;
                }
            }
        }


    
    void rotateCube(float rotateMatrix[4][4],float moveToStartMatrix[4][4],float moveToCenterMatrix[4][4] ){
        for(int i=0;i<4;i++){
            printf("\nP:%d",i);
            printf("  x:%lf y:%lf z:%lf  , %lf\n",faces[5].coordinates[i][0],faces[5].coordinates[i][1],faces[5].coordinates[i][2],faces[5].coordinates[i][3]);
        }
        
        for(int i=0;i<6;i++){
            this->faces[i].coordinates = recalculatFaces(faces[i] , moveToStartMatrix);
        }
        for(int i=0;i<6;i++){
            this->faces[i].coordinates = recalculatFaces(faces[i],rotateMatrix);
        }
        for(int i=0;i<6;i++){
            this->faces[i].coordinates = recalculatFaces(faces[i],moveToCenterMatrix);
        }
        
        
        for(int i=0;i<4;i++){
            printf("\n\nP:%d",i);
            printf(" x:%lf y:%lf z:%lf  , %lf\n",faces[5].coordinates[i][0],faces[5].coordinates[i][1],faces[5].coordinates[i][2],faces[5].coordinates[i][3]);
        }
    }
    
    
    
    void drawCube( SDL_Renderer *renderer){
        
        
        zBuffer->clearBuffer();
        
        loadInDepthMap3( zBuffer, faces[0]);
        loadInDepthMap3( zBuffer, faces[1]);
        loadInDepthMap3( zBuffer, faces[2]);
        loadInDepthMap3( zBuffer, faces[3]);
        loadInDepthMap3( zBuffer, faces[4]);
       // loadInDepthMap3( zBuffer, faces[5]);
    
        for(int i=0;i<1080;i++){
            for(int j=0;j<1080;j++){
                if(zBuffer->z_depth_map[i][j]!=100000){
                   // printf("I:%d J:%d z: %d\n",i,j,zBuffer->z_depth_map[i][j]);
                    SDL_SetRenderDrawColor(renderer, 32, 43, 44, 255);
                    SDL_RenderDrawPoint(renderer, j, i);
                }


            }
        }
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

        for(int i=0;i<5;i++){
            drawFace(this->faces[i],renderer);
        }
        
         //   drawFace(this->faces[5],renderer);
        
    }
    
    private:
    
        ZBuffer * zBuffer;
    
        float ** recalculatFaces(Face face,float B[4][4] ){//multiply matrixies
            
            float ** newCoordinates = (float**) calloc(4,sizeof(float*));
            for (int i = 0; i< 4; i++) {
                newCoordinates[i] = (float*) calloc(4,sizeof(float));
            }
            
            for(int i = 0; i < 4; i++){
                for(int j = 0; j < 4; j++){
                    for(int k = 0; k < 4; k++){
                       // printf("%d",i);
                        newCoordinates[i][j] += face.coordinates[i][k] * B[k][j];
                    }
                }
            }
            
            return newCoordinates;
            
        
        }
    
        int * findFaceRectFiled(Face face){
            int * rectPositions = (int*) calloc(4, sizeof(int));
            rectPositions[0]=10000;//xmin
            rectPositions[1]=10000;//ymin
            rectPositions[2]=0;//xmax
            rectPositions[3]=0;//ymax
        
            
            
            for(int i=0;i < 4;i++){
                
                if(face.coordinates[i][0]<rectPositions[0])
                    rectPositions[0]=face.coordinates[i][0];
                if(face.coordinates[i][1]<rectPositions[1])
                    rectPositions[1]=face.coordinates[i][1];
                if(face.coordinates[i][0]>rectPositions[2])
                    rectPositions[2]=face.coordinates[i][0];
                if(face.coordinates[i][1]>rectPositions[3])
                    rectPositions[3]=face.coordinates[i][1];
                
            }
            
          
           
            return rectPositions;
            
        }
    

        bool isInFace(Face face,int x,int y){
            int sign, curSign;
            int x1= face.coordinates[1][0]-face.coordinates[0][0];
            int x2= x-face.coordinates[1][0];
            int y1= face.coordinates[1][1]-face.coordinates[0][1];
            int y2= y-face.coordinates[1][1];
            
            sign = x1*y2 - y1*x2 >= 0 ? 1 : -1;
            
            for(int i=1;i<3;i++){
                
                x1= face.coordinates[i+1][0]-face.coordinates[i][0];
                x2= x-face.coordinates[i+1][0];
                y1= face.coordinates[i+1][1]-face.coordinates[i][1];
                y2= y-face.coordinates[i+1][1];
                curSign = x1*y2 - y1*x2 >= 0 ? 1 : -1;
                if(curSign!= sign)
                    return false;
            }
            
            x1= face.coordinates[0][0]-face.coordinates[3][0];
            x2= x-face.coordinates[0][0];
            y1= face.coordinates[0][1]-face.coordinates[3][1];
            y2= y-face.coordinates[0][1];
            curSign = x1*y2 - y1*x2 >= 0 ? 1 : -1;
            if(curSign!= sign)
                return false;
        
            return true;
        }
                
        void loadInDepthMap3(ZBuffer *zBuffer, Face face){
            
            int zMax=-10000;
            for(int i=0;i<4;i++){
                if(zMax<=face.coordinates[i][2])
                    zMax=face.coordinates[i][2];
            }
    
            int * borderCoordinates = findFaceRectFiled(face);
            
            for(int i= borderCoordinates[1]; i<=borderCoordinates[3];i++){
                for(int j = borderCoordinates[0]; j<= borderCoordinates[2];j++){
                    if(0<=j && j<=1080 && 0<=i && i<=1080)
                        if(isInFace(face, j,i) && zBuffer->z_depth_map[i][j]>=zMax){
                            zBuffer->z_depth_map[i][j]=zMax;
                        }
                }
                zMax--;
            }
        }
    
    
        void drawLine(SDL_Renderer *renderer, ZBuffer *zBuffer, int x1, int y1, int x2, int y2 , int z1, int z2)//Bresenham's line algo with modification for zBuffer
        {
            int bufZ = z2;
            
            int dx = (x2 - x1 >= 0 ? 1 : -1);
            int dy = (y2 - y1 >= 0 ? 1 : -1);
            int dz = z1==z2 ? 0 :dy;
            
            int lengthX = abs(x2 - x1);
            int lengthY = abs(y2 - y1);
            
            int length = lengthX>lengthY ? lengthX : lengthY;
            
            if (length == 0)
            {
                if(y1>=0 && y1<1080 && x1>=0&&x1<1080)
                    if(zBuffer->z_depth_map[y1][x1] > bufZ)
                    SDL_RenderDrawPoint(renderer, x1, y1);
            }
            
            if (lengthY <= lengthX)
            {
                // Начальные значения
                int x = x1;
                int y = y1;
                int d = -lengthX;
                
                // Основной цикл
                length++;
                while(length--)
                {
                    if(y>=0&&y<1080 && x>=0&&x<1080)
                        if(zBuffer->z_depth_map[y][x] > bufZ)
                            SDL_RenderDrawPoint(renderer, x, y);
                    x += dx;
                    d += 2 * lengthY;
                    if (d > 0) {
                        d -= 2 * lengthX;
                        y += dy;
                        bufZ+=dz;
                    }
                }
            }
            else
            {
                // Начальные значения
                int x = x1;
                int y = y1;
                int d = - lengthY;
                
                // Основной цикл
                length++;
                while(length--)
                {
                    if(y>=0&&y<1080 && x>=0&&x<1080)
                        if(zBuffer->z_depth_map[y][x] > bufZ)
                            SDL_RenderDrawPoint(renderer, x, y);
                    y += dy;
                    d += 2 * lengthX;
                    bufZ+=dz;
                    if (d > 0) {
                        d -= 2 * lengthY;
                        x += dx;
                    }
                }
            }
        }
    
    
        void drawFace(Face face, SDL_Renderer *renderer){
            for(int k=-1;k<1;k++){
                for(int j=-1;j<1;j++){
                    
                    for(int i=0;i< 3;i ++){
                        drawLine(renderer,zBuffer, face.coordinates[i][0]+j, face.coordinates[i][1]+k, face.coordinates[i+1][0]+j, face.coordinates[i+1][1]+k, face.coordinates[i][2],face.coordinates[i+1][2]);
                    }
                    drawLine(renderer,zBuffer, face.coordinates[3][0]+j, face.coordinates[3][1]+k, face.coordinates[0][0]+j, face.coordinates[0][1]+k,face.coordinates[3][2],face.coordinates[0][2]);
                    
                }
                
            }
//            for(int i=0;i< 3;i ++){
//                drawLine(renderer,zBuffer, face.coordinates[i][0], face.coordinates[i][1], face.coordinates[i+1][0], face.coordinates[i+1][1], face.coordinates[i][2],face.coordinates[i+1][2]);
//            }
//            drawLine(renderer,zBuffer, face.coordinates[3][0], face.coordinates[3][1], face.coordinates[0][0], face.coordinates[0][1],face.coordinates[3][2],face.coordinates[0][2]);
            
        }
    
    
};



