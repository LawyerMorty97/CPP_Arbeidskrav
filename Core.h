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

class Core {
public:

    struct Image {
        SDL_Rect coords;
        SDL_Texture* txd;
    };

    Core(std::string title, int w_size, int h_size);
    ~Core();

    void error(std::string msg);
    void error_sdl(std::string msg);
    void Quit();

    Image CreateImage(std::string image);

private:
    int w_width, w_height; // Window dimensions
    SDL_Window* window;
    SDL_Renderer* renderer;
};


#endif //PROJECT_CORE_H
