#include <stdio.h>
#include <stdlib.h>

#define IS_FULL(ptr) (!(ptr))
#define IS_EMPTY(ptr) ((ptr)->rlink == ptr)

typedef struct {
    int key;       // element as per textbook
} element;

typedef struct node *nodePointer;

typedef struct node {
    nodePointer llink;
    element data;
    nodePointer rlink;
} node;

//---------------------------------------------
// INSERT: textbook exact function
//---------------------------------------------
void dinsert(nodePointer node, nodePointer newnode)
{
    newnode->llink = node;
    newnode->rlink = node->rlink;
    node->rlink->llink = newnode;
    node->rlink = newnode;
}

//---------------------------------------------
// DELETE: textbook exact function
//---------------------------------------------
void ddelete(nodePointer head, nodePointer deleted)
{
    if (deleted == head) {
        printf("Deletion of head node not permitted.\n");
        
        return;
    }

    deleted->llink->rlink = deleted->rlink;
    deleted->rlink->llink = deleted->llink;
    free(deleted);
}

//---------------------------------------------
// DISPLAY: forward traversal
//---------------------------------------------
void display(nodePointer head)
{
    nodePointer temp = head->rlink;

    if (IS_EMPTY(head)) {
        printf("List is empty.\n");
        return;
    }

    printf("List contents: ");
    while (temp != head) {
        printf("%d ", temp->data.key);
        temp = temp->rlink;
    }
    printf("\n");
}

//---------------------------------------------
// MAIN PROGRAM
//---------------------------------------------
int main()
{
    nodePointer head = (nodePointer)malloc(sizeof(node));
    if (IS_FULL(head)) {
        printf("Memory full\n");
        exit(1);
    }

    // initialize empty circular list with head node
    head->llink = head;
    head->rlink = head;

    int choice;
    element item;
    nodePointer temp, ptr;

    while (1) {
        printf("\n--- DOUBLY LINKED LIST MENU ---\n");
        printf("1. Insert node\n");
        printf("2. Delete node\n");
        printf("3. Display list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            printf("Enter key to insert: ");
            scanf("%d", &item.key);

            temp = (nodePointer)malloc(sizeof(node));
            if (IS_FULL(temp)) {
                printf("Memory full\n");
                exit(1);
            }

            temp->data = item;

            // Insert after head (at beginning)
            dinsert(head, temp);
            break;

        case 2:
            if (IS_EMPTY(head)) {
                printf("List is empty. Cannot delete.\n");
                break;
            }

            printf("Enter key to delete: ");
            scanf("%d", &item.key);

            ptr = head->rlink;
            while (ptr != head && ptr->data.key != item.key)
                ptr = ptr->rlink;

            if (ptr == head)
                printf("Key not found.\n");
            else
                ddelete(head, ptr);

            break;

        case 3:
            display(head);
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}