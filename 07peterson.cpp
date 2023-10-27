// Peterson Solution ,i.e., two process solution.

#include<iostream>
#include<bits/stdc++.h>
void first_process(int &turn, bool flag[])
{
    do{
        flag[0]=true;
        turn =1;
        while(turn==1 && flag[1]==true);
        // Critical section
        flag[0]=false;
    }while(true);
}
void second_process(int &turn, bool flag[])
{
    do{
        flag[1]=true;
        turn =0;
        while(turn==0 && flag[0]==true);
        // Critical section
        flag[1]=false;
    }while(true);
}
int main()
{
    int turn;// Indicates whose turn it is to enter in critical section.
    bool flag[2]={false, false}; // Used to indicate whether a process is ready to enter the critical section.
    first_process( turn, flag);
    second_process( turn, flag);
}

