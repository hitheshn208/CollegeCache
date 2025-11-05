#include<stdio.h>
#include<stdlib.h>
#define MAX 20

typedef enum {lparen, rparen, add, sub, divide, mul, mod, operand, eos, operator} precedence;
char stack[MAX];
int top = -1;
char expr[MAX];

char pop()
{
    if(top == -1)
    {
        printf("the Stack is full!!\n");
        exit(1);
    }
    return stack[top--];
}

void push(char symbol)
{
    stack[++top] = symbol;
}

precedence getToken(char *symbol, int *n)
{
    *symbol = expr[(*n)++];

    switch(*symbol)
    {
        case ')' : return rparen;
        case '(' : return lparen;
        case '+' : return add;
        case '-' : return sub;
        case '*' : return mul;
        case '/' : return divide;
        case '\0' : return eos;
        default : return operand;
    }
}

void postfix()
{
    char symbol;
    int n = 0 ;
    precedence token = getToken(&symbol, &n);

    while(token != eos)
    {
        if(token == operand)
        {
            printf("%c", symbol);
        }
        else if(token == rparen)
        {
            while(stack[top] != '(')
            {
                printf("%c", pop());
            }
            pop();
        }
        else
        {
            push(symbol);
        }

        token = getToken(&symbol, &n);
    }

    if(top != -1)
    {
        while(top >= 0)
        {
            printf("%c", pop());
        }
    }

    return;
}

int main()
{
    printf("Enter the infix expression : ");
    scanf("%s", expr);
    postfix();

    return 0;
}