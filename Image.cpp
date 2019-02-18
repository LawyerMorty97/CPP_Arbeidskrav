//
// Created by Mathias Berntsen on 18/02/2019.
//

#include <tuple>
#include "Image.h"

Image::Image(std::string filename, int x, int y, SDL_Renderer* renderer) : x(_x), y(_y), w(_w), h(_h) {
    surface = SDL_LoadBMP(Utils::stringToChar("images/" + filename));

    if (surface == nullptr) {
        Utils::error_sdl("Failed to load image '" + filename + "'");
        return;
    }

    texture = SDL_CreateTextureFromSurface(renderer, surface);

    rect.x = x;
    rect.y = y;
    rect.w = surface->w / 2;
    rect.h = surface->h / 2;

    _x = x;
    _y = y;
    _w = surface->w / 2;
    _h = surface->h / 2;

    SDL_FreeSurface(surface);

    Image::renderer = renderer;

    mCanRender = true;
}

std::tuple<float, float> Image::getPosition() {
    return {x, y};
}

void Image::setPosition(float x, float y) {
    _x = x;
    _y = y;
    rect.x = static_cast<int>(_x);
    rect.y = static_cast<int>(_y);
}

std::tuple<float, float> Image::getSize() {
    return {w, h};
}

void Image::setSize(float w, float h) {
    _w = w;
    _h = h;
    rect.w = static_cast<int>(_w);
    rect.h = static_cast<int>(_h);
}

bool Image::Draw() {
    if (!mCanRender)
        return false;

    SDL_RenderCopy(renderer, texture, nullptr, &rect);

    return true;
}

Image::~Image() {
}