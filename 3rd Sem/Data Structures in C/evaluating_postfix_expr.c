#include <stdio.h>
#include <stdlib.h>
#define MAX 20
char stack[MAX];
int top = -1;
char expr[MAX];
typedef enum {lparen, rparen, add, sub, divide, mul, mod, operand, eos} precedence;

void push(int op)
{
    if(top == MAX-1)
    {
        printf("Stack full!!");
        exit(1);
    }

    stack[++top] = op;
}

int pop()
{
    if(top == -1)
    {
        printf("Stack empty!!\n");
        exit(1);
    }

    return stack[top--];
}

precedence getToken(char *character, int *n)
{
    *character = expr[(*n)++];

    switch(*character)
    {
        case '+' : return add;
        case '-' : return sub;
        case '*' : return mul;
        case '/' : return divide;
        case '%' : return mod;
        case '\0': return eos;
        default : return operand;
    };
}

int evaluate()
{
    char character;
    int n=0;
    precedence token;
    token = getToken(&character, &n);
    int op1, op2;

    while(token != eos)
    {
        if(token == operand)
        {
            push(character - '0');
        }
        else
        {
            op2 = pop();
            op1 = pop();

            switch(token)
            {
                case add : push((op1 + op2));break;
                case sub : push((op1 - op2));break;
                case mul : push((op1)*(op2));break;
                case divide : if(op2 != 0)
                                    push( (op1/op2) );
                            else
                            {
                                printf("Divide by zero!!");
                                exit(1);
                            }
                            break;

                case mod : if(op2 != 0)
                                    push( (op1%op2) );
                            else
                            {
                                printf("Divide by zero!!");
                                exit(1);
                            }
                            break;
            }
        }

        token = getToken(&character, &n);

    }

    return pop();
}

int main()
{
    printf("Enter the postfix expression : ");
    scanf("%s", expr);
    printf("The solution of the postfix expression is : %d", evaluate());

}