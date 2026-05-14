#include<stdio.h>
#include<stdlib.h>

void firstfit(int block[], int b, int process[], int p)
{
	int allocation[p];
	
	for(int i = 0; i < p; i++)
        allocation[i] = -1;

	for(int i = 0; i < p; i ++)
		for(int j = 0; j < b; j++)
			if(block[j] >= process[i])
			{
				allocation[i] = j;
				block[j] -= process[i];
				break;
			}
	
}	

void bestfit(int block[], int b, int process[], int p)
{
	int allocation[p];

        for(int i = 0; i < p; i++)
        allocation[i] = -1;

	for(int i = 0; i < p; i++)
	{
		int best = -1;
		for(int j = 0; j < b; j++)
		{
			if(block[j] >= process[i])
			{
				if(best == -1 || block[j] < block[best])
					best = j;
			}
		}

		if(best != -1)
		{
			allocation[i] = best;
			block[best] -= process[i];
		}
	}
}

void worstfit(int block[], int b, int process[], int p)
{
	int allocation[p];

        for(int i = 0; i < p; i++)
        allocation[i] = -1;

	for(int i = 0; i < p; i++)
	{
		int worst = -1;
		for(int j = 0; j < b; j++)
		{
			if(block[j] >= process[i])
			{
				if(worst == -1 || block[j] > block[worst])
					worst = j;
			}
		}

		if(worst != -1)
		{
			allocation[i] = worst;
			block[worst] -= process[i];
		}
	}
}


int main()
{
    int blocks, processes;

    int blockSize[10], processSize[10];
    int block1[10], block2[10], block3[10];

    printf("Enter number of memory blocks: ");
    scanf("%d", &blocks);

    printf("Enter sizes of memory blocks:\n");

    for(int i = 0; i < blocks; i++)
    {
        scanf("%d", &blockSize[i]);

        block1[i] = blockSize[i];
        block2[i] = blockSize[i];
        block3[i] = blockSize[i];
    }

    printf("Enter number of processes: ");
    scanf("%d", &processes);

    printf("Enter sizes of processes:\n");

    for(int i = 0; i < processes; i++)
        scanf("%d", &processSize[i]);

    firstfit(block1, blocks, processSize, processes);
    bestfit(block2, blocks, processSize, processes);
    worstfit(block3, blocks, processSize, processes);

    return 0;
}
