//
// Created by Mathias Berntsen on 18/02/2019.
//

#ifndef C_ARBEIDSKRAV_IMAGE_H
#define C_ARBEIDSKRAV_IMAGE_H

#include <SDL.h>
#include <string>
#include "Utils.h"

class Image {
public:
    SDL_Surface* surface;
    SDL_Texture* texture;
    SDL_Rect position;

    Image(std::string filename);
    ~Image();

    float x, y;
private:
    bool mCanRender = false;
};


#endif //C_ARBEIDSKRAV_IMAGE_H
