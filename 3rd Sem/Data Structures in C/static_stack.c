#include <stdio.h>
#define MAX_SIZE  10

typedef struct 
{
    int data;
}Stack_structure;

void push(Stack_structure stack[], int *top)
{
    if(*top == MAX_SIZE)
    {
        printf("Stack Full!!\n");
        return;
    }
    else
    {
        printf("Enter the element to push into the stack : ");
        scanf("%d", &stack[++(*top)].data);
        printf("Pushed the element into the stack\n");
        return;
    }
}

void pop( int *top)
{
    if(*top == -1)
    {
        printf("Stack is Empty!!\n");
    }
    else
    {
        *top--;
    }
}

void display(Stack_structure stack[], int *top)
{
    if(*top == -1)
    {
        printf("Stack is Empty. Nothing is there to print :(\n");
    }
    else
    {
        printf("STACK ELEMENTS\n");
        for(int i= *top; i>-1; i--)
        {
            printf("|     %d     |\n", stack[i].data);
            printf("--------------\n");
        }
        return;
    }
}

int main()
{
    Stack_structure stack[MAX_SIZE];
    int top = -1;
    int choice;
    int toExit = 0;

    while(!toExit)
    {
        printf("\n======================\n");
        printf("Stack Operation Menu\n");
        printf("1.Push \n2.Pop \n3.Display \n4.Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: 
                    push(stack, &top);
                    break;

            case 2: 
                    pop(&top);
                    break;

            case 3: 
                    display(stack, &top);
                    break;

            case 4: 
                    toExit = 1;
                    break;

            default : printf("Invalid input\n");
        }
    }

    printf("\nSuccessfully exited the loop and program\n");
    return 0;
}







// typedef struct
// {
//     int arr[10];
//     int top;
// }Stack;

// Stack stack;

// void push(Stack *stack)
// {
//     if(stack->top == 10)
//     {
//         printf("Stack is full!!!");
//         return;
//     }
//     else
//     {
//         printf("Enter the element to push into the stack : ");
//         scanf("%d", &stack->arr[stack->top]);
//         stack->top++;
//         return;
//     }
// }

// void pop(Stack *stack)
// {
//     if(stack->top == 0)
//     {
//         printf("Stack is empty!!");
//         return;
//     }
//     else
//     {
//         stack->top--;
//         printf("\nPoped the top element\n");
//         return;
//     }
// }

// void display(Stack *stack)
// {
//     if(stack->top == 0)
//     {
//         printf("Stack is Empty, Nothing is there to print :( \n");
//         return;
//     }
//     else
//     {
//         printf("__STACK ELEMENTS__\n");
//         for(int i = stack->top - 1 ; i >= 0 ; i--)
//         {
//             printf("|     %d     |\n", stack->arr[i]);
//             printf("--------------\n");
//         }

//         return;
//     }
// }

// int main()
// {
//     stack.top = 0;

//     int choice;
//     int toExit = 0;

//     while(!toExit)
//     {
//         printf("\n\nStack Operation Menu\n");
//         printf("1.Push \n2.Pop \n3.Display \n4.Exit\n");
//         printf("Enter your choice : ");
//         scanf("%d", &choice);

//         switch(choice)
//         {
//             case 1: 
//                     push(&stack);
//                     break;

//             case 2: 
//                     pop(&stack);
//                     break;

//             case 3: 
//                     display(&stack);
//                     break;

//             case 4: 
//                     toExit = 1;
//                     break;

//             default : printf("Invalid input");
//         }
//     }

//     printf("\nSuccessfully exited the loop and program\n");
//     return 0;
// }