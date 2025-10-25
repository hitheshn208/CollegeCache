#include <stdio.h>
#define MAX_QUEUE_SIZE 10

typedef struct 
{
    int data;
}Queue_structure;

int front = -1, rear = -1;

void AddQ (Queue_structure queue[], int item)
{
    if(rear == MAX_QUEUE_SIZE-1)
    {
        printf("The queue is full!!");
        return;
    }
    else
    {
        queue[++rear].data = item;
        printf("Element added");
        return;
    }
}

void DeleteQ (Queue_structure queue[])
{
    if(rear == front)
    {
        printf("Queue is empty!!!!");
        return;
    }
    else
    {
        front++;
        return; 
    }
}

void display(Queue_structure queue[])
{
    if(rear == front)
    {
        printf("Queue is empty!!");
        return;
    }
    else
    {
        printf("The elements in the queue are : \n");
        for(int i=front+1; i<=rear ; i++)
        {
            printf("| %d ", queue[i].data);
        }
        printf("|");
        return;
    }
}

int main()
{
    Queue_structure queue[MAX_QUEUE_SIZE];
    int toExit = 0, choice, item;

    while(!toExit)
    {
        printf("\n===================\n");
        printf("Queue operation menu\n");
        printf("1.Add\n");
        printf("2.Delete\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1 :
                printf("Enter the elements to add to queue : ");
                scanf("%d", &item);
                AddQ(queue, item);
                break;
            
            case 2 :
                DeleteQ(queue);
                break;
            
            case 3 :
                display(queue);
                break;

            case 4 :
                toExit = 1;
                break;

            default :
                printf("Invalid input");
        }
        printf("\n");
    };

    printf("Program terminated.\n");

    return 0;
}