#include <iostream>
#include <algorithm>
using namespace std;

int ab;

typedef struct schedule
{
	string pro_id;
	int at,bt,ct,ta,wt;

}schedule;

bool compare(schedule a,schedule b)
{
	return a.at < b.at;
	
}

bool compare2(schedule a,schedule b)
{
	return a.bt < b.bt && a.at <= ab;
	
}

int main()
{
	schedule pro[10];
	
	int n,i,j;
    
    int avgtat=0,av_wt=0,sl=0;
	

	cout<<"Enter the number of process:";
	cin>>n;
	
	for(i=0;i<n;i++)
	{cout<<"Enter  arrival time for process p"<<i+1<<":";
		
		cin>>pro[i].at;
	    pro[i].pro_id=i+1;
	}
    for(i=0;i<n;i++)
	{cout<<"Enter  burst time for process p"<<i+1<<":";
	
		cin>>pro[i].bt;
	
	}
   

	sort(pro,pro+n,compare);


	pro[0].ct=pro[0].bt+pro[0].at;
	pro[0].ta=pro[0].ct-pro[0].at;
	pro[0].wt=pro[0].ta-pro[0].bt;

	for(i=1;i<n;i++)
	{
		ab=pro[i-1].ct;
		sort(pro+i,pro+n,compare2);
		if(pro[i-1].ct<pro[i].at)
		{
			pro[i].ct=pro[i-1].ct+pro[i].bt+(pro[i].at-pro[i-1].ct);
		}
		else
		{

			pro[i].ct=pro[i-1].ct+pro[i].bt;

		}
		pro[i].ta=pro[i].ct-pro[i].at;
		pro[i].wt=pro[i].ta-pro[i].bt;
	}
     cout<<"\n\nProcess\t arrivaltime\t BT\t CT\t TAT\tWT\n";
	for(i=0;i<n;i++)
	{
		
		cout<<i+1<<"\t\t"<<pro[i].at<<"\t"<<pro[i].bt
		<<"\t"<<pro[i].ct<<"\t"<<pro[i].ta<<"\t"<<pro[i].wt;
		
		cout<<endl;
        avgtat+=pro[i].ta;
        av_wt+=pro[i].wt;
        sl+=pro[i].bt;
	}
   cout<<"\n\n Avg TAT = "<< avgtat/n;
    cout<<"\n\n Avg WT = "<< av_wt/n;
    cout<<"\n\nLength = "<<sl;
	
	return 0;
}
