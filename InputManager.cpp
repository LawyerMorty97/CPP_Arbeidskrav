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

bool InputManager::KeyStillUp(int iKeyIndex) {
    bool current_state = keys[iKeyIndex];
    bool last_state = oldKeys.get()[iKeyIndex];
    return (current_state && last_state);
}