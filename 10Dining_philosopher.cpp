// dining philospher using semaphore


#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void wait(int &s)
{
    while(s<=0);
    s--;
}
void signal(int &s)
{
    s++;
}
void philosopher_i(int i,vector<int> &chopsticks)
{
    do{
        wait(chopsticks[i]);
        wait(chopsticks[(i+1)%chopsticks.size()]);

        /* philosopher eating now */

        signal(chopsticks[i]);
        signal(chopsticks[(i+1)%chopsticks.size()]);
    }while(true);
}
int main()
{
    vector<int> chopsticks(5,0);

    philosopher_i(0,chopsticks);
    philosopher_i(1,chopsticks);
    philosopher_i(2,chopsticks);
    philosopher_i(3,chopsticks);
    philosopher_i(4,chopsticks);
}