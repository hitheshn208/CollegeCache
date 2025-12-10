#include<stdio.h>
#include<stdlib.h>
#define MALLOC(p,size) p = (Queue_structure*)malloc(size);

typedef struct
{
        int data;

}Queue_structure;

Queue_structure* queue;
int capacity = 3,front = 0, rear = 0;

void copy(int startpos, int endpos, Queue_structure newQueue[], int newstart)
{
        for(int i = startpos, j = newstart; i<endpos; i++,j++)
        {
                newQueue[j].data = queue[i].data;
        }
}

void createNewQueue()
{
        Queue_structure* newQueue;
        MALLOC(newQueue, 2*capacity*sizeof(Queue_structure));

        int start = (front+1)%capacity;
        if(start < 2)
                copy(start, start+capacity-1, newQueue, 0);
        else
        {
                copy(start, capacity, newQueue, 0);
                copy(0, rear+1, newQueue, capacity-start+1);
        }

        rear = capacity - 1;
        capacity *= 2;
        front = capacity-1;
        free(queue);
        queue = newQueue;
}

void addq()
{
        rear = (rear+1) % capacity;
        if(front == rear)
        {
                printf("Queue full\n Allocating Memory...\n");
                createNewQueue();
        }

        int item;
        printf("Enter the element : ");
        scanf("%d", &item);
        queue[rear].data = item;
        printf("Element added\n");
}


void deleteq()
{
        if(front == rear)
        {
                printf("Queue is empty!!\n");
                return;
        }
        front = (front+1) % capacity;
}

void display()
{
        if(front == rear)
        {
                printf("Queue is empty!!\n");
                return;
        }

        int i = front;
        do
        {
                i = (i+1)%capacity;
                printf("| %d ",queue[i].data);
        }while( i != rear);
        printf("|\n");
}

int main()
{
        MALLOC(queue, capacity*sizeof(Queue_structure));

        int choice = 4;

        while(1)
        {
                printf("\n==Queue Operation menu==\n");
                printf("1.Insert \n2.Delete \n3.Display \n4.Exit\n");
                scanf("%d", &choice);

                switch(choice)
                {
                        case 1 :addq(); break;
                        case 2 :deleteq(); break;
                        case 3 :display(); break;
                        case 4 :
                                printf("Exiting the program\n");
                                return 0;
                }
        }
}