#include<stdio.h>
#include<stdlib.h>
#define MAX 20

typedef enum {rparen, operand, eos, operator} precedence;
char stack[MAX];
int top = -1;
char expr[MAX];

char pop()
{
    if(top == -1)
    {
        printf("\nThe Stack is empty!!\n");
        exit(1);
    }
    return stack[top--];
}

void push(char symbol)
{
    stack[++top] = symbol;
}

int precedenceChecker(char op)
{
    switch(op)
    {
        case '(':
        case ')': return 3;
        case '*':
        case '/':
        case '%': return 2;
        case '+':
        case '-': return 1;
    }
}

precedence getToken(char *symbol, int *n)
{
    *symbol = expr[(*n)++];

    switch(*symbol)
    {
        case ')' : return rparen;
        case '(' : 
        case '+' : 
        case '-' : 
        case '*' : 
        case '%' :
        case '/' : return operator;
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
            /*If the precedence of the operator in stack is greater than the operator to be pushed then, pop the stack until the operator in stack has less precedence or the stack is empty*/
            while( precedenceChecker(symbol) <= precedenceChecker(stack[top]) && stack[top]!='(' )
            {
                printf("%c", pop());

                if(top == -1)
                    break;
            }
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
    printf("Postfix expression is : ");
    postfix();
    printf("\n");
    return 0;
}