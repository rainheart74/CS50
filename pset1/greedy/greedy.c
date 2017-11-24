/*
   Link to problem: https://docs.cs50.net/problems/greedy/greedy.html.
*/
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("O hai! ");
    double dollars;
    do
    {
        printf("How much change is owed?\n");
        dollars = get_double();
    }
    while (dollars <= 0);
    int cents = 100.0 * dollars;
    int quarters = cents / 25;
    cents = cents % 25;
    int tens = cents / 10;
    cents = cents % 10;
    int fives = cents / 5;
    cents = cents % 5;

    int coins = quarters + tens + fives + cents;
    printf("%i\n", coins);
    return 0;
}
