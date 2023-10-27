// Reader-Writer using semaphore
// While writer is writing no other reader's or writer's is allowed to enter.
// While reader is reading other reader's are allowed but not writer's.
// wrt is a binary semaphore which is common for both reader and writer.
// mutex us a binary semaphore used to ensure mutual exclusion when readcnt is updated.
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
void writer(int &wrt)
{
    do{
        // writer request for critical section.
        wait(wrt);
        /* writer writes into the file.*/

        // writer releasing the critical section.
        signal(wrt);
    }while(true);
}
void reader(int &wrt, int &mutex, int &readcnt)
{
    do
    {
        wait(mutex);
        readcnt++; // one reader added

        if (readcnt==1)
        {
            wait(wrt);// now no writer can enter as wrt become 0
            //and in wait it goes to infinite loop for writer.

            signal(mutex);// releasing mutex to let other reader enter.
        }
        /*current reader perform reading here*/
        wait(mutex);
        readcnt--;
        if(readcnt==0)
        {
            signal(wrt);// now writer can enter
            signal(mutex);// reader leaves
        }

    }while(true);
}
int main()
{
    int wrt=1;
    int mutex=1;
    int readcnt=0;

    writer(wrt);
    reader(wrt,mutex,readcnt);
    writer(wrt);
    reader(wrt,mutex,readcnt);
    writer(wrt);
    reader(wrt,mutex,readcnt);
    writer(wrt);
    reader(wrt,mutex,readcnt);

    return 0;
}