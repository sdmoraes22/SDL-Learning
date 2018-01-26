/***************************************************************/
/**Classe responsável por inicializar o SDL e o loop principal**/
/**do aplicativo************************************************/

#ifndef SDL_SETUP_H
#define SDL_SETUP_H
#include"sdl_principal.h"


class SDL_Setup
{
    public:
        //Construtor que inicializa a janela e o renderizador do SDL
        SDL_Setup(bool* quit, int screenWidth, int screenHeight);
        virtual ~SDL_Setup();

        SDL_Event* GetMainEvent();
        SDL_Renderer* GetRenderer();


        void Begin();
        void End();
    protected:
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
        SDL_Event* mainEvent;


};

#endif // SDL_SETUP_H
