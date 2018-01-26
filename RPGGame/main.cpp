#include "main.h"


Main::Main(int passed_ScreenWidth, int passed_ScreenHeight)
{
    screenWidth = passed_ScreenWidth;
    screenHeight = passed_ScreenHeight;
    quit = false;

    sdl_setup = new SDL_Setup(&quit, screenWidth, screenHeight);
    grass = new Sprite(sdl_setup->GetRenderer(),"data/grass.bmp", 0, 0, screenWidth, screenHeight, 0, 0, 0, 0);
    bob = new Sprite(sdl_setup->GetRenderer(),"data/bob.bmp", 100, 300, 100, 100, 0, 0, 0, 0);

    Moveup = false;
    Movedown = false;
    Moveleft = false;
    Moveright = false;
    timecheck = SDL_GetTicks();
}

Main::~Main()
{
    delete sdl_setup;
    delete grass;
    delete bob;
}

void Main::GameLoop()
{
    while (!quit && sdl_setup->GetMainEvent()->type != SDL_QUIT)
    {
        sdl_setup->Begin();
        grass->Draw();
        bob->Draw();
        sdl_setup->End();

        switch(sdl_setup->GetMainEvent()->type)
        {
            case SDL_KEYDOWN:

                switch(sdl_setup->GetMainEvent()->key.keysym.sym)
                {
                    case SDLK_a:
                        Moveleft = true;
                    break;
                    case SDLK_d:
                        Moveright = true;
                    break;
                    case SDLK_w:
                        Moveup = true;
                    break;
                    case SDLK_s:
                        Movedown = true;
                    break;
                    default:
                    break;
                }
            break;

            case SDL_KEYUP:

                switch(sdl_setup->GetMainEvent()->key.keysym.sym)
                {
                    case SDLK_a:
                        Moveleft = false;
                    break;
                    case SDLK_d:
                        Moveright = false;
                    break;
                    case SDLK_w:
                        Moveup = false;
                    break;
                    case SDLK_s:
                        Movedown = false;
                    break;
                    default:
                    break;
                }
            break;
            default:
            break;
        }
        if(timecheck+2 < SDL_GetTicks())
        {
            if(Moveleft)
            {
                bob->SetX(bob->GetX()-1);
            }

            if(Moveright)
            {
                bob->SetX(bob->GetX()+1);
            }

            if(Moveup)
            {
                bob->SetY(bob->GetY()-1);
            }

            if(Movedown)
            {
                bob->SetY(bob->GetY()+1);
            }

            timecheck = SDL_GetTicks();
        }
    }
}
