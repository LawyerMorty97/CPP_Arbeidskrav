#include <iostream>

#include "Core.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    Core c("Test", 640, 480);

    c.Quit();

    return 0;
}