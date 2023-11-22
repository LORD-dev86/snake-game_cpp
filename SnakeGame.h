#include <iostream>
#include <vector>
#include <ctime>

#ifdef _WIN32
#include <conio.h>
#include <windows.h>
#else 
#include <cstdlib>
#include <ncurses>
#endif

#ifndef SNAKEGAME_H
#define SNAKEGAME_H
class SnakeGame
{
    private:
        bool isGameOver;
        int width, height;
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
        eDirection dir;
        
    public:
        bool getIsGameOver()
        {
            return isGameOver;
        }
        
        int getGameScore()
        {
            return score;
        }

        void Setup();
        void ClearField();
        void Print();
        void Input();
        void Logic();
};
#endif