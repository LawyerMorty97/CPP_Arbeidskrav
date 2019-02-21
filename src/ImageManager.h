//
// Created by mmfij on 2/20/2019.
//

#ifndef C_ARBEIDSKRAV_IMAGEMANAGER_H
#define C_ARBEIDSKRAV_IMAGEMANAGER_H

#include <iostream>
#include <SDL.h>

#include "Image.h"

class ImageManager {
public:
    static ImageManager* instance();

    void Draw();
protected:
    SDL_Renderer* renderer;
private:
    static ImageManager *inst_;

    ImageManager(SDL_Renderer* renderer) {
        ImageManager::renderer = renderer;
    }
};


#endif //C_ARBEIDSKRAV_IMAGEMANAGER_H
