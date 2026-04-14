#include<stdlib.h>
#include<stdio.h>

int main()
{
	int read_count=0, choice, wrt = 1;
	printf("-------READER-WRITER SIMULATION-------\n");
	while(1)
	{
		printf("\n1.Add Reader\n2.Remove Reader\n3.Add Writer\n4.Remove Writer\n5.Exit\n");
		printf("Enter your choice : ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1: if(wrt == 0)
				{
					printf("Access denied: Writer is writing\n");
				}else{
					read_count++;
					printf("Reader added. Total active readers : %d\n", read_count);
				}
				break;

			case 2: if(read_count > 0)
				{
					read_count--;
					printf("Reader removed. Total active readers: %d\n", read_count);
				}else{
					printf("No reader is reading\n");
				}
				break;

			case 3: if(wrt == 0)
				{
					printf("Access denied : Another Writer is already writing\n");
				}else if(read_count > 0){
					printf("Access denied : Readers are reading\n");
				}else{
					wrt = 0;
					printf("Writer started writing\n");
				}
				break;

			case 4: if(wrt == 0)
				{
					wrt = 1;
					printf("Writer removed. Resource is now free\n");
				}else{
					printf("No writer is writing\n");
				}
				break;

			case 5: printf("Terminating....\n");
				exit(0);
		}
	}
}


