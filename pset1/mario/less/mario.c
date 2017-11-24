/*
   Link to problem: https://docs.cs50.net/problems/mario/less/mario.html.
*/
#include <stdio.h>
#include <cs50.h>

int get_height();
void print_pyramide(int height);

int main(void)
{
    int height = get_height();
    print_pyramide(height);
    return 0;
}

int get_height()
{
    int height;
    do
    {
        printf("Height: ");
        height = get_int();
    }
    while (height < 0 || height > 23);
    return height;
}

void print_pyramide(int height)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < height - 1 - i; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < i + 2; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}