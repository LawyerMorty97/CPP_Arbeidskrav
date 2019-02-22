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

    imageManager->Add("lmorty.bmp", 0, 0, 128, 128);
    imageManager->Add("rick.bmp", 128, 0, 128, 128);

    while (!quit) {
        Update();
        Draw();
    }

    Quit();
}

void Core::Quit() {
    delete input;
    delete imageManager;

    Utils::message("Deinitialized ImGui");
    ImGuiSDL::Deinitialize();

    Utils::message("Destroyed SDL renderer");
    SDL_DestroyRenderer(renderer);

    Utils::message("Destroyed SDL window");
    SDL_DestroyWindow(window);

    Utils::message("Destroyed ImGui Context");
    ImGui::DestroyContext();

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

    ImGui::CreateContext();
    ImGuiSDL::Initialize(renderer, w_width, w_height);

    imageManager = ImageManager::instance(renderer);
    input = InputManager::instance();
}

void Core::Update() {
    input->Update();
    ImGuiIO& io = ImGui::GetIO();

    while(SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT)
            quit = true;
        else if (event.type == SDL_WINDOWEVENT) {
            if (event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED) {
                io.DisplaySize.x = static_cast<float>(event.window.data1);
                io.DisplaySize.y = static_cast<float>(event.window.data2);
            }
        }
    }

    io.DeltaTime = 1.f / 60.f;
    int x;
    int y;
    const int btns = SDL_GetMouseState(&x, &y);
    io.MousePos = ImVec2(x, y);
    io.MouseDown[0] = btns & SDL_BUTTON(SDL_BUTTON_LEFT);
    io.MouseDown[1] = btns & SDL_BUTTON(SDL_BUTTON_RIGHT);


    if (input->KeyUp(SDL_SCANCODE_ESCAPE))
        quit = true;

    Image* image1 = imageManager->Get(0);
    Image* image2 = imageManager->Get(1);
    if (input->KeyStillDown(SDL_SCANCODE_A)) {
        image1->setPosition(image1->x - 0.1f, image1->y);
    }

    if (input->KeyStillDown(SDL_SCANCODE_D)) {
        image1->setPosition(image1->x + 0.1f, image1->y);
    }

    if (input->KeyStillDown(SDL_SCANCODE_W)) {
        image1->setPosition(image1->x, image1->y - 0.1f);
    }

    if (input->KeyStillDown(SDL_SCANCODE_S)) {
        image1->setPosition(image1->x, image1->y + 0.1f);
    }

    if (input->KeyStillDown(SDL_SCANCODE_LEFT)) {
        image2->setPosition(image2->x - 0.1f, image2->y);
    }

    if (input->KeyStillDown(SDL_SCANCODE_RIGHT)) {
        image2->setPosition(image2->x + 0.1f, image2->y);
    }

    if (input->KeyStillDown(SDL_SCANCODE_UP)) {
        image2->setPosition(image2->x, image2->y - 0.1f);
    }

    if (input->KeyStillDown(SDL_SCANCODE_DOWN)) {
        image2->setPosition(image2->x, image2->y + 0.1f);
    }
}

void Core::Draw() {
    ImGui::NewFrame();
    //ImGui::ShowDemoWindow();

    ImGuiIO &io = ImGui::GetIO();

    ImGui::SetNextWindowBgAlpha(0.3f);
    ImGui::Begin("Example: Simple Overlay", NULL, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoNav);
    ImGui::Text("Simple overlay\nIn the corner of the screen\n(right-click to position)");
    ImGui::Separator();
    if (ImGui::IsMousePosValid())
        ImGui::Text("Mouse Position: (%.1f, %.1f)", io.MousePos.x, io.MousePos.y);
    else
        ImGui::Text("Mouse Position: <invalid>");
    if (ImGui::BeginPopupContextWindow()) {
        ImGui::EndPopup();
    }
    ImGui::End();

    SDL_SetRenderDrawColor(renderer, 128, 255, 128, 255); // Light Green
    SDL_RenderClear(renderer);

    imageManager->Draw();

    ImGui::Render();
    ImGuiSDL::Render(ImGui::GetDrawData());

    SDL_RenderPresent(renderer);
}

Core::~Core() {
    Quit();
}