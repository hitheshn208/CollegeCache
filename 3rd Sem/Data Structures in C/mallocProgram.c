#include<stdlib.h>
#include<stdio.h>


int main()
{
    int *arr;
    int n;
    printf("Enter the size of the array : ");
    scanf("%d", &n);
    arr = (int*)malloc(n * sizeof(int));
    if(arr == NULL)
    {
        printf("Memory was not allocated!!");
        return 1;
    }

    printf("Enter the elements into the array\n");

    for(int i=0 ; i<n; i++)
        scanf("%d", &arr[i]);

        printf("The elements in the array are :\n");

    for(int i=0;i<n;i++)
        printf("%d\n", arr[i]);

    free(arr);

     return 0;
}