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

    bool operator==(const InputManager &rhs) const;

    bool operator!=(const InputManager &rhs) const;

    bool KeyDown(int iKeyIndex);
    bool KeyStillDown(int iKeyIndex);
    bool KeyUp(int iKeyIndex);
    bool KeyStillUp(int iKeyIndex);

    bool MouseDown(int iButton);
    bool MouseStillDown(int iButton);
    bool MouseUp(int iButton);
    bool MouseStillUp(int iButton);

    void Update();

protected:
    const Uint8* keys;
    std::unique_ptr<Uint8> oldKeys;
    int keyCount;

    int mouseX;
    int mouseY;

    Uint8 buttons;
    Uint8 oldButtons;
private:
    static InputManager *inst_;

    InputManager() {
        keys = SDL_GetKeyboardState(&keyCount);
        oldKeys = std::unique_ptr<Uint8>(new Uint8[keyCount]);
    }
};

#endif //CPP_ARBEIDSKRAV_INPUTMANAGER_H
