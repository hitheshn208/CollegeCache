#include<stdio.h>
#include<stdlib.h>

void paging()
{
	int page_size;
	printf("Enter the page size : " );
	scanf("%d", &page_size);
	int logical_address;
	printf("Enter logical address : ");
	scanf("%d", &logical_address);

	int page_no = logical_address / page_size;
	int offset = logical_address % page_size;

	printf("Page number : %d\n", page_no);
	printf("Page Offset : %d\n", offset);
}

void segmentation()
{
	int segments;

	printf("Enter the total number of segments : ");
	scanf("%d", &segments);

	int base[segments], limit[segments];
	for(int i = 0; i < segments; i++)
        {
  	        printf("\nEnter base address of segment %d: ", i);
                scanf("%d", &base[i]);

                printf("Enter limit of segment %d: ", i);
                scanf("%d", &limit[i]);
            }

	int segNo, offset;

	printf("\nEnter segment number: ");
        scanf("%d", &seg_no);

        printf("Enter offset: ");
        scanf("%d", &offset);

	if(limit[segNo] >= offset)
		printf("Physical address : %d\n", base[segNo] + offset);
	else
		printf("Offset exceeds limit\n");
}

int main()
{
	int choice;

    printf("1. Paging Technique\n");
    printf("2. Segmentation Technique\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:paging();
	      break;
	case 2: segmentation();
		break;
	default: exit(1);
    }

	return 0;
}	
