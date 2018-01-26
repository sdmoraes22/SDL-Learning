#include "main.h"

int main(int argc, char* args[])
{
    Main* gamemain = new Main(800, 600) ;
    gamemain->GameLoop();
    delete gamemain;
    return 0;
}
