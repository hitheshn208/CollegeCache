#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *arr;
    int n1=0,n2=0,choice;
    
    printf("Enter the number of elements : ");
    scanf("%d", &n1);

    arr = (int*)malloc(n1*sizeof(int)); // arr = [1][2][3].........[n1-1]

    printf("Enter the array elements\n");
    for( int i=0; i<n1 ; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Entered elements are :\n");
    for(int i=0; i<n1; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\nWanna add more elements??? \n1.Yes \n2.No \n");
    scanf("%d", &choice);

    if(choice == 1)
    {
        printf("How many more elements? : ");
        scanf("%d", &n2);
        arr = (int*)realloc(arr, (n1+n2)*sizeof(int));   //Re allocation to increase the size of array by n1
                                                        //New array is , arr = [1][2][3]....[n1-1] + ([n1][n1+1].....[n1+n2-1])<--- added space will be n2-n1
        printf("Enter the elements\n");
                                                        // Initial n1 = 3, arr = [0][1][2]
                                                        // After realloc n2 = 5, arr = [0][1][2] [3][4]
        for(int i = n1; i<(n2+n1); i++)
            scanf("%d", &arr[i]);

        printf("Final Array elements are : ");
        for(int i=0 ; i<(n2+n1) ; i++)
            printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;

}