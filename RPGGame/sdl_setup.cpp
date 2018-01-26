#include "sdl_setup.h"

SDL_Setup::SDL_Setup(bool* quit, int screenWidth, int screenHeight)
{
    window = NULL;
    window = SDL_CreateWindow("Sprites Teste", 100, 100, screenWidth, screenHeight, SDL_WINDOW_SHOWN);


    if(window == NULL)
    {
        std::cout << "Window couldn't be created. " << std::endl;
        *quit = true;
    }

    renderer = NULL;
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    mainEvent = new SDL_Event();
}

SDL_Setup::~SDL_Setup()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    delete mainEvent;

}

SDL_Event* SDL_Setup::GetMainEvent()
{
    return mainEvent;
}

SDL_Renderer* SDL_Setup::GetRenderer()
{
    return renderer;
}

void SDL_Setup::Begin()
{
    SDL_PollEvent(mainEvent);
    SDL_RenderClear(renderer);
}

void SDL_Setup::End()
{
    SDL_RenderPresent(renderer);
}
