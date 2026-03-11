#include<stdio.h>
#include<stdlib.h>

int sort(const void* a, const void* b)
{
	int x = *(int*)a;
	int y = *(int*)b;

	if(x > y)
		return 1;
	else if( x < y)
		return -1;
	else 
		return 0;
}

int main()
{
	int *bt, *ct;
	int *process;
	int n;
	printf("Enter the number of the processes : ");
	scanf("%d", &n);
	bt = (int*)malloc(n*sizeof(int));
	process = (int*)malloc(n*sizeof(int));
	printf("Enter Burst times of the process \n");

	for(int i = 0; i < n; i++)
	{
		printf("P%d : ", i+1);
		scanf("%d", &bt[i]);
		process[i] = bt[i];
	}

	qsort(bt, n, sizeof(int), sort);
	for(int i = 0; i<n; i++)
		printf("%d", bt[i]);

	return 0;
}
