//
// Created by Mathias Berntsen on 13/02/2019.
//

#include "Core.h"

Core::Core(std::string title, int w_size, int h_size) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        Utils::error_sdl("Unable to initalize SDL");

    char* c_title = Utils::stringToChar(title);

    window = SDL_CreateWindow(c_title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w_size, h_size, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
    if (!window)
        Utils::error_sdl("Failed to create window");

    renderer = SDL_CreateRenderer(window, 01, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        SDL_DestroyWindow(window);
        Utils::error_sdl("Failed to create renderer");
    }

    SDL_SetRenderDrawColor(renderer, 128, 255, 128, 255); // Light Green
    SDL_RenderClear(renderer);

    Image image = Image("lmorty.bmp", 0, 0, renderer);

    // Input
    input = InputManager::instance();

    float x = 0.f;
    float y = 0.f;

    SDL_Event e;
    bool quit = false;

    while (!quit) {
        input->Update();

        while(SDL_PollEvent(&e))
            if (e.type == SDL_QUIT)
                quit = true;

        if (input->KeyUp(SDL_SCANCODE_ESCAPE))
            quit = true;

        if (input->KeyStillDown(SDL_SCANCODE_A) || input->KeyStillDown(SDL_SCANCODE_LEFT)) {
            image.setPosition(image.x - 0.1f, image.y);
        }

        if (input->KeyStillDown(SDL_SCANCODE_D) || input->KeyStillDown(SDL_SCANCODE_RIGHT)) {
            image.setPosition(image.x + 0.1f, image.y);
        }

        if (input->KeyStillDown(SDL_SCANCODE_W) || input->KeyStillDown(SDL_SCANCODE_UP)) {
            image.setPosition(image.x, image.y - 0.1f);
        }

        if (input->KeyStillDown(SDL_SCANCODE_S) || input->KeyStillDown(SDL_SCANCODE_DOWN)) {
            image.setPosition(image.x, image.y + 0.1f);
        }

        if (input->KeyStillDown(SDL_SCANCODE_Q)) {
            image.setSize(image.w - 0.1f, image.h - 0.1f);
        }

        if (input->KeyStillDown(SDL_SCANCODE_E)) {
            image.setSize(image.w + 0.1f, image.h + 0.1f);
        }

        //SDL_RenderCopy(renderer, image.txd, nullptr, &image.coords);
        image.Draw();

        SDL_RenderPresent(renderer);
        SDL_RenderClear(renderer);
    }
}

void Core::Quit() {
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    exit(EXIT_SUCCESS);
}

Core::~Core() {
    Quit();
}