//
// Created by Mathias Berntsen on 15/02/2019.
//

#include "InputManager.h"

InputManager* InputManager::instance() {
    if (!inst) {
        inst = new InputManager();
    }

    return instance();
}

bool InputManager::KeyDown(int iKeyIndex) {

}

bool InputManager::KeyStillDown(int iKeyIndex) {

}