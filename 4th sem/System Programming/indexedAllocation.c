#include <stdio.h>
int main()
{
    int n, sb[10], m[10], b[10][10], x;
    printf("Enter the number of files: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        printf("\nEnter the index block of file-%d: ", i + 1);
        scanf("%d", &sb[i]);

        printf("Enter the number of blocks occupied by file-%d: ", i + 1);
        scanf("%d", &m[i]);

        printf("Enter the block numbers of file-%d:\n", i + 1);
        for(int j = 0; j < m[i]; j++)
        {
            printf("Block %d: ", j + 1);
            scanf("%d", &b[i][j]);
        }
    }
    printf("\n----------------------------------------\n");
    printf("File\tIndexBlock\tSize\n");
    printf("----------------------------------------\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\n", i + 1, sb[i], m[i]);
    }
    printf("\nEnter the file number to display details: ");
    scanf("%d", &x);
     printf("\nFile Number: %d\n", x);
    printf("Index Block: %d\n", sb[x - 1]);
    printf("File Size  : %d\n", m[x - 1]);
    printf("Blocks Occupied: ");
    for(int j = 0; j < m[x - 1]; j++)
    {
        printf("%d ", b[x - 1][j]);
    }

    printf("\n");
    return 0;
}
