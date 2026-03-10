#include <stdio.h>
int main() 
{
    int n;
    int start[10], length[10];
    char name[10][20];

    printf("Enter the number of files: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) 
  {
        printf("\nEnter file name: ");
        scanf("%s", name[i]);

        printf("Enter starting block: ");
        scanf("%d", &start[i]);

        printf("Enter length of file: ");
        scanf("%d", &length[i]);
    }

    printf("\n-----------------------------------------------\n");
    printf("File\tStart\tLength\tAllocated Blocks\n");
    printf("-----------------------------------------------\n");

    for (int i = 0; i < n; i++) 
{
        printf("%s\t%d\t%d\t", name[i], start[i], length[i]);

        for (int b = start[i]; b < start[i] + length[i]; b++) {
            printf("%d ", b);
        }
        printf("\n");
    }

    return 0;
}
