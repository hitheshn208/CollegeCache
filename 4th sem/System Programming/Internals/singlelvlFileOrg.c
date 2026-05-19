#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct file{
	char name[50];
};

int main()
{
	int n;
	printf("Enter the number of files : ");
	scanf("%d", &n);
	struct file u[n];
	
	for(int i = 0; i < n; i++)
	{
		printf("Enter the file %d name : ", (i+1));
		scanf("%s", u[i].name);
	}

	printf("\nSingle level File Organisation : \n");
	printf("Root\n  |\n");
	for(int i = 0; i < n; i++)
		if(i == n-1)
			printf("  `--%s\n", u[i].name);
		else
			printf("  +--%s\n", u[i].name);

	char find[20];
	printf("\n\nEnter the file name to search : " );
	scanf("%s", find);

	int found = 0;

	for(int i = 0; i < n; i ++)
		if(strcmp(find, u[i].name) == 0)
		{
			found = 1;
			break;
		}
	if(found)
		printf("File found in Root directory\n");
	else
		printf("File not found\n");

	return 0;
}
