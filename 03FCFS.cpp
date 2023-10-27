// First Come First Serve Scheduling algorithm.
// criteria : First come First Serve.
// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     vector<int> at,bt,ct,tat,wt;
//     float avg_wt = 0.0,  avg_tat = 0.0;
//     int n;
//     cout<<"Enter no of process:";
//     cin>>n;
//     cout<<"Enter Arrival time:";
//     for(int i=0;i<n;i++)
//     {
//         int x;
//         cin>>x;
//         at.push_back(x);
//     }
//     cout<<"Enter Burst Time:";
//     for(int i=0;i<n;i++)
//     {
//         int x;
//         cin>>x;
//         bt.push_back(x);
//     }
//     cout<<endl<<"Process  Arival_Time  Burst_Time  Completion_Time  Turnaround_Time  Waiting_Time  ";
    
//     ct.push_back(bt[0]+at[0]);
//     tat.push_back(ct[0]-at[0]);
//     wt.push_back(tat[0]-bt[0]);
//     avg_tat = tat[0];
//     avg_wt = wt[0];
//     cout<<endl<<"    "<<0<<"        "<<at[0]<<"           "<<bt[0]<<"             "<<ct[0]<<"                "<<tat[0]<<"                "<<wt[0]<<endl;
//     for(int i=1;i<n;i++)
//     {
//         ct[i]=bt[i]+ct[i-1];
//         tat[i]= ct[i]-at[i];
//         wt[i]=tat[i]-bt[i];
//         avg_tat+=tat[i];
//         avg_wt+=wt[i];

//         cout<<endl<<"    "<<i<<"        "<<at[i]<<"           "<<bt[i]<<"             "<<ct[i]<<"                "<<tat[i]<<"                "<<wt[i]<<endl;
//     }
//     cout<<"Average Turnaround Time :"<<(float)avg_tat/n<<endl;
//     cout<<"Average Waiting Time :"<<(float)avg_wt/n<<endl;

//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n;
    cout<<"Enter n:";
    cin>>n;
    vector<int> at, bt, ct(n), tat(n);
    cout<<"Enter at:";
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        at.push_back(x);
    }
    cout<<"Enter bt:";
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        bt.push_back(x);
    }
    vector<pair<int,pair<int,int>>> v; // {at,{bt, pid}}
    for(int i=0;i<n;i++)
    {
        v.push_back({at[i],{bt[i],i}});
    }
    for(int i=0;i<n;i++)
    {
        cout<<v[i].first<<" "<<v[i].second.first<<" "<<v[i].second.second<<endl;
    }
    
    sort(v.begin(),v.end());
    queue<pair<int,int>> q; // bt, pid
    int count =n;
    int t=0;
    int i=0;
    while(count>0)
    {
        if(t<v[0].first) t++;
        else
        {
            
            while(i<n && v[i].first <=t)
            {
                q.push({v[i].second.second,v[i].second.first});
                i++;
            }
            t+=q.front().second;
            ct[q.front().first]=t;
            q.pop();
            count--;
        }
    }
    float avg_tat=0.0;
    for(int i=0;i<n;i++)
    {
        tat[i]=ct[i]-at[i];
        avg_tat+=tat[i];
    }
    cout<<"Avg tat:"<<fixed<<setprecision(1)<<avg_tat/n<<endl;
    return 0;
}
