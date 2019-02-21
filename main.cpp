#include <iostream>

#include "src/Core.h"

Core* core;

int main() {
    core = Core::instance();
    core->Setup("Hello World", 800, 600);

    delete core;

    return 0;
}