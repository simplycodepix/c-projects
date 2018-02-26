#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define SIZE 10

const int width = 20;
const int height = 15;
int score;

struct Spaceships
{
    int x, y;
} spaceship;

struct Enemies
{
    int x, y;
} enemy1, enemy2;

struct Bullets
{
 int x, y;
} bullet;

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
    spaceship.y = 14;
    spaceship.x = 10;

    enemy1.x = rand() % width;
    enemy1.y = -(rand() % height);
    enemy2.x = rand() % width;
    enemy2.y = -(rand() % height);

}

void Bullet()
{
    bullet.x = spaceship.x;
    bullet.y = (spaceship.y - 1);
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
            else if(i == enemy1.y && j == enemy1.x)
                printf("o");
            else if(i == enemy2.y && j == enemy2.x)
                printf("o");
            else if(i == bullet.y && j == bullet.x)
                printf("*");
            else if(i == spaceship.y && j == spaceship.x)
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
            case 's':
                dir = SHOT;
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
            spaceship.x--;
            dir = STOP;
            break;
        case RIGHT:
            spaceship.x++;
            dir = STOP;
            break;
        case SHOT:
            Bullet();
            dir = STOP;
            break;
        case STOP:
            enemy1.y++;
            enemy2.y++;
            break;
        default:
            break;
    }


    if(spaceship.x <= 0)
    {
        spaceship.x = 1;
    }
    if(spaceship.x >= (width - 1))
    {
        spaceship.x = (width - 2);
    }

}