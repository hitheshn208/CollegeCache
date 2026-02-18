#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>

void main(int args, char* strs[])
{
    if(args<2)
    {
        fprintf(stderr,"enter a string as commandline aregument");
        exit(1);
    }

    while(1)
    {
        sleep(1);
        printf("%s\n", strs[1]);
    }
}