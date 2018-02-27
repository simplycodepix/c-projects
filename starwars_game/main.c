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
    char look;
} spaceship;

struct Enemies
{
    int x, y;
    char look;
} enemy1, enemy2;

struct Bullets
{
 int x, y;
 char look;
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
    spaceship.look = '_';

    bullet.x = spaceship.x;
    bullet.y = (spaceship.y - 1);
    bullet.look = '*';

    enemy1.look = enemy2.look = 'o';
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
            else if(i == bullet.y && j == bullet.x)
                printf("%c", bullet.look);
            else if(i == spaceship.y && j == spaceship.x)
            {
                printf("%c", spaceship.look);
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
            bullet.y--;
            break;
        case STOP:
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