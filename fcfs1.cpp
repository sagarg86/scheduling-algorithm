#include <bits/stdc++.h>
using namespace std;
int main()
{
    system("cls");

    int n;
    cout<<"Enter total no. of process: ";
    cin>>n;

    int burst_time[n];

    cout<<"Enter burst time for process : \n";
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter Bt for P "<<i+1<<": ";
        cin>>burst_time[i];
    }

    int tat_arr[n];
    for (int i = 0; i < n; i++)
    {
        tat_arr[i]=0;
    }
    int bt=0;
    for (int i = 0; i < n; i++)
    {
        tat_arr[i] = burst_time[i] + bt  ;
        bt = tat_arr[i];

    }

    int wt_arr[n];

    for (int i = 0; i < n; i++)
    {
        wt_arr[i]=0;
    }
    

   for (int i = 0; i < n; i++)
   {
       wt_arr[i] = tat_arr[i] - burst_time[i]; 
   }

    cout<<"\n\nProcess\t BurstTime\t TAT\tWT\n";

    float av_wt = 0,avgtat=0,sl=0;

    for (int i = 0; i < n; i++)
    {
        cout<<i+1<<"\t\t"<<burst_time[i]<<"\t"<<tat_arr[i]<<"\t"<<wt_arr[i]<<endl;
        avgtat+=tat_arr[i];
        av_wt+=wt_arr[i];
        sl+=burst_time[i];
    }

    cout<<"\n\n Avg TAT = "<< avgtat/n;
    cout<<"\n\n Avg WT = "<< av_wt/n;
    cout<<"\n\nLength = "<<sl;
return 0;
}