#include "SnakeGame.h"

int main()
{   
    SnakeGame game;
    game.Setup();

    while(!game.getIsGameOver())
    {
        game.Print();
        game.Input();
        game.Logic();  
    }

    getch();

    return 0;
}