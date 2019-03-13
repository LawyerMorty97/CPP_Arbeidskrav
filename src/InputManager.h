//
// Created by Mathias Berntsen on 15/02/2019.
//

#ifndef CPP_ARBEIDSKRAV_INPUTMANAGER_H
#define CPP_ARBEIDSKRAV_INPUTMANAGER_H

#include <iostream>
#include <cstring>
#include <memory>
#include <SDL.h>

class InputManager {
public:
    static InputManager *instance();

    bool KeyDown(int iKeyIndex);
    bool KeyStillDown(int iKeyIndex);
    bool KeyUp(int iKeyIndex);
    bool KeyStillUp(int iKeyIndex);

    bool MouseDown(int iButton);
    bool MouseStillDown(int iButton);
    bool MouseUp(int iButton);
    bool MouseStillUp(int iButton);

    std::tuple<int, int> MousePosition();

    void Update();

protected:
    const Uint8* m_keys;
    std::unique_ptr<Uint8> m_oldKeys;
    int m_keyCount;

    int m_mouseX;
    int m_mouseY;

    Uint32 m_buttons;
    Uint32 m_oldButtons;
private:
    static InputManager *inst_;

    InputManager() {
        m_keys = SDL_GetKeyboardState(&m_keyCount);
        m_oldKeys = std::unique_ptr<Uint8>(new Uint8[m_keyCount]);

        m_buttons = SDL_GetRelativeMouseState(&m_mouseX, &m_mouseY);
    }
};

#endif //CPP_ARBEIDSKRAV_INPUTMANAGER_H
