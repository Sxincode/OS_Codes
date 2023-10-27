// Shortest Job first scheduling algorithm.
// criteria : Burst Time & Non - preemptive.
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter no of process:";
    cin>>n;
    vector<int> at, bt, ct(n), tat(n), wt(n);
    float avg_tat=0.0, avg_wt=0.0;
    cout<<"Enter Arival time:";
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        at.push_back(x);
    }
    cout<<"Enter burst time:";
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        bt.push_back(x);
    }
    vector<pair<int,pair<int,int>>> v; //<at,<bt,pid>>
    for(int i=0;i<n;i++)
    {
        v.push_back({at[i],{bt[i],i}});
    }
    // sorting acc to arrival time.
    sort(v.begin(),v.end());
    priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> pq;// bt,pid 
    int time=0;
    int count =n;
    int i=0;
    while(time<v[i].first) time++;
    
    while(count>0)
    {
            if(time<v[i].first)
            {
                time++;
            }
            else
            {

                while(i<n && v[i].first<=time)
                {
                    
                    pq.push({v[i].second.first,v[i].second.second});
                    i++;
                }
                
                time+=pq.top().first;
                
                ct[pq.top().second]=time;
                pq.pop();
                count--;
            }
    }
    cout<<"Completion time::"<<endl;
    for(int i=0;i<n;i++)
    { 
        cout<<ct[i]<<" ";
    }
    for(int i=0;i<n;i++)
    {
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        avg_tat+=tat[i];
        avg_wt+=wt[i];
    }
    cout<<endl<<"Process  Arival_Time  Burst_Time  Completion_Time  Turnaround_Time  Waiting_Time  ";
    for(int i=0;i<n;i++)
    {
        cout<<endl<<"    "<<i<<"        "<<at[i]<<"           "<<bt[i]<<"             "<<ct[i]<<"                "<<tat[i]<<"                "<<wt[i]<<endl;
    }
    cout<<"Average Turnaround Time :"<<(float)avg_tat/n<<endl;
    cout<<"Average Waiting Time :"<<(float)avg_wt/n<<endl;
}
