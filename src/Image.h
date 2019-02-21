//
// Created by Mathias Berntsen on 18/02/2019.
//

#ifndef C_ARBEIDSKRAV_IMAGE_H
#define C_ARBEIDSKRAV_IMAGE_H

#include <SDL.h>
#include <string>
#include "Utils.h"

class Image {
    SDL_Renderer* renderer;
    SDL_Rect rect;

    bool mCanRender = false;
    float _x, _y, _w, _h;
public:
    SDL_Surface* surface;
    SDL_Texture* texture;

    const float &x;
    const float &y;
    const float &w;
    const float &h;

    Image(std::string filename, int x, int y, int w, int h, SDL_Renderer* renderer);
    ~Image();

    bool Draw();

    std::tuple<float, float> getPosition();
    std::tuple<float, float> getSize();
    void setPosition(float x, float y);

    std::tuple<int, int> GetSurfaceSize();
    void setSize(float w, float h);
};


#endif //C_ARBEIDSKRAV_IMAGE_H
