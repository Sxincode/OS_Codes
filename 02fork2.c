// Program for fork() system call

#include<stdio.h>
int main()
{
    if(fork())
    {
        if(!fork())
        {
            fork();
            printf("Hey! ");
        }
        else
        {
            printf("Lucifer ");
        }
    }
    else
    {
        printf(" Morning ");
    }
    printf(" Star ");
    return 0;
}