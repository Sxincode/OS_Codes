/* Prevention of zombie process*/

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    int i;
    pid_t pid = fork();
    if(pid==0)
    {
        for(i=0;i<20;i++)
        {
            printf("I am Child\n");
        }
    }
    else
    {
        wait(NULL);
        printf("I am Parent\n");
        while(1);
    }
}