#ifndef MAIN_H
#define MAIN_H
#include "sdl_setup.h"
#include "sprite.h"

class Main
{
    public:
        Main(int passed_ScreenWidth, int passed_ScreenHeight);
        virtual ~Main();
        void GameLoop();

    protected:
    private:
        int screenWidth;
        int screenHeight;
        unsigned int timecheck;
        bool quit;
        SDL_Window* window;
        SDL_Renderer* renderer;
        SDL_Event* mainEvent;

        SDL_Setup* sdl_setup;
        Sprite* grass;
        Sprite* bob;

        bool Moveleft;
        bool Moveright;
        bool Moveup;
        bool Movedown;
};

#endif // MAIN_H
