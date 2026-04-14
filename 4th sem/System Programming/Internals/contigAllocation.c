#include<stdio.h>

int main()
{
	int n;
	printf("Enter the number of files : ");
	scanf("%d", &n);
	int start[n], length[n];
	char name[n][10];

	for(int i = 0; i < n ; i++)
	{
		printf("\nEnter the name of the file%d", (i+1));
		scanf("%s",name[i]);
		printf("Enter the starting block : ");
		scanf("%d", &start[i]);
		printf("Enter the Length of the file : ");
		scanf("%d", &length[i]);
	}

	printf("-----------------------------------------------\n");
	printf("File\tStart\tLength\tAllocated Blocks\n");
	printf("-----------------------------------------------\n");
	
	for(int i = 0; i<n; i++)
	{
		printf("%s\t%d\t%d\t", name[i], start[i], length[i]);
		for(int j = start[i]; j < start[i] + length[i]; j++)
			printf("%d ", j);
		printf("\n");
	}
	
	return 0;
}
