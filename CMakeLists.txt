cmake_minimum_required(VERSION 3.13)
project(C++_Arbeidskrav)

set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/bin")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lSDL2")

set(INC_DIR "${PROJECT_SOURCE_DIR}/include") #Include Directory
set(LIB_DIR "${PROJECT_SOURCE_DIR}/library") #Library Directory

find_package(OpenGL REQUIRED)

set(SDL2_LIB "${LIB_DIR}/libSDL2.dll.a;${LIB_DIR}/libSDL2main.a")

include_directories(${INC_DIR} ${OPENGL_INCLUDE_DIR})

add_executable(${PROJECT_NAME} main.cpp Core.cpp Image.cpp Utils.cpp InputManager.cpp)

target_link_libraries(${PROJECT_NAME} ${SDL2_LIB} ${OPENGL_LIBRARIES})