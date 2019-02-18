//
// Created by Mathias Berntsen on 18/02/2019.
//

#include "Image.h"

Image::Image(std::string filename) {
    surface = SDL_LoadBMP(Utils::stringToChar("images/" + filename));

    if (surface == nullptr) {
    }
}

Image::~Image() {
}