#include <stdio.h>
#include<stdlib.h>

int SIZE = 0;
int *hashTable;

void init()
{
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}

int hashFunction(int key)
{
    return key % SIZE;
}

void insert()
{
    int key, index;
    printf("Enter key to insert: ");
    scanf("%d", &key);

    index = hashFunction(key);
    int pre_index = index;

    while (hashTable[index] != -1)
    {
        index = (index + 1) % SIZE;

        if(pre_index == index)
        {
            printf("Hash Table is full \n");
            return;
        }
    }

    hashTable[index] = key;
    printf("Key %d inserted at index %d\n", key, index);
}

void search()
{
    int key, index, startIndex;
    printf("Enter key to search: ");
    scanf("%d", &key);

    index = hashFunction(key);
    startIndex = index;

    while (hashTable[index] != -1)
    {
        if (hashTable[index] == key)
        {
            printf("Key %d found at index %d\n", key, index);
            return;
        }

        index = (index + 1) % SIZE;

        if (index == startIndex)
            break;
    }

    printf("Key %d not found\n", key);
}

void display()
{
    printf("\nHash Table:\n");
    for (int i = 0; i < SIZE; i++)
        printf("Index %d : %d\n", i, hashTable[i]);
}

int main()
{
    int choice;
    printf("Enter hash table size : ");
    scanf("%d", &SIZE);
    hashTable = (int*)malloc(SIZE*sizeof(int));

    init();

    while (1)
    {
        printf("\n--- Hash Table Menu ---\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            search();
            break;
        case 3:
            display();
            break;
        case 4:
            free(hashTable);
            return 0;
        default:
            printf("Invalid choice!\n");
        }
    }
}
