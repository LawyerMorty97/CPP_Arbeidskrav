//
// Created by Mathias Berntsen on 15/02/2019.
//

#include "Utils.h"

char* Utils::stringToChar(std::string str) {
    char* result;

    result = const_cast<char*>(str.c_str());

    return result;
}

std::string Utils::intToString(int num) {
    std::string str = std::to_string(num);

    return str;
}

void Utils::message(std::string msg) {
    std::cout << "MESSAGE: " << msg << "." << std::endl;
}

void Utils::error(std::string msg) {
    std::cerr << "ERROR: " << msg << "." << std::endl;
    exit(EXIT_FAILURE);
}

void Utils::error_sdl(std::string msg) {
    std::cerr << "SDL ERROR: " << msg << ". (" << SDL_GetError() << ")" << std::endl;
    SDL_Quit();
    exit(EXIT_FAILURE);
}