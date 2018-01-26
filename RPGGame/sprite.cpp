#include "sprite.h"


Sprite::Sprite(SDL_Renderer* passed_renderer, std::string filename, int src_x, int src_y, int src_width, int src_height,
                int dest_x, int dest_y, int dest_width, int dest_height)
{
    renderer = passed_renderer;
    image = NULL;
    image = IMG_LoadTexture(renderer, filename.c_str());
    if(image == NULL)
    {
        std::cout << "Nao foi possivel carregar a imagem: " << filename <<std::endl;
    }

    drect.x = src_x;
    drect.y = src_y;
    drect.w = src_width;
    drect.h = src_height;

    srect.x = dest_x;
    srect.y = dest_y;
    srect.w = dest_width;
    srect.h = dest_height;
}

Sprite::~Sprite()
{
    SDL_DestroyTexture(image);
}

void Sprite::Draw()
{
    if(srect.x == 0 && srect.y == 0 && srect.w == 0 && srect.h == 0)
    {
        SDL_RenderCopy(renderer,image, NULL, &drect);
    }
    else
    {
        SDL_RenderCopy(renderer,image, &srect, &drect);
    }
}

void Sprite::SetX(int x)
{
    drect.x = x;
}

void Sprite::SetY(int y)
{
    drect.y = y;
}

int Sprite::GetX()
{
    return drect.x;
}

int Sprite::GetY()
{
    return drect.y;
}
