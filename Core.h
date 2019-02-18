//
// Created by Mathias Berntsen on 13/02/2019.
//

#ifndef PROJECT_CORE_H
#define PROJECT_CORE_H

#include <iostream>

#define SDL_MAIN_HANDLED
#include <SDL.h>

#include "Utils.h"
#include "InputManager.h"

#include "Image.h"

class Core {
public:
    Core(std::string title, int w_size, int h_size);
    ~Core();

    void Quit();
private:
    int w_width, w_height; // Window dimensions
    SDL_Window* window;
    SDL_Renderer* renderer;

    InputManager* input;
};


#endif //PROJECT_CORE_H
