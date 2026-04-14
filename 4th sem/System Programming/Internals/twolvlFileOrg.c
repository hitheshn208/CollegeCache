#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct fileOrg{
	char name[10];
	int fileCount;
	char fileNames[10][10];
};

int main()
{
	int n;
	printf("Enter the number of users : ");
	scanf("%d", &n);
	struct fileOrg u[n];
	for( int i = 0; i < n; i++)
	{
		printf("Enter the name of the user %d", (i+1));
		scanf("%s",u[i].name);
		printf("Enter the number of files : " );
		scanf("%d",&u[i].fileCount);
		for(int j = 0; j < u[i].fileCount; j++)
		{
		 	printf("Enter the name of file-%d : ", (j+1));
			scanf("%s",  u[i].fileNames[j]);
		}
	}
	
	printf("\nTwo level file organisation\n");
	printf("Root\n  |\n");
	for(int  i = 0; i < n; i ++)
	{
		if(i == n-1)
			printf("  `--%s\n", u[i].name);
		else
			printf("  +--%s\n", u[i].name);

		for(int j = 0; j < u[i].fileCount; j++){
			if(j == u[i].fileCount - 1)
				printf("  |    `--%s\n", u[i].fileNames[j]);
			else
				printf("  |    +--%s\n", u[i].fileNames[j]);
		}
	}
	char Usearch[20], Fsearch[20];
	int found = 0;

	printf("Enter the username to search in : ");
	scanf("%s", Usearch);
	printf("Enter the filename to search : ");
	scanf("%s", Fsearch);
	
	for(int i = 0; i < n; i++)
	{
		if(strcmp(Usearch, u[i].name) == 0)
		{
			for(int j = 0; j < u[i].fileCount; j++)
			{
				if(strcmp(Fsearch, u[i].fileNames[j]) == 0)
				{
					found = 1;
					break;
				}
			}

			break;
		}
	}

	if(found)
		printf("File found\n");
	else
		printf("File not found\n");

	return 0;
}
						
