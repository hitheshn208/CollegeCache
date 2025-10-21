#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *arr;
    int n = 10;

    arr = (int*)calloc(n, sizeof(int));

    if(arr ==NULL)
    {
        printf("Memory was not allocated\n");
        return 1;
    }

    for(int i=0; i<n; i++)
    {
        printf("%d\n", arr[i]);
    }

    free(arr);

    return 0;

}