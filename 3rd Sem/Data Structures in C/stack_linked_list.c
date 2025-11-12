#include<stdio.h>
#include<stdlib.h>
#define MALLOC(ptr) ptr = (linkpointer)malloc(sizeof(node))

typedef struct node* linkpointer;
typedef struct node
{
    int data; 
    linkpointer link;
}node;

linkpointer top;


void push(int item)
{
    linkpointer temp;
    MALLOC(temp);
    temp->data = item;
    temp->link = top;
    top = temp;
    return;
}

void pop()
{
    if(top->link == NULL)
    {
        printf("Stack is Empty!!!");
        return;
    }
    linkpointer temp;
    temp = top;
    top = temp->link;
    free(temp);
}

void display()
{
    if(top->link == NULL)
    {
        printf("Stack is Empty!!!");
        return;
    }

    linkpointer track;

    for(track = top; track->link != NULL; track = track->link)
    {
        printf("[ %d ]\n", track->data);
    }
}

void freeStack()
{
    linkpointer temp;
    
    while(top->link!=NULL)
    {
        temp = top;
        top = top->link;
        free(temp);
    }

    free(top);
    printf("Freed the memory\n");
}

int main()
{
    MALLOC(top);
    top->link = NULL;
    int choice = 4;
    while(1)
    {
        printf("\n\n==Stack Linked List==\n");
        printf("1.Insert \n2.Delete \n3.Display \n4.Exit \nEnter your choice : ");
        scanf("%d", &choice);
        int item;
        
        switch(choice)
        {
            case 1 : 
                    printf("Enter the element to push : ");
                    scanf("%d", &item);
                    push(item);
                    break;

            case 2 :
                    pop();
                    break;
                    
            case 3 :
                    display();
                    break;

            case 4 :freeStack();
                    printf("Exiting the program...\n");
                    return 0;
        }
    }    
}