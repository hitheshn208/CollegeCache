#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 20

typedef struct element{
    int data;
}element;

element heap[MAX_SIZE];
int n = 0;

void insert(int num)
{
    if(n == MAX_SIZE)
    {
        printf("Heap full");
        exit(EXIT_FAILURE);
    }

    int i = ++n;
    
    while( (i != 1) && heap[i/2].data < num)
    {
        heap[i].data = heap[i/2].data;
        i /= 2;
    }

    heap[i].data = num;
    return;
}

int delete()
{
    if(n == 0)
    {
        exit(0);
    }

    int deleted = heap[1].data;
    int temp = heap[n--].data;
    int parent = 1, child=2;

    while(child <= n)
    {
        if(child < n && heap[child].data < heap[child+1].data)
            child++;

        if(heap[child].data < temp)
            break;

        heap[parent].data = heap[child].data;
        parent = child;
        child *= 2; 
    }

    heap[parent].data = temp;

    return deleted;
}

int main()
{
    int a[] = {4,9,7,3,6,2};

    for(int i = 0; i<6; i++)
        insert(a[i]);

    for(int i = 0; i<6; i++)
        printf("%d ", delete());
}