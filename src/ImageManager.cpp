//
// Created by mmfij on 2/20/2019.
//

#include "ImageManager.h"

ImageManager* ImageManager::inst_ = NULL;

ImageManager* ImageManager::instance(SDL_Renderer* renderer) {
    if (inst_ == NULL) {
        inst_ = new ImageManager(renderer);
    }

    return inst_;
}

ImageManager::~ImageManager() {
    delete[] buffer;
}

Image* ImageManager::Add(std::string image, int x, int y, int w, int h) {
    Image* new_image = new Image(image, x, y, w, h, renderer);

    buffer[allocated] = new_image;
    allocated++;

    return new_image;
}

Image* ImageManager::Get(int index) {
    Image* image = nullptr;
    if (buffer[index] != nullptr)
        image = buffer[index];

    return image;
}

void ImageManager::Draw() {
    for(int i = 0; i < (allocated + extra); i++) {
        Image* image = buffer[i];
        image->Draw();
    }
}