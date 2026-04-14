#include<stdio.h>
#include<stdlib.h>

int mutex = 1;
int full = 0;
int empty = 3;
int item = 0;

void Produce()
{
	mutex--;

	full++;
	empty--;
	item++;
	printf("Producer produced item %d\n", item);

	mutex++;

	return;
}

void Consume()
{
	mutex--;

	empty++;
	full--;
	printf("Comsumer consumed item %d\n", item);
	item--;
	
	mutex++;
	return;
}

int main()
{
	int choice = 3;

	printf("Producer Consumer Problem Simulation\n");
	while(1)
	{
		printf("\n1.Produce\n2.Consume\n3.Exit\n");
		printf("Enter your choice : ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:	if(mutex == 1 && empty == 0)
					printf("BUFFER IS FULL! Producer must wait\n");
				else
					Produce();
				break;

			case 2: if(mutex == 1 && full == 0)
					printf("BUFFER IS EMPTY! Consumer must wait\n");
				else
					Consume();
				break;

			case 3: printf("Exiting..\n");
				exit(0);

			default : printf("Invalid choice\n");
		}
	}

	return 0;
}
