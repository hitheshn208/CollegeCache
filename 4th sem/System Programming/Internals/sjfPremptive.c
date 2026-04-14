#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n;
	printf("Enter the number of processes : ");
	scanf("%d", &n);

	int pid[n], at[n], bt[n], ct[n], rt[n], tat[n], wt[n];

	for(int i = 0; i < n; i++)
	{
		printf("\nEnter the Arrival time of P%d : ", (i+1));
		scanf("%d", &at[i]);
		printf("Enter the Burst time of P%d : ", (i+1));
		scanf("%d", &bt[i]);
		rt[i] = bt[i];
	}

	int min, pos, index, completed = 0, time = 0;

	while(completed < n)
	{
		min = 9999;
		pos = -1;

		for( index = 0; index<n; index++)
		{
			if(at[index] <= time && rt[index] > 0 && rt[index] < min)
			{
				min = rt[index];
				pos = index;
			}
		}

		if(pos == -1)
			time++;
		else
		{
			rt[pos]--;
			time++;
			if(rt[pos] == 0)
			{
				ct[pos] = time;
				completed++;
			}
		}
	}

	float avgwt=0, avgtat=0;
	for(int i = 0; i<n; i++)
	{
		tat[i] = ct[i] - at[i];
		wt[i] = tat[i] - bt[i];

		avgtat = avgtat + (float)tat[i];
		avgwt = avgwt + (float)wt[i];
	}

	avgtat /= n;
	avgwt /= n;

	printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
	printf("-------------------------------------------------------\n");

	for(int i = 0; i < n; i++)
		printf("P%d\t%d\t%d\t%d\t%d\t%d\n", (i+1), at[i], bt[i], ct[i], tat[i], wt[i]);

	return 0;
}

