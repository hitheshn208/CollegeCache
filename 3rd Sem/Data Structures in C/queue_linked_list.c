#include<stdio.h>
#include<stdlib.h>
#define MALLOC(ptr) ptr = (Node*)malloc(sizeof(Node));

typedef struct Node
{
        int data;
        struct Node* link;
}Node;

struct Node *front, *rear;

void addq(int item)
{
        if(rear == NULL)
        {
                MALLOC(rear);
                rear->data = item;
                rear->link = NULL;
                front = rear;
                return;
        }
        else
        {
                struct Node* temp;
                MALLOC(temp);
                temp->data = item;
                rear->link = temp;
                temp->link = NULL;
                rear = temp;
                return;

        }
}

void deleteq()
{
        if(front == NULL && rear == NULL)
        {
                printf("Queue Empty!!!\n");
        }
        else if(front == rear) //Both rear and front are pointing to the same node. These is only single node
        {
                rear = NULL;
                free(front);
                front = NULL;
                printf("Deleted a single node. Queue is now empty\n");
        }
        else
        {
                struct Node* temp;
                temp = front;
                front = front->link;
                free(temp);
                printf("Deleted a node from front\n");
        }
}

void display()
{
        if(front == NULL && rear == NULL)
        {
                printf("Queue is Empty...\n");

        }
        else
        {
                struct Node* track;
                track = front;
                printf("Queue elements are :\n front-->");
                while(track !=NULL )
                {
                        printf("| %d ", track->data);
                        track = track->link;
                }
                printf("|<--rear\n");
        }
        return;
}

void freeq()
{
        if(free == NULL && rear == NULL)
        {
                return;
        }
        else
        {
                struct Node *track;
                while(front != NULL)
                {
                        track = front;
                        front = front->link;
                        free(track);
                }
                printf("Memory freed\n");
        }
}

int main()
{
        front = NULL;
        rear = NULL;

        int choice;

        while(1)
        {
                printf("\n\n--Queue Linked List--\n");
                printf("1.Add node \n2.Delete node \n3.Display \n4.Exit \nEnter your choice : ");
                scanf("%d", &choice);
                int value;
                switch(choice)
                {
                        case 1:
                                printf("Enter the value to add : ");
                                scanf("%d", &value);
                                addq(value);
                                break;

                        case 2:
                                deleteq();
                                break;

                        case 3:
                                display();
                                break;

                        case 4:
                                printf("Exiting the program...");
                                return 0;

                        default : printf("Invalid choice");
                }
        }
}