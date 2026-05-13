#include<stdlib.h>
#include<stdio.h>

void sort(int a[], int n)
{
	for(int i = 0; i < n - 1; i++)
		for(int j = 0; j < n-i-1; j++)
			if(a[j] > a[j+1])
			{
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
}

void fcfs(int req[], int n, int head)
{
	int total = 0;

	for(int i = 0; i < n; i++)
	{
		int seek = abs(req[i] - head);
		total += seek;
		head = req[i];
	}
	printf("Total FIFO seek time %d\n", total);
}

void scan(int req[], int n, int head, int disk_size, int circular)
{
	int pos;
	int total = 0;
	sort(req, n);
	for(int i = 0; i < n; i ++)
		if(head < req[i]){
			pos = i;
			break;
		}

	//Moving towards right 
	for(int i = pos; i < n; i++)
	{
		int seek = abs(head - req[i]);
		total += seek;
		head = req[i];
	}

	//Move to the end
	int seek = abs((disk_size - 1) - head);
	total += seek;
	head = disk_size-1;

	if(circular == 0)
	{
		//SCAN
		for(int i = pos-1; i >= 0; i--)
		{
			int seek = abs(head - req[i]);
			total += seek;
			head = req[i];
		}

		printf("Total SCAN seek time is %d\n", total); 
	}else{
		//CSCAN
		total += head;
		head = 0;

		for(int i = 0; i < pos; i++)
		{
			int seek = abs(head - req[i]);
			total += seek;
			head = req[i];
		}
		printf("Total CSCAN seek time is %d\n", total);
	}
}



int main()
{
    int n, head, disk_size;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    int req[n];

    printf("Enter request sequence:\n");

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &req[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter disk size: ");
    scanf("%d", &disk_size);

    fcfs(req, n, head);

    scan(req, n, head, disk_size, 0);

    scan(req, n, head, disk_size, 1);

    return 0;
}
