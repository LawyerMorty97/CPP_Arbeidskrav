cmake_minimum_required(VERSION 3.13)
project(C++_Arbeidskrav)

set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/bin")

set(CMAKE_CXX_STANDARD 17)

if(${APPLE})
    message("Preparing macOS project")
    find_package(SDL2 REQUIRED)
    find_package(SDL2_image REQUIRED)
    find_package(SDL2_ttf REQUIRED)
    find_package(OpenGL REQUIRED)

    include_directories(${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR} ${SDL2_TTF_INCLUDE_DIR} ${OPENGL_INCLUDE_DIR})
else()
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lSDL2 -lSDL_ttf")

    set(INC_DIR "${PROJECT_SOURCE_DIR}/include") #Include Directory
    set(LIB_DIR "${PROJECT_SOURCE_DIR}/library") #Library Directory
    find_package(OpenGL REQUIRED)

    if(${WIN32})
        message("Preparing Win32 project")
        set(SDL2_LIB "${LIB_DIR}/libSDL2.dll.a;${LIB_DIR}/libSDL2main.a")
        set(SDL2_TTF_LIB "${LIB_DIR}/libSDL2_ttf.dll.a")
    else()
        message("Preparing Linux project")
        set(SDL2_LIB "${LIB_DIR}/libSDL2.a;${LIB_DIR}/libSDL2main.a")
        set(SDL2_TTF_LIB "${LIB_DIR}/libSDL2_ttf.a")
    endif()

    include_directories(${INC_DIR} ${OPENGL_INCLUDE_DIR})
endif()

add_executable(${PROJECT_NAME} main.cpp src/Core.cpp src/Image.cpp src/Utils.cpp src/InputManager.cpp src/ImageManager.cpp src/ImageManager.h imgui/imgui.cpp imgui/imgui_draw.cpp imgui/imgui_sdl.cpp imgui/imgui_widgets.cpp imgui/imgui_demo.cpp)

if(${APPLE})
    target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY} ${SDL2_TTF_LIBRARY} ${SDL2_IMAGE_LIBRARY} ${OPENGL_LIBRARIES})
elseif (${WIN32})
    target_link_libraries(${PROJECT_NAME} ${SDL2_LIB} ${SDL2_TTF_LIB} ${OPENGL_LIBRARIES})
else()
endif()