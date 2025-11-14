#include<stdio.h>
#include<stdlib.h>
#define MALLOC(p,s) p = (Queue_structure*)malloc(s)

typedef struct
{
    int data;
}Queue_structure;

void copy(int a, int b, int c, Queue_structure **oldqueue, Queue_structure *newqueue)
{
    int i = a;
    while(i<b)
    {
        newqueue[c].data = (*oldqueue)[i].data;
        c++;
        i++;
    }
}

void queueFull(Queue_structure **queue, int *r, int*f, int *c)
{
    int rear = *r, front = *f,  capacity = *c;

    Queue_structure *newQueue;

    MALLOC(newQueue, 2*(capacity)*sizeof(Queue_structure));
    if(newQueue == NULL)
    {
        printf("Memory not allocated to new queue \n");
        exit(0);
    }
    
    int start = (front + 1) % capacity;

    if(start < 2)
    {
        copy(start, capacity, 0, queue, newQueue);
    }
    else
    {
        copy(start, capacity, 0,  queue, newQueue); //first arg : from where to copy ; second arg : till where to copy ( here capacity -1) ; third arg : which position to copy to of newqueue
        copy(0, rear+1 , capacity-start, queue, newQueue);
    }

    *c = 2*(*c); //double the capacity
    *r = capacity - 2; // points to the last element , subtracted 2 because there was an empty field in old queue;
    *f = *c - 1;
    free(queue);
    *queue = newQueue;
    newQueue = NULL;
}


void addQ(Queue_structure **queue, int *rear, int*front, int *capacity)
{
    int temp;
    *rear = (*rear + 1) % (*capacity);

    if(*front == *rear)
    {
        printf("Queue has filled allocating more memory...\n");
        (*rear)--;
        queueFull(queue, rear, front, capacity);
        printf("Capacity : %d , rear : %d , front : %d\n", *capacity, *rear, *front);
        *rear = (*rear + 1) % (*capacity);
    }

    printf("Enter the element to enter into the queue : ");
    scanf("%d", &temp);
    (*queue)[*rear].data = temp;
    return; 
}

void deleteQ(Queue_structure *queue, int *front, int *rear, int capacity)
{
    if(*front == *rear)
    {
        printf("Queue is empty !!\n");
    }
    else
    {
        *front = (*front + 1) % capacity;
    }

}

void display(Queue_structure *queue, int front, int rear, int capacity)
{
    int i = front;
    if(rear == front)
    {
        printf("Queue is empty nothing to print\n");
        return;
    }
    else
    {
        printf("Queue elements are : ");
        
        do
        {
            i = ( i+1 ) % capacity;
            printf("| %d ", queue[i]);

        }while( i != rear);
        printf("|\n");
        return;
    }
}


int main()
{
    int front = 0, rear = 0, capacity = 3;
    Queue_structure *queue;
    MALLOC(queue, capacity*sizeof(Queue_structure));

    if(queue == NULL)
    {
        printf("Memory not allocated!!\n");
        return 0;
    }
    int toExit = 0, choice;

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
                addQ(&queue, &rear, &front, &capacity);
                break;
            
            case 2 :
                deleteQ(queue, &front, &rear, capacity);
                break;
            
            case 3 :
                display(queue, front, rear, capacity);
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

    free(queue);

    return 0;
      

}