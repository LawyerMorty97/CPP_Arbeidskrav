#include <iostream>

#include "Core.h"

Core* core;

int main() {
    core = Core::instance();
    core->Setup("Hello World", 800, 600);

    return 0;
}