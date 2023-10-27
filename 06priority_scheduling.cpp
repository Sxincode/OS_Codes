// priority scheduling 
// We are assuming that all process arrive at same time.. i.e. at time : 0

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter number of process:";
    cin>>n; 
    vector<int> pr, bt,ct(n),tat(n),wt(n);
    float avg_tat=0.0, avg_wt=0.0;
    cout<<"Enter Priority:";
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        pr.push_back(x);
    }
    cout<<"Enter burst time:";
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        bt.push_back(x);
    }
    vector<pair<int,pair<int,int>>> v;
    for(int i=0;i<n;i++)
    {
        v.push_back({pr[i],{bt[i],i}});
    }
    sort(v.begin(), v.end());
    int time=0;
    int count=n;
    int i=0;
    while(count>0)
    {
        time+=v[i].second.first;
        ct[v[i].second.second]=time;
        i++;
        count--;        
    }
    for(int i=0;i<n;i++)
    {
        tat[i]=ct[i];
        wt[i]=tat[i]-bt[i];
        avg_tat+=tat[i];
        avg_wt+=wt[i];
    }
    cout<<endl<<"Process  priority  Burst_Time  Completion_Time  Turnaround_Time  Waiting_Time  ";
    for(int i=0;i<n;i++)
    {
        cout<<endl<<"    "<<i<<"        "<<pr[i]<<"           "<<bt[i]<<"             "<<ct[i]<<"                "<<tat[i]<<"                "<<wt[i]<<endl;
    }
    cout<<"Average Turnaround Time :"<<(float)avg_tat/n<<endl;
    cout<<"Average Waiting Time :"<<(float)avg_wt/n<<endl;

    
}