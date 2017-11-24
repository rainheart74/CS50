/*
   Link to problem: https://docs.cs50.net/problems/credit/credit.html.
*/
#include <stdio.h>
#include <cs50.h>
#include <string.h>

string get_number(void);
bool check_number(string number);
bool check_valid(string number);
bool check_amex(string number);
bool check_mastercard(string number);
bool check_visa(string number);

int main(void)
{
    string number = get_number();

    bool is_valid = check_valid(number);
    if (!is_valid)
    {
        printf("INVALID\n");
        return 0;
    }
    bool is_amex = check_amex(number);
    if (is_amex)
    {
        printf("AMEX\n");
        return 0;
    }
    bool is_mastercard = check_mastercard(number);
    if (is_mastercard)
    {
        printf("MASTERCARD\n");
        return 0;
    }
    bool is_visa = check_visa(number);
    if (is_visa)
    {
        printf("VISA\n");
        return 0;
    }
    return -1;
}

bool check_valid(string number)
{
    int n = strlen(number);
    int sum1 = 0;
    for (int i = n - 2; i >= 0; i -= 2)
    {
        int digit = number[i] - '0';
        int doubled_digit = digit * 2;
        int tens = doubled_digit / 10;
        int ones = doubled_digit % 10;
        sum1 += tens + ones;
    }
    int sum2 = 0;
    for (int i = n - 1; i >= 0; i -= 2)
    {
        int digit = number[i] - '0';
        sum2 += digit;
    }
    int sum = sum1 + sum2;
    return sum % 10 == 0;
}

bool check_amex(string number)
{
    int length = strlen(number);
    if (length == 15)
    {
        if (number[0] == '3' && (number[1] == '4' || number[1] == '7'))
        {
            return true;
        }
    }
    return false;
}

bool check_mastercard(string number)
{
    int length = strlen(number);
    if (length == 16)
    {
        if (number[0] == '5' && (number[1] >= '1' && number[1] <= '5'))
        {
            return true;
        }
    }
    return false;
}

bool check_visa(string number)
{
    int length = strlen(number);
    if (length == 13 || length == 16)
    {
        if (number[0] == '4')
        {
            return true;
        }
    }
    return false;
}

string get_number(void)
{
    string number;
    do
    {
        printf("Number: ");
        number = get_string();
    }
    while (!check_number(number));
    return number;
}

bool check_number(string number)
{
    int length = strlen(number);
    if (length == 0)
    {
        return false;
    }
    for (int i = 0; i < length; i++)
    {
       if (number[i] < '0' || number[i] > '9')
       {
           return false;
       }
    }
    return true;
}