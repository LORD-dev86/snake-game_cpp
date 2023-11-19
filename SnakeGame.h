#include <iostream>
#include <conio.h>
#include <vector>
#include <windows.h>

class SnakeGame
{
    private:
        bool isGameOver;
        int wigth, height;
        int score;

        int snakeHeadX, snakeHeadY;
        int foodX, foodY;

        std::vector<int> snakeTailX, snakeTailY;
        int snakeTailLength;

        enum eDirection {
            STOP = 0,
            LEFT,
            RIGHT,
            UP,
            DOWN
        };
        
    public:
        bool getIsGameOver()
        {
            return isGameOver;
        }

        void Setup();
        void Print();
        void Input();
        void Logic();
};