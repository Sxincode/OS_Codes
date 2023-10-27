// Producer - consumer using binary semaphore.
// mutex for aquiring lock
// s is a binary semaphore for critical section
//  F is for denoting no of element are in buffer
//  E is for denoting no of empty slots in buffer.
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
void producer(int &s, int &mutex,int &F, int &E,int &i,vector<int> buffer)
{
    // Checking whether buffer is full or not.
    wait(E);
    // Aquiring lock.
    wait(mutex);

    /* Adding data to buffer*/
    buffer[i]=191;
    i= (i+1)% buffer.size();

    // Releasing lock
    signal(mutex);
    // increasing F value to denote one element added.
    signal(F);
}
void consumer(int &s, int &mutex,int &F, int &E,int &i,vector<int> buffer)
{
    // Checking whether buffer is empty or not.
    wait(F);
    // Aquiring lock.
    wait(mutex);

    /* Removing data from buffer*/
    buffer[(i-1)%buffer.size()]=-1;
    i= (i+1)% buffer.size();

    // Releasing lock
    signal(mutex);
    // increasing E value to denote one element removed.
    signal(E);
}
int main()
{
    int n=10;
    int i=0;
    vector<int> buffer(n);
    int s=1; // Binary semaphore
    int mutex =1; // Lock
    int F=0; // Full slots
    int E=n; // Empty slots
    producer(s,mutex,F,E,i,buffer);
    consumer(s,mutex,F,E,i,buffer);
    producer(s,mutex,F,E,i,buffer);
    consumer(s,mutex,F,E,i,buffer);
    producer(s,mutex,F,E,i,buffer);
    consumer(s,mutex,F,E,i,buffer);
}