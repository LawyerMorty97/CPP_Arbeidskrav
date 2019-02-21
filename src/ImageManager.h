//
// Created by mmfij on 2/20/2019.
//

#ifndef C_ARBEIDSKRAV_IMAGEMANAGER_H
#define C_ARBEIDSKRAV_IMAGEMANAGER_H

#include <iostream>
#include <SDL.h>

#include "Image.h"

class ImageManager {
public:
    static ImageManager* instance(SDL_Renderer* renderer);
    ~ImageManager();

    Image* Add(std::string image, int x, int y, int w, int h);
    Image* Get(int index);
    void Draw();
protected:
    SDL_Renderer* renderer;

    Image** buffer;
    int allocated = 0;
    int extra = 0;
    const int ALLOC_MAX = 10000;
private:
    static ImageManager *inst_;

    ImageManager(SDL_Renderer* renderer) {
        buffer = new Image*[ALLOC_MAX];

        /*int allocated = 0;
        int jmp = 0;
        int m = 10;
        int c = 500;

        int* v = new int[m];
        for (int i = 0; i < c; i++) {
            std::cout << "Allocated i" << i << std::endl;
            if (allocated >= (m-1) && ((m+jmp) < c)) {
                jmp += 1;
                std::cout << "Extending array size to " << (m + jmp) << "(" << allocated << ")" << std::endl;
                int* t = new int[m+jmp];
                for (int j = 0; j < allocated; j++) {
                    t[j] = v[j];
                }
                delete[] v;
                v = t;
            }
            v[i] = rand() * i;
            allocated += 1;
        }*/
        ImageManager::renderer = renderer;
    }
};


#endif //C_ARBEIDSKRAV_IMAGEMANAGER_H
