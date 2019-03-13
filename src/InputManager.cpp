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
    m_oldButtons = m_buttons;
    memcpy(m_oldKeys.get(), m_keys, m_keyCount * sizeof(Uint8));

    SDL_PumpEvents();

    m_keys = SDL_GetKeyboardState(&m_keyCount);
    m_buttons = SDL_GetRelativeMouseState(&m_mouseX, &m_mouseY);

}

bool InputManager::KeyDown(int iKeyIndex) {
    bool current_state = m_keys[iKeyIndex];
    bool last_state = m_oldKeys.get()[iKeyIndex];
    return (current_state && !last_state);
}

bool InputManager::KeyUp(int iKeyIndex) {
    bool current_state = m_keys[iKeyIndex];
    bool last_state = m_oldKeys.get()[iKeyIndex];
    return (!current_state && last_state);
}

bool InputManager::KeyStillDown(int iKeyIndex) {
    bool current_state = m_keys[iKeyIndex];
    bool last_state = m_oldKeys.get()[iKeyIndex];
    return (current_state && last_state);
}

std::tuple<int, int> InputManager::MousePosition() {
    return {m_mouseX, m_mouseY};
}

bool InputManager::KeyStillUp(int iKeyIndex) {
    bool current_state = m_keys[iKeyIndex];
    bool last_state = m_oldKeys.get()[iKeyIndex];
    return (!current_state && !last_state);
}

bool InputManager::MouseDown(int iButton) {
    bool current_state = m_buttons & SDL_BUTTON(iButton);
    bool last_state = m_oldButtons & SDL_BUTTON(iButton);

    return (current_state && !last_state);
}

bool InputManager::MouseUp(int iButton) {
    bool current_state = m_buttons & SDL_BUTTON(iButton);
    bool last_state = m_oldButtons & SDL_BUTTON(iButton);

    return (!current_state && last_state);
}

bool InputManager::MouseStillDown(int iButton) {
    bool current_state = m_buttons & SDL_BUTTON(iButton);
    bool last_state = m_oldButtons & SDL_BUTTON(iButton);

    return (current_state && last_state);
}

bool InputManager::MouseStillUp(int iButton) {
    bool current_state = m_buttons & SDL_BUTTON(iButton);
    bool last_state = m_oldButtons & SDL_BUTTON(iButton);

    return (!current_state && !last_state);
}