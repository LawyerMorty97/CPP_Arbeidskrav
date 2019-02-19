//
// Created by Mathias Berntsen on 15/02/2019.
//

#include "InputManager.h"

InputManager* InputManager::inst_ = NULL;

InputManager* InputManager::instance() {
    if (inst_ == NULL) {
        inst_ = new InputManager();
    }

    return inst_;
}

void InputManager::Update() {
    oldButtons = buttons;
    memcpy(oldKeys.get(), keys, keyCount * sizeof(Uint8));

    SDL_PumpEvents();

    keys = SDL_GetKeyboardState(&keyCount);
    buttons = SDL_GetRelativeMouseState(&mouseX, &mouseY);

}

bool InputManager::KeyDown(int iKeyIndex) {
    bool current_state = keys[iKeyIndex];
    bool last_state = oldKeys.get()[iKeyIndex];
    return (current_state && !last_state);
}

bool InputManager::KeyUp(int iKeyIndex) {
    bool current_state = keys[iKeyIndex];
    bool last_state = oldKeys.get()[iKeyIndex];
    return (!current_state && last_state);
}

bool InputManager::KeyStillDown(int iKeyIndex) {
    bool current_state = keys[iKeyIndex];
    bool last_state = oldKeys.get()[iKeyIndex];
    return (current_state && last_state);
}

std::tuple<int, int> InputManager::MousePosition() {
    return {mouseX, mouseY};
}

bool InputManager::KeyStillUp(int iKeyIndex) {
    bool current_state = keys[iKeyIndex];
    bool last_state = oldKeys.get()[iKeyIndex];
    return (!current_state && !last_state);
}

bool InputManager::MouseDown(int iButton) {
    bool current_state = buttons & SDL_BUTTON(iButton);
    bool last_state = oldButtons & SDL_BUTTON(iButton);

    return (current_state && !last_state);
}

bool InputManager::MouseUp(int iButton) {
    bool current_state = buttons & SDL_BUTTON(iButton);
    bool last_state = oldButtons & SDL_BUTTON(iButton);

    return (!current_state && last_state);
}

bool InputManager::MouseStillDown(int iButton) {
    bool current_state = buttons & SDL_BUTTON(iButton);
    bool last_state = oldButtons & SDL_BUTTON(iButton);

    return (current_state && last_state);
}

bool InputManager::MouseStillUp(int iButton) {
    bool current_state = buttons & SDL_BUTTON(iButton);
    bool last_state = oldButtons & SDL_BUTTON(iButton);

    return (!current_state && !last_state);
}