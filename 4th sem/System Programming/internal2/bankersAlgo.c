#include<stdio.h>

int main()
{
	int n,m;

	printf("Enter the number of the processes :");
	scanf("%d", &n);
	printf("Enter the number of resources : ");
	scanf("%d", &m);

	int alloc[n][m], max[n][m], need[n][m], avail[m];

	printf("Enter the allocation matrix : \n");
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			scanf("%d", &alloc[i][j]);

	printf("Enter the max matrix : \n");
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			scanf("%d", &max[i][j]);

	printf("Enter the avaliable reaources : ");
	for(int i = 0; i < m; i++)
		scanf("%d", &avail[i]);

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			need[i][j] = max[i][j] - alloc[i][j];

	int finished[n];
	int safeSeq[n];
	for(int i = 0; i < n; i++)
	{
		finished[i] = 0;
		safeSeq[i] = 0;
	}
	int count = 0;

	while(count < n)
	{
		int found = 0;

		for(int i = 0; i < n; i++)
		{
			if(finished[i] == 0)
			{
				int possible = 1;

				for(int j = 0; j < m; j++)
				{
					if(need[i][j] > avail[j])
					{
						possible = 0;
						break;
					}
				}

				if(possible)
				{
					for(int j = 0; j < m; j++)
						avail[j] += alloc[i][j];
					
					safeSeq[count] = i;
					count++;
					finished[i] = 1;

					found = 1;
				}
			}
		}

		if(!found)
			break;
	}

	if(count == n)
	{
		printf("System is in safe sequesnce \n");
		printf("Safe sequence : ");
		for(int i = 0; i < n; i++)
			printf("%d ", safeSeq[i]);
		printf("\n");
	}else{
		printf("System is not in safe sequence\n");
	}

	return 0;
}

