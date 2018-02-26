#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define SIZE 10

const int width = 20;
const int height = 15;
int x = 10, y = 14, score;

enum eDirection { STOP, LEFT, RIGHT, SHOT } dir;
int gameOver;

void Setup();
void Bullet();
void Draw();
void Input();
void Logic();

int main(void)
{
    Setup();
    while(!gameOver)
    {
        Draw();
        Input();
        Logic();
        // Sleep(10);
    }
    return 0;
}

void Setup()
{
    gameOver = 0;
}

void Bullet()
{

}

void Draw()
{
    system("cls");
    for(int i = 0; i < width; i++)
        printf("#");
    printf("\n");

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            if(j == 0 || j == (width - 1))
                printf("#");
            else if(i == y && j == x)
            {
                printf("_");
            }
            else
                printf(" ");

        }
        printf("\n");
    }

    for(int i = 0; i < width; i++)
        printf("#");
    printf("\n");
}

void Input()
{

    if(_kbhit())
    {
        switch(_getch())
        {
            case 'a':
                dir = LEFT;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 'x':
                gameOver = 1;
                break;
        }
    }

}

void Logic()
{

    switch(dir)
    {
        case LEFT:
            x--;
            dir = STOP;
            break;
        case RIGHT:
            x++;
            dir = STOP;
            break;
        default:
            break;
    }

    if(x <= 0)
    {
        x = 1;
    }
    if(x >= (width - 1))
    {
        x = (width - 2);
    }

}