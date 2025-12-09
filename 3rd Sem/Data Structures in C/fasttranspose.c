#include<stdio.h>
#include<stdlib.h>
typedef struct 
{
    int col, row, val;
}matrix;

void readSparse(matrix a[])
{
    int r,c, values;
    printf("Enter the number of rows and columns\n");
    scanf("%d %d", &r, &c);
    a[0].row = r;
    a[0].col = c;

    printf("Enter the total number of non zero elements \n");
    scanf("%d", &values);
    a[0].val = values;

    printf("Enter the row col and value\n");
    for(int i=1 ; i<=a[0].val; i++)
        scanf("%d %d %d", &a[i].row, &a[i].col, &a[i].val);
}

void fastTranspose(matrix a[], matrix b[])
{
    int start_pos[20], row_terms[20], j;

    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].val = a[0].val;

    for(int i=0; i<a[0].col; i++)
        row_terms[i] = 0;

    for(int i=1; i<=a[0].val; i++)
        row_terms[a[i].col]++;

    start_pos[0] = 1;

    for(int i=1; i<a[0].col; i++)
        start_pos[i] = start_pos[i-1] + row_terms[i-1];

    for(int i=1; i<=a[0].val; i++)
    {
        j = start_pos[a[i].col]++;
        b[j].row = a[i].col;
        b[j].col = a[i].row;
        b[j].val = a[i].val;
    }
}

void printMAtrix(matrix a[])
{
    printf("Row\tCol\tValue\n");

    for(int i = 0; i<=a[0].val; i++)
        printf("%d\t%d\t%d\n", a[i].row, a[i].col, a[i].val);

        printf("\n");
}

int main()
{
    matrix a[20], b[20];
    
    readSparse(a);
    printf("Original matrix\n");
    printMAtrix(a);

    fastTranspose(a,b);
    printf("Transpose of the matrix\n");
    printMAtrix(b);
}