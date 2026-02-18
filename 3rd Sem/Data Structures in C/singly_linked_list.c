#include<stdlib.h>
#include<stdio.h>
#define MALLOC(var) var = (LinkedList*)malloc(sizeof(LinkedList))

typedef struct LinkedList *linkpointer;
typedef struct LinkedList
{
    int data;
    linkpointer link;
}LinkedList;

void Displaychoice(linkpointer track)
{
    linkpointer i;
    i = track;

    if(track == NULL)
    {
        printf("List is empty!!!");
        return;
    }

    do
    {
        printf("| %d |-->", i->data);
        i = i->link;

    }while(i->link != NULL);

    return;
}

// linkpointer insertNode(int value, linkpointer front)
// {
//     linkpointer node;
//     MALLOC(node);

//     node->data = value;
//     node->link = front;
//     first = node;
// }

void insertion(linkpointer track, int pos)
{
    int value;
    printf("Enter the value to be inserted : \n");
    scanf("%d", &value);
    
    linkpointer temp;    //Creating a node
    MALLOC(temp);
    temp->data = value;

    if(pos == 1)
    {
        temp->link = track;            //Adding the node in the beginning of the linked list
        track = temp;
    }
    else if(pos == -1)
    {                                   //Adding the node in the end of the list
        linkpointer i;
        i = track;

        while(i->link != NULL)
        {
            i = i->link;
        }

        i->link = temp;
    }
    else
    {
        linkpointer i = track;
        linkpointer prev;
        while(pos-1)
        {
            prev = i;
            i = i->link;
            pos--;
        }

        temp->link = i;
        prev->link = temp;

    }
}

void InsertionChoice(linkpointer track)
{
    int choice;
    int toExit = 1;

    while(toExit)
    {
        printf("---Insert Option---\n");
        printf("1.Insert at beginning \n2.Insert at End \n3.Insert at specific position");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: toExit = 0;
                insertion(track, 1);
            
            case 2: toExit = 0;
                insertion(track, -1);

            case 3: toExit = 0;
                int pos;
                printf("Enter the position :");
                scanf("%d", &pos);
                insertion(track, pos);

            default : 
                printf("Enter valid option!!\n");
        }
    }

    
}

int main()
{
    linkpointer track = NULL;
    int choice;



    while(1)
    {
        printf("----Singly Linked list operation menu----\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: 
                InsertionChoice(track);

            case 2:
            case 3:
                Displaychoice(track);
            case 4: return 0;
        }
    }
    return 0;

}