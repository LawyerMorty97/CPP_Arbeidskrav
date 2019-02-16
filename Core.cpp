//
// Created by Mathias Berntsen on 13/02/2019.
//

#include "Core.h"

void Core::error(std::string msg) {
    std::cerr << "ERROR: " << msg << "." << std::endl;
    exit(1);
}

void Core::error_sdl(std::string msg) {
    std::cerr << "SDL ERROR: " << msg << ". (" << SDL_GetError() << ")" << std::endl;
    SDL_Quit();
    exit(EXIT_FAILURE);
}

Core::Image Core::CreateImage(std::string image) {
    Image img;

    SDL_Surface* surface = SDL_LoadBMP(Utils::stringToChar("images/" + image));

    if (surface == nullptr) {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        error_sdl("Failed to load image '" + image + "'");
    }

    SDL_Texture* drawable = SDL_CreateTextureFromSurface(renderer, surface);
    img.txd = drawable;

    img.coords.x = 0;
    img.coords.y = 0;
    img.coords.w = surface->w / 2;
    img.coords.h = surface->h / 2;

    SDL_FreeSurface(surface);

    return img;
}

Core::Core(std::string title, int w_size, int h_size) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        error_sdl("Unable to initalize SDL");

    char* c_title = Utils::stringToChar(title);

    window = SDL_CreateWindow(c_title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w_size, h_size, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
    if (!window)
        error_sdl("Failed to create window");

    renderer = SDL_CreateRenderer(window, 01, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        SDL_DestroyWindow(window);
        error_sdl("Failed to create renderer");
    }

    SDL_SetRenderDrawColor(renderer, 128, 255, 128, 255); // Light Green
    SDL_RenderClear(renderer);

    Image image = CreateImage("lmorty.bmp");

    int nK = 0;
    const Uint8 *keys = nullptr;
    float x = 0.f;

    SDL_Event e;
    bool quit = false;

    while (!quit) {
        SDL_PumpEvents();
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT)
                quit = true;

            if (e.type == SDL_KEYDOWN) {
                switch(e.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        quit = true;
                        break;
                }
            }
        }
        keys = SDL_GetKeyboardState(&nK);
        if (keys[SDL_SCANCODE_RIGHT] || keys[SDL_SCANCODE_D]) {
            x += 0.1;
            image.coords.x = static_cast<int>(x);
        }
        if (keys[SDL_SCANCODE_LEFT] || keys[SDL_SCANCODE_A]) {
            x -= 0.1;
            image.coords.x = static_cast<int>(x);
        }

        SDL_RenderCopy(renderer, image.txd, nullptr, &image.coords);

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