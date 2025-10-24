#include<stdio.h>
#include<stdlib.h>
#define MALLOC(pointer) (pointer*)malloc(1*sizeof(pointer));
// #define REALLOC(pointer,size) 

typedef struct 
{
    int data;
}stackStructure;

void push(stackStructure stack[], int *top, int *capacity)
{
    if(*top == *capacity-1)
    {
        stack = (stackStructure*)realloc(stack, sizeof(stackStructure));
        (*capacity) *= 2;
    }

    int a;
    printf("Enter the element to push into the stack : ");
    scanf("%d", &a);
    stack[++(*top)].data = a;
    printf("Pushed the element.\n");
}

void pop(int *top)
{
    if(*top == -1)
    {
        printf("Stack is Empty\n");
        printf("Address of top : %d \n", top);
        return;
    }

    (*top)--;
    printf("Popped the top element.\n");
}

void display(stackStructure stack[], int top, int capacity)
{
    if(top == -1)
    {
        printf("Stack is empty !!!\n");
        return;
    }

    printf("Stack Elements are : \n");
    for(int i=top; i>-1; i--)
    {
        printf("|     %d     |\n", stack[i]);
        printf("--------------\n");
    }

}


int main()
{
    stackStructure *stack;  
    int top = -1;
    int capacity = 1;
    int choice = 4;
    
    stack  = MALLOC(stackStructure);

    if(stack == NULL)
    {
            printf("MEMORY WAS NOT ALLOCATED\n");
            return 0;
    }

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
                    push(stack, &top, &capacity);
                    break;

            case 2: 
                    pop(&top);
                    break;

            case 3: 
                    display(stack, top, capacity);
                    break;

            case 4: 
                    toExit = 1;
                    break;

            default : printf("Invalid input\n");
        }
    }
    free(stack);

    return 0;
}