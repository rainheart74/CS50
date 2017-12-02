/*
   Link to problem: https://docs.cs50.net/problems/initials/less/initials.html.
   This solution uses argc and argv, explained in lecture video.
*/
#include <stdio.h>
#include <cs50.h>
#include <string.h>

char to_uppercase(char letter);

int main(int argc, string argv[])
{
    for (int i = 1; i < argc; i++)
    {
        char big_letter = to_uppercase(argv[i][0]);
        printf("%c", big_letter);
    }
    printf("\n");
    return 0;
}


char to_uppercase(char letter)
{
    if (letter >= 'A' && letter <= 'Z')
    {
        return letter;
    }
    else
    {
        return (char)(letter - 32);
    }
}
