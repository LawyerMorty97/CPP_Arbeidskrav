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
    const Uint8* keys;
    std::unique_ptr<Uint8> oldKeys;
    int keyCount;

    int mouseX, mouseY;

    Uint32 buttons;
    Uint32 oldButtons;
private:
    static InputManager *inst_;

    InputManager() {
        keys = SDL_GetKeyboardState(&keyCount);
        oldKeys = std::unique_ptr<Uint8>(new Uint8[keyCount]);

        buttons = SDL_GetRelativeMouseState(&mouseX, &mouseY);
    }
};

#endif //CPP_ARBEIDSKRAV_INPUTMANAGER_H
