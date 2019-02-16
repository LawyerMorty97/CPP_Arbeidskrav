//
// Created by Mathias Berntsen on 15/02/2019.
//

#include "Utils.h"

char* Utils::stringToChar(std::string str) {
    char* result;

    result = const_cast<char*>(str.c_str());

    return result;
}