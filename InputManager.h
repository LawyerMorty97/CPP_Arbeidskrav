//
// Created by Mathias Berntsen on 15/02/2019.
//

#ifndef PROJECT1_INPUTMANAGER_H
#define PROJECT1_INPUTMANAGER_H

#include <iostream>
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

protected:
    const Uint8* keys;
    std::unique_ptr<Uint8> oldKeys;
    int keyCount;

    InputManager() {
        keys = SDL_GetKeyboardState(&keyCount);
        oldKeys = std::unique_ptr<Uint8>(new Uint8[keyCount]);
    }

    int mouseX;
    int mouseY;

    Uint8 buttons;
    Uint8 oldButtons;
private:
    static InputManager *inst;
};

InputManager* InputManager::inst = 0;

#endif //PROJECT1_INPUTMANAGER_H
