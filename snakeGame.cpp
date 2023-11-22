#include "SnakeGame.h"

void SnakeGame::Setup()
{
    isGameOver = false;
    score = 0;

    width = 20; 
    height = 12;

    dir = STOP;
    
    snakeHeadX = width / 2;
    snakeHeadY = height / 2;

    srand(time(NULL));
    foodX = 1 + rand() % (width - 2);
    foodY = 1 + rand() % (height - 2);

    snakeTailX.resize(100);
    snakeTailY.resize(100);
}

void SnakeGame::ClearField()
{
    #ifdef _WIN32
        system("cls");
    #else 
        system("clear");
    #endif
}

void SnakeGame::Print()
{
    Sleep(60);
    ClearField();

    if(isGameOver)
    {
        std::cout << "\t\t!!!GAME OVER!!!" << std::endl;
        std::cout << std::endl << std::endl;
        std::cout << "Score: " << score;
        return;
    }

    //draw top border
    for(int i = 0; i < width + 2; i++)
    {
        std::cout << "-";
    }
    
    std::cout << std::endl;

    for(int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //draw left border
            if(j == 0)
            {
                std::cout << "|";
            }
            
            //draw snake head
            if (i == snakeHeadY && j == snakeHeadX)
            {
                std::cout << "S";
            }
            //draw food
            else if (i == foodY && j == foodX)
            {
                std::cout << "%";
            } 
            else 
            {
                bool isSnakeTailCoord = false;
                
                //draw snake tail
                for(int k = 0; k < snakeTailLength; k++)
                {
                    if (snakeTailX[k] == j && snakeTailY[k] == i)
                    {
                        std::cout << "s";
                        isSnakeTailCoord = true;
                    }
                }

                if(!isSnakeTailCoord)
                {
                   std::cout << " "; 
                }

                //draw right border
                if (j == width - 1)
                {
                    std::cout << "|";
                }  
            }
        }
        std::cout << std::endl;
    }

    //draw bottom border
    for(int i = 0; i < width + 2; i++)
    {
        std::cout << "-";
    }

    std::cout << std::endl << std::endl;
    std::cout << "Score: " << score;
    std::cout << std::endl << std::endl;
}

void SnakeGame::Input()
{
    #ifdef _WIN32
    if (_kbhit())
    {
        switch(_getch())
        {
            case 'w':
                dir = UP;
                break;
            case 'a':
                dir = LEFT;
                break;
            case 's':
                dir = DOWN;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 27:
                isGameOver = true;
                dir = STOP;
        }
    }
    #else
    if (getch() != ERR)
    {
        switch(getch())
        {
            case 'w':
                dir = UP;
                break;
            case 'a':
                dir = LEFT;
                break;
            case 's':
                dir = DOWN;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 27:
                isGameOver = true;
                dir = STOP;
        }
    }
    #endif
}

void SnakeGame::Logic()
{
    int prevX = snakeTailX[0];
    int prevY = snakeTailY[0];
    int prev2X, prev2Y;

    snakeTailX[0] = snakeHeadX;
    snakeTailY[0] = snakeHeadY;

    //extension Snake tail 
    for (int i = 1; i < snakeTailLength; i++)
    {
        prev2X = snakeTailX[i];
        prev2Y = snakeTailY[i];

        snakeTailX[i] = prevX;
        snakeTailY[i] = prevY;

        prevX = prev2X;
        prevY = prev2Y;
    }

    //turn snake head
    switch(dir)
    {
    case LEFT:
        snakeHeadX--;
        break;
    case RIGHT:
        snakeHeadX++;
        break;
    case UP:
        snakeHeadY--;
        break;
    case DOWN:
        snakeHeadY++;
        break;
    }

    //border teleport
    if (snakeHeadX >= width)
    {
        snakeHeadX = 0;
    } 
    else if (snakeHeadX < 0)
    {
        snakeHeadX = width - 1;
    }

    if (snakeHeadY >= height)
    {
        snakeHeadY = 0;
    } 
    else if(snakeHeadY < 0)
    {
        snakeHeadY = height - 1;
    }

    //check game over 
    for (int i = 0; i < snakeTailLength; i++)
    {
        if (snakeTailX[i] == snakeHeadX && snakeTailY[i] == snakeHeadY)
        {
            isGameOver = true;
        }
    }

    //eating food
    if (snakeHeadX == foodX && snakeHeadY == foodY)
    {
        snakeTailLength++;
        score++;

        //spawn new food
        srand(time(NULL));
        foodX = 1 + rand() % (width - 2);
        foodY = 1 + rand() % (height - 2);
    } 
}