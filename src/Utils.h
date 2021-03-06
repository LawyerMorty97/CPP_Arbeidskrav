//
// Created by Mathias Berntsen on 15/02/2019.
//

#ifndef ARBEIDSKRAV_UTILS_H
#define ARBEIDSKRAV_UTILS_H

#include <iostream>
#include <SDL.h>

class Utils {
public:
    static const char* stringToChar(std::string str);
    static std::string intToString(int num);

    static void message(std::string msg);
    static void error(std::string msg);
    static void error_sdl(std::string msg);
};


#endif //ARBEIDSKRAV_UTILS_H
