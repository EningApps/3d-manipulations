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
            coordinates[i]= (float*)calloc(3,sizeof(float));
        }
    }
    
    ~Face(){
       
    }
    
    float **coordinates;

};

struct Cube{
    public:
    
        Cube(float da,float xCenter, float yCenter, float zCenter, ZBuffer * zBuffer){
            this->a = da*sqrt(2);
            this->faces = new Face[6];
            this->zBuffer = zBuffer ;
            
            int halfTreshhold = 0;//needed to calculate depth_map
            
            //top face
            faces[0].coordinates[0][0] = xCenter-da; // x-coordinate
            faces[0].coordinates[0][1] = yCenter; // y- coordinate
            faces[0].coordinates[0][2] = 0; //z-coordinate
            
            faces[0].coordinates[1][0] = xCenter;
            faces[0].coordinates[1][1] = yCenter+da;
            faces[0].coordinates[1][2] = zCenter-da;
            
            faces[0].coordinates[2][0] = xCenter+da;
            faces[0].coordinates[2][1] = yCenter;
            faces[0].coordinates[2][2] = zCenter;
            
            faces[0].coordinates[3][0] = xCenter;
            faces[0].coordinates[3][1] = yCenter-da;
            faces[0].coordinates[3][2] = zCenter+da;
            
            
            //calculating coordinates of other faces basing on top face's coordinates
            
            faces[1].coordinates[0][0] = xCenter-da;;
            faces[1].coordinates[0][1] = yCenter+da;
            faces[1].coordinates[0][2] = zCenter;
            
            faces[1].coordinates[1][0] = xCenter;
            faces[1].coordinates[1][1] = yCenter+2*da;
            faces[1].coordinates[1][2] = zCenter-da;
        
            faces[1].coordinates[2][0] = xCenter;
            faces[1].coordinates[2][1] = yCenter + da;
            faces[1].coordinates[2][2] = zCenter-da;
            
            faces[1].coordinates[3][0] = faces[0].coordinates[0][0];
            faces[1].coordinates[3][1] = faces[0].coordinates[0][1];
            faces[1].coordinates[3][2] = zCenter;
            
            
            faces[2].coordinates[0][0] = xCenter;
            faces[2].coordinates[0][1] = faces[1].coordinates[1][1];
            faces[2].coordinates[0][2] = zCenter-da;
            
            faces[2].coordinates[1][0] = xCenter+da;
            faces[2].coordinates[1][1] = yCenter+da;
            faces[2].coordinates[1][2] = zCenter;
            
            faces[2].coordinates[2][0] = xCenter+da;
            faces[2].coordinates[2][1] = yCenter;
            faces[2].coordinates[2][2] = zCenter;
            
            faces[2].coordinates[3][0] = faces[0].coordinates[1][0];
            faces[2].coordinates[3][1] = faces[0].coordinates[1][1];
            faces[2].coordinates[3][2] = zCenter-da;
            
//            
//            
//            faces[3].coordinates[0][0] = faces[2].coordinates[1][0];
//            faces[3].coordinates[0][1] = faces[2].coordinates[1][1];
//            faces[3].coordinates[0][2] = zCenter;
//            
//            faces[3].coordinates[1][0] = xCenter;
//            faces[3].coordinates[1][1] = yCenter;
//            faces[3].coordinates[1][2] = zCenter+da;
//            
//            faces[3].coordinates[2][0] = xCenter;
//            faces[3].coordinates[2][1] = yCenter-da;
//            faces[3].coordinates[2][2] = zCenter+da;
//            
//            faces[3].coordinates[3][0] = faces[2].coordinates[2][0];
//            faces[3].coordinates[3][1] = faces[2].coordinates[2][1];
//            faces[3].coordinates[3][2] = zCenter;
//            
//            
//
//            
//            faces[4].coordinates[0][0] = xCenter;
//            faces[4].coordinates[0][1] = yCenter;
//            faces[4].coordinates[0][2] = zCenter+da;
//    
//            faces[4].coordinates[1][0] = xCenter;
//            faces[4].coordinates[1][1] = yCenter-da;
//            faces[4].coordinates[1][2] = zCenter;
//            
//            faces[4].coordinates[2][0] = xCenter-da;
//            faces[4].coordinates[2][1] = yCenter;
//            faces[4].coordinates[2][2] = zCenter;
//            
//            faces[4].coordinates[3][0] = xCenter-da;
//            faces[4].coordinates[3][1] = yCenter+da;
//            faces[4].coordinates[3][2] = zCenter+da;
//            
//            
//            
//            
//            faces[5].coordinates[0][0] = faces[1].coordinates[0][0];
//            faces[5].coordinates[0][1] = faces[1].coordinates[0][1];
//            faces[5].coordinates[0][2] = zCenter;
//
//            faces[5].coordinates[1][0] = faces[1].coordinates[1][0];
//            faces[5].coordinates[1][1] = faces[1].coordinates[1][1];
//            faces[5].coordinates[1][2] = zCenter-da;
//
//            faces[5].coordinates[2][0] = faces[2].coordinates[1][0];
//            faces[5].coordinates[2][1] = faces[2].coordinates[1][1];
//            faces[5].coordinates[2][2] = zCenter;
//
//            faces[5].coordinates[3][0] = xCenter;
//            faces[5].coordinates[3][1] = yCenter;
//            faces[5].coordinates[3][2] = zCenter+da;
//            
            
            
//            for(int j = faces[0].coordinates[1][1]+1, i = xCenter , z = -da; j < faces[0].coordinates[3][1]-1; j++){
//                if(zBuffer->z_depth_map[i+1][j]>z)
//                    zBuffer->z_depth_map[i+1][j] = z;
//                if(zBuffer->z_depth_map[i-1][j]>z)
//                    zBuffer->z_depth_map[i-1][j] = z;
//                if(halfTreshhold<(faces[0].coordinates[1][1] - faces[0].coordinates[3][1])/2)
//                    i++;
//                else
//                    i--;
//                halfTreshhold++;
//                z++;
//            }
//
//            for(int i =0; i < 1080; i++){
//                for(int j=0; j<1080;j++){
//                    if(zBuffer->z_depth_map[i][j]!=10000)
//                        printf("%d ",zBuffer->z_depth_map[i][j]);
//                }
//                printf("\n");
//            }
//
//            halfTreshhold = 0;
//            for(int j = faces[5].coordinates[1][1]+1, i = xCenter , z = -da; j < faces[5].coordinates[3][1]-1; j++){
//                if(zBuffer->z_depth_map[i+1][j]>z)
//                    zBuffer->z_depth_map[i+1][j] = z;
//                if(zBuffer->z_depth_map[i-1][j]>z)
//                    zBuffer->z_depth_map[i-1][j] = z;
//                if(halfTreshhold<(faces[5].coordinates[1][1] - faces[5].coordinates[3][1])/2)
//                    i++;
//                else
//                    i--;
//                halfTreshhold++;
//                z++;
//            }
//
        }
    
    

        float a;
        Face *faces;
    
    
    void rotateCube(float rotateMatrix[3][3]){
        for(int i=0;i<6;i++){
            this->faces[i].coordinates = recalculatFaces(faces[i],rotateMatrix);
        }
    }
    
    private:
    
        ZBuffer * zBuffer;
    
        float ** recalculatFaces(Face face,float B[3][3] ){
            
            float ** newCoordinates = (float**) calloc(4,sizeof(float*));
            for (int i = 0; i< 4; i++) {
                newCoordinates[i] = (float*) calloc(4,sizeof(float));
            }
            
            for(int i = 0; i < 4; i++){
                for(int j = 0; j < 3; j++){
                    for(int k = 0; k < 3; k++){
                        printf("%d",i);
                        //float x = coordinates[i][k];
                        newCoordinates[i][j] += face.coordinates[i][k] * B[k][j];
                    }
                }
            }
            
            return newCoordinates;
            
        }
    
    
};



