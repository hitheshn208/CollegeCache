#include<stdio.h>
#include<stdlib.h>

int main()
{
	int frames;
	printf("Enter the number of frames: ");
	scanf("%d", &frames);

	int pages;
	printf("Enter the number of pages : ");
	scanf("%d", &pages);
	
	int ref[pages];
	printf("Enter the references string : ");
	for(int i = 0; i<pages; i++)
		scanf("%d", &ref[i]);

	int stack[frames];
	for(int i = 0; i < frames; i++)
		stack[i] = 0;
	int top = 0;
	int fault = 0, hit = 0;

	for(int i = 0; i < pages; i++)
	{
		int page = ref[i];
		int found = 0;
		int pos = -1;
		for(int j = 0; j < top; j++)
		{
			if(stack[j] == page)
			{	
				found = 1;
				hit++;
				pos = j;
				break;
			}
		}

		if(found)
		{
			int temp = stack[pos];
			for(int j = pos; j < top - 1; j++)
				stack[j] = stack[j+1];

			stack[top-1] = temp;
		}else{
			fault++;

			if(top < frames)
			{
				stack[top] = page;
				top++;
			}else{
				for(int j = 0; j < frames - 1; j++)
				{
					stack[j] = stack[j+1];
				}
				stack[frames-1] = page;
			}
		}

		printf("Page %d -> ", page);
		for(int k = 0; k < top; k++)
			printf("%d ",stack[k]);

		found == 1? printf("hit\n") : printf("fault\n");

	}

	printf("Total page faults %d\n", fault);
	printf("Total page hits %d\n", hit);

	return 0;
}
			



