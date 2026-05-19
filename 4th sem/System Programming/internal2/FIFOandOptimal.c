#include<stdio.h>
#include<stdlib.h>

void fifo(int pages, int frames, int ref[])
{
	int faults = 0, hits = 0;
	
	int frame[frames];
	int index = 0;

	for(int i = 0; i < frames; i++)
		frame[i] = -1;

	for(int i = 0; i < pages; i++)
	{
		int page = ref[i];
		int found = 0;
		for(int j = 0; j < frames; j++)
		{
			if(frame[j] == ref[i])
			{
				found = 1;
				hits++;
			}
		}

		if(!found)
		{
			faults++;
			frame[index] = ref[i];
			index = (index + 1) % frames;

		}

	}

	printf("Total faults : %d\n", faults);
	printf("Total hits : %d\n", hits);
}

void optimal(int pages, int frames, int ref[])
{
	int frame[frames];

	int faults = 0, hits = 0;
	for(int i = 0; i < frames; i++)
		frame[i] = -1;

	for(int i = 0; i < pages; i++)
	{
		int found = 0;

		for(int j = 0; j < frames; j++)
		{
			if(frame[j] == ref[i])
			{
				found = 1;
				hits++;
			}
		}

		if(!found)
		{
			int empty = -1;

			for(int k = 0; k < frames; k++)
				if(frame[k] == -1){
					empty = k;
					break;
				}

			if(empty != -1)
			{
				frame[empty] = ref[i];
				faults++;
			}else{
				faults++;
				int replaceIndex = -1;
				int farthest = -1;

				for(int j = 0; j < frames; j++)
				{
					int k;
					for(k = i+1; k < pages; k++)
						if(frame[j] == ref[k])
							break;

					if(k==pages)
						replaceIndex = k;

					if( k > farthest)
					{
						farthest = k;
						replaceIndex = k;
					}
				}

				frame[replaceIndex] = ref[i];
			}
		}
	}

	printf("Total faults %d\n", faults);
	printf("Total hits %d\n", hits);

	return;
}

int main()
{
	int pages, frames;
	printf("Enter the number of pages : ");
	scanf("%d", &pages);

	printf("Enter the number of frames : ");
	scanf("%d", &frames);

	int ref[pages];

	printf("Enter the reference string : ");
	for(int i = 0; i < pages; i++)
		scanf("%d", &ref[i]);

	fifo(pages, frames, ref);
	optimal(pages, frames, ref);

	return 0;
}
