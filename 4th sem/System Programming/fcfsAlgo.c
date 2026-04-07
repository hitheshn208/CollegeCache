#include<stdio.h>
#include<stdlib.h>

int main()
{
	int *bt, n, *ct;
	printf("Enter the number of processes : ");
	scanf("%d", &n);
	bt = (int*)malloc(n*sizeof(int));
	ct = (int*)malloc(n*sizeof(int));
	printf("Enter the burst time \n");
	for(int i = 0; i<n; i++)
	{
		printf("P%d : ", i+1);
		scanf("%d", &bt[i]);
	}	

	int totalTime = 0;
	for(int i = 0; i<n; i++){
		totalTime += bt[i];
		ct[i] = totalTime;
	}
	
	float totalWT = 0, totalTAT = 0;

	printf("Process\tAT\tBT\tCT\tTAT\tWT\n");
	for(int i = 0; i<n; i++)
	{
		int tat = ct[i] - 0;
		int wt = tat - bt[i];
		totalWT += wt;
		totalTAT += tat;
		printf(" P%d\t%d\t%d\t%d  \t%d\t%d\n", i+1,0, bt[i], ct[i], tat, wt);
	}

	printf("Average TAT : %f\n", totalTAT/n);
	printf("Average WT : %f\n", totalWT/n);
	return 0;
}
