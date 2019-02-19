//
// Created by Mathias Berntsen on 13/02/2019.
//

#include "Core.h"

Core* Core::inst_ = NULL;

Core* Core::instance() {
    if (inst_ == NULL) {
        inst_ = new Core();
    }

    return inst_;
}

void Core::Setup(std::string title, int w_size, int h_size) {
    Core::title = title;
    Core::w_width = w_size;
    Core::w_height = h_size;

    SetupSDL();
    setup = true;

    image = new Image("lmorty.bmp", 0, 0, renderer);

    while (!quit) {
        Update();
        Draw();
    }

    Quit();
}

void Core::Quit() {
    SDL_DestroyWindow(window);
    Utils::message("Destroyed SDL window");
    SDL_DestroyRenderer(renderer);
    Utils::message("Destroyed SDL renderer");
    SDL_Quit();
    Utils::message("Quit SDL");

    exit(EXIT_SUCCESS);
}

void Core::SetupSDL() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        Utils::error_sdl("Unable to initalize SDL");
    else
        Utils::message("Initialized SDL");

    char* c_title = Utils::stringToChar(title);

    window = SDL_CreateWindow(c_title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w_width, w_height, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
    if (!window)
        Utils::error_sdl("Failed to create window");
    else
        Utils::message("Created a window");

    renderer = SDL_CreateRenderer(window, 01, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        SDL_DestroyWindow(window);
        Utils::error_sdl("Failed to create renderer");
    } else {
        Utils::message("Created a SDL renderer");
    }

    SDL_SetRenderDrawColor(renderer, 128, 255, 128, 255); // Light Green
    SDL_RenderClear(renderer);

    input = InputManager::instance();
}

void Core::Update() {
    input->Update();

    while(SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT)
            quit = true;
    }

    if (input->KeyUp(SDL_SCANCODE_ESCAPE))
        quit = true;

    if (input->KeyStillDown(SDL_SCANCODE_A) || input->KeyStillDown(SDL_SCANCODE_LEFT)) {
        image->setPosition(image->x - 0.1f, image->y);
    }

    if (input->KeyStillDown(SDL_SCANCODE_D) || input->KeyStillDown(SDL_SCANCODE_RIGHT)) {
        image->setPosition(image->x + 0.1f, image->y);
    }

    if (input->KeyStillDown(SDL_SCANCODE_W) || input->KeyStillDown(SDL_SCANCODE_UP)) {
        image->setPosition(image->x, image->y - 0.1f);
    }

    if (input->KeyStillDown(SDL_SCANCODE_S) || input->KeyStillDown(SDL_SCANCODE_DOWN)) {
        image->setPosition(image->x, image->y + 0.1f);
    }

    if (input->KeyStillDown(SDL_SCANCODE_Q)) {
        image->setSize(image->w - 0.1f, image->h - 0.1f);
    }

    if (input->KeyStillDown(SDL_SCANCODE_E)) {
        image->setSize(image->w + 0.1f, image->h + 0.1f);
    }

    if (input->MouseUp(SDL_BUTTON_RIGHT))
        quit = true;
}

void Core::Draw() {
    image->Draw();

    SDL_RenderPresent(renderer);
    SDL_RenderClear(renderer);
}

Core::~Core() {
    Quit();
}