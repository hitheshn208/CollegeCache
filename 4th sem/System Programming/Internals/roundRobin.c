#include<stdlib.h>
#include<stdio.h>

int main()
{
	int n;
	printf("Enter the number processes : ");
	scanf("%d", &n);
	int pid[n], at[n], bt[n], ct[n], rt[n], tat[n], wt[n];
	for(int i = 0; i < n; i++)
	{
		pid[i] = i+1;
		printf("\nEnter the arival time of P%d : ", pid[i]);
		scanf("%d", &at[i]);
		printf("Enter the burst time of P%d : ", pid[i]);
		scanf("%d", &bt[i]);
		rt[i] = bt[i];
	}

	int completed = 0, time = 0, tq = 0;
	printf("\nEnter the time quantum : ");
	scanf("%d", &tq);

	while(completed < n)
	{
		int found = 0;

		for(int i = 0; i < n; i++)
		{
			if(at[i] <=time && rt[i] > 0)
			{
				found = 1;
				if(rt[i] > tq){
					rt[i] -= tq;
					time += tq;
				}
				else{
					time += rt[i];
					rt[i] = 0;
					ct[i] = time;
					completed++;
				}
			}
		}

		if(!found)
			time++;
	}

	float avgtat, avgwt;

	for(int i = 0; i < n; i ++)
	{
		tat[i] = ct[i] - at[i];
		wt[i] = tat[i] - bt[i];
		avgtat += tat[i];
		avgwt += wt[i];
	}

	printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
	printf("-----------------------------------------------\n");
	for(int i = 0; i < n; i++)
		printf("%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);

	printf("\nAverage Turnaround time = %.2f", avgtat/n);
	printf("\nAverage waiting time = %.2f", avgwt/n);

	return 0;
}
