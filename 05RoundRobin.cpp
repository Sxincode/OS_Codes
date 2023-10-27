// Round Robin scheduling algorithm 
// Criteria Time Quantum.
// We need a queue to maintain the ready queue.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    // Enter number of process
    int n;
    cout<<"Enter number of process:";
    cin>>n;
    vector<vector<int>> v(n, vector<int>(6,0)); //  pid(0), at(1), bt(2), ct(3), tat(4), wt(5)

    cout<<"Enter process id:";
    for(int i=0;i<n;i++) // pid
    {
        cin>>v[i][0];
    }
    cout<<"Enter Arrival time:";
    for(int i=0;i<n;i++) // arrival time
    {
        cin>>v[i][1];
    }
    cout<<"Enter burst time:";
    for(int i=0;i<n;i++) // burst time
    {
        cin>>v[i][2];
    }

    // sort according to arrival time
    sort(v.begin(), v.end(), [](vector<int> &a, vector<int> &b){
        return a[1]<b[1];
    });

    queue<pair<int ,int>> q;// bt, index
    for(int i=0;i<n;i++)
    {
        q.push({v[i][2],i});
    }
    int time = 0;
    while(!q.empty())
    {
        int bt= q.front().first; // bt
        int ind = q.front().second; // index
        q.pop();
        if(bt-2>0) // assume time quantum = 2;
        {
            time+=2;
            v[ind][3]=time;
            q.push({bt-2,ind});
        }
        else
        {
            time+=bt;
            v[ind][3]=time;
        }
    }
    float wt_time = 0.0;
    for(int i=0; i<n;i++)
    {
        v[i][5] = v[i][3] - v[i][1]; // tat
        v[i][5] = v[i][4] - v[i][2]; // wt
        wt_time+=v[i][5];
    }
    cout<<"Average waiting time:"<<fixed<<setprecision(2)<<(float)wt_time/n;
    return 0;
}
