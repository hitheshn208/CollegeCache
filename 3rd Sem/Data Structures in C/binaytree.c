#include<stdio.h>
#include<stdlib.h>

typedef struct node* nodepointer;
typedef struct node
{
    int data;
    nodepointer lchild, rchild;
}node;

nodepointer root;

void insertNode(int ele)
{
    if(root == NULL)
    {
        root  = (nodepointer)malloc(sizeof(node));
        root->data = ele;
        root->lchild = NULL;
        root->rchild = NULL;
        return; 
    }
    nodepointer temp, track;
    temp = (nodepointer)malloc(sizeof(node));
    temp->data = ele;
    temp->lchild = NULL;
    temp->rchild = NULL;
    track = root;
    while(track != NULL)
    {
        if(ele > track->data)
        {
            if(!(track->rchild))
            {
                track->rchild = temp;
                break;
            }
            else
                track = track->rchild;
        }
        else if(ele < track->data)
        {
            if(!(track->lchild))
            {
                track->lchild = temp;
                break;
            }
            else
                track = track->lchild;
        }
    }

    return;
}

void inorder(nodepointer ptr)
{
    if(ptr)
    {
        inorder(ptr->lchild);
        printf("%d ", ptr->data);
        inorder(ptr->rchild);
    }
}

void preorder(nodepointer ptr)
{
    if(ptr)
    {
        printf("%d ", ptr->data);
        preorder(ptr->lchild);
        preorder(ptr->rchild);
    }
}

void postorder(nodepointer ptr)
{
    if(ptr)
    {
        postorder(ptr->lchild);
        postorder(ptr->rchild);
        printf("%d ", ptr->data);
    }
}

int main()
{
    root = NULL;
    int n, ele;
    printf("Enter the number of Nodes : ");
    scanf("%d", &n);
    printf("Enter the elements :\n");

    for(int i = 0; i<n ; i++) 
    {
        scanf("%d", &ele);
        insertNode(ele);
    }

    printf("Binary tree created\n :");
    printf("Inorder : ");
    inorder(root);
    printf("\n");
    printf("Preorder : ");
    preorder(root);
    printf("\n");
    printf("Inorder : ");
    postorder(root);
}