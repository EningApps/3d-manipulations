//
//  ZBuffer.hpp
//  aokg_laba1
//
//  Created by Artsiom on 21.05.18.
//  Copyright © 2018 Artsiom. All rights reserved.
//

#ifndef ZBuffer_hpp
#define ZBuffer_hpp

#include <stdio.h>
#include <stdlib.h>

#endif /* ZBuffer_hpp */
struct ZBuffer{
    private:
        int height , width ;
    
        void initBufMap(){
            z_depth_map = (int**)calloc(height,sizeof(int*));
            for(int i = 0; i< height; i++){
                z_depth_map[i] = (int*)calloc(width,sizeof(int));
            }
            for(int i = 0; i< height; i++){
                for(int j = 0; j< width; j++){
                    z_depth_map[i][j] = 100000;
                }
            }
        }
    
    public:
        ZBuffer(int SCREEN_WIDTH, int SCREEN_HEIGHT){
            this->height = SCREEN_HEIGHT;
            this->width = SCREEN_WIDTH;
            initBufMap();
        }
    
    
    
        int ** z_depth_map;
    
    
    
        void clearBuffer(){
            for(int i = 0; i< height; i++){
                for(int j = 0; j< width; j++){
                    z_depth_map[i][j] = 100000;
                }
            }
        }
    
    
    

    
};
