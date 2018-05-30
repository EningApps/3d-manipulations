#pragma once

#include "structures.h"

#define M 5
#define N 3
const int SCREEN_WIDTH = 1080;
const int SCREEN_HEIGHT = 1080;
const float Xcentr = SCREEN_HEIGHT / 2 ;
const float Ycentr = SCREEN_WIDTH / 2 - 300;
const float Zcentr = 0;



const float deltaRad = M_PI/36;

float rotateMatrix[3][3]={  {cos(deltaRad),sin(deltaRad),0},
    {-1*sin(deltaRad),cos(deltaRad),0},
    {0,0,1}};


float Y_RotateMatrixR[4][4]=
    {{cos(deltaRad),0,sin(deltaRad),0},
    {0,1,0,0},
    {-sin(deltaRad),0,cos(deltaRad),0},
    {0,0,0,1}};



float Y_RotateMatrixL[4][4]=
{{cos(deltaRad),0,-sin(deltaRad),0},
    {0,1,0,0},
    {sin(deltaRad),0,cos(deltaRad),0},
    {0,0,0,1}};


float X_RotateMatrixR[4][4]=
    {{1,0,0,0},
    {0,cos(deltaRad),-sin(deltaRad),0},
    {0,sin(deltaRad),cos(deltaRad),0},
    {0,0,0,1}};

float X_RotateMatrixL[4][4]=
{{1,0,0,0},
    {0,cos(deltaRad),sin(deltaRad),0},
    {0,-sin(deltaRad),cos(deltaRad),0},
    {0,0,0,1}};

float Z_RotateMatrixR[4][4]=
{{cos(deltaRad),-sin(deltaRad),0,0},
    {sin(deltaRad),cos(deltaRad),0,0},
    {0,0,1,0},
    {0,0,0,1}};


float Z_RotateMatrixL[4][4]=
{{cos(deltaRad),sin(deltaRad),0,0},
    {-sin(deltaRad),cos(deltaRad),0,0},
    {0,0,1,0},
    {0,0,0,1}};


float moveMatrix[4][4]=
    {{1.,0.,0., 20.0},
    {0.,1.,0., 20.0},
    {0.,0.,1.,20.},
    {0.,0.,0.,1}};

float rotateMatrix3D[4][4]={  {cos(deltaRad),sin(deltaRad),0},
    {-1*sin(deltaRad),cos(deltaRad),0},
    {0,0,1}};

float moveToStartMatrix[4][4]=
    {{1.,0.,0.,0.},
    {0.,1.,0.,0.},
    {0.,0.,1.,0.},
    {-Xcentr,-Ycentr-100,-Zcentr,1}};

float moveToCenterMatrix[4][4]=
{{1.,0.,0.,0.},
    {0.,1.,0.,0.},
    {0.,0.,1.,0.},
    {Xcentr,Ycentr+100,Zcentr,1}};
