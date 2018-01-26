/******************************************************************/
/**Classe reponsável por carregar e renderizar os sprites na tela**/
/******************************************************************/

#ifndef SPRITE_H
#define SPRITE_H
#include "sdl_setup.h"

class Sprite
{
    public:

        //Construtor para imagens e tilesets
        Sprite(SDL_Renderer* passed_renderer, std::string filename, int src_x, int src_y, int src_width, int src_height,
                int dest_x, int dest_y, int dest_width, int dest_height);

        virtual ~Sprite();

        //Desenha a imagem no render
        void Draw();
        //Detecta a colisão de um sprite
        void Collision();

        void SetX(int x);

        void SetY(int y);

        int GetX();

        int GetY();

    protected:
    private:
        SDL_Texture* image;
        SDL_Rect srect;
        SDL_Rect drect;


        SDL_Renderer* renderer;
        SDL_Event* spriteEvent;
};

#endif // SPRITE_H
