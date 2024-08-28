#include <stdio.h>
#include <stdbool.h>

bool isParenthesesBalanced(char *);

void main ()
{

    char expression[1100];

    while (scanf(" %s", expression) != EOF)
    {

        if (isParenthesesBalanced(expression))
            printf("correct\n");
        else
            printf("incorrect\n");

    }

}

bool isParenthesesBalanced(char *str)
{

    short balance = 0;

    if (*str == ')')
        return false;

    while ((*str) && (balance >= 0))
    {
        if (*str == '(')
            balance++;

        if (*str == ')')
            balance--;

        str++;
    }

    return balance == 0;

}