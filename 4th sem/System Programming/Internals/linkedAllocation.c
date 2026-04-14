#include<stdlib.h>
#include<stdio.h>
int main()
{
	int n;
	printf("Enter the number of files : ");
	scanf("%d", &n);
	int start[n], end[n], count[n], blocks[n][10];

	for(int i = 0; i < n; i++)
	{
		printf("Enter the start block of the file-%d : ", (i+1));
		scanf("%d", &start[i]);
		printf("Enter the end block of the file-%d : ", (i+1));
		scanf("%d", &end[i]);
		printf("Enter the number of blocks used by the file-%d : ", (i+1));
		scanf("%d", &count[i]);
		printf("Enter the linked blocks : ");
		for(int j = 0; j < count[i]; j++)
			scanf("%d", &blocks[i][j]);
	}
	printf("File\tstart\tend\tBlocks\n");
	for(int i = 0 ; i < n; i++){
		printf("%d\t%d\t%d\t", (i+1), start[i], end[i]);
		for(int j = 0; j < count[i]; j++)
			printf("%d ", blocks[i][j]);
		printf("\n");
	}

	int file;
	printf("Enter the file number to disaply it's chain : "); 
	scanf("%d", &file);


	printf("Following blocks are allocated for the file-%d", file);
	for(int i = 0; i < count[file-1]; i++)
		printf("%d -> ", blocks[file-1][i]);
	printf("NULL\n");
	return 0;
}

