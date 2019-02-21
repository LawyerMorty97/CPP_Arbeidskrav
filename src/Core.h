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

#include "imgui/imgui.h"
#include "imgui/imgui_sdl.h"

#include "Image.h"

class Core {
public:
    static Core* instance();

    void Setup(std::string title, int w_size, int h_size);
    ~Core();
protected:
    int w_width, w_height; // Window dimensions
    bool quit = false;
    bool setup = false;

    std::string title;

    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event event;

    InputManager* input;

    Image* image1;
    Image* image2;
private:
    static Core* inst_;

    Core() {

    };

    void SetupSDL();
    void Quit();

    void Update();
    void Draw();
};


#endif //PROJECT_CORE_H
