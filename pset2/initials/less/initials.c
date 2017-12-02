/*
   Link to problem: https://docs.cs50.net/problems/initials/less/initials.html.
*/
#include <stdio.h>
#include <cs50.h>
#include <string.h>

char to_uppercase(char letter);

int main(void)
{
    string name = get_string();
    printf("%c", to_uppercase(name[0]));
    for (int i = 1, n = strlen(name); i < n; i++)
    {
        if (name[i - 1] == ' ')
        {
            printf("%c", to_uppercase(name[i]));
        }
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
