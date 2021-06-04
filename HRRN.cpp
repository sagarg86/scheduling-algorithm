#include<iostream>
#include<algorithm>
using namespace std;
struct node{
    int pname;
    int btime;
    int atime;
    int wtime;
    float rr=0;
}a[50];

bool btimeSort(node a,node b){
    return a.btime < b.btime; 
}
bool atimeSort(node a,node b){
    return a.atime < b.atime; 
}
bool rrtimeSort(node a,node b){
    return a.rr > b.rr; 
}
void disp(int n){
    sort(a,a+n,btimeSort);
    sort(a,a+n,atimeSort);
    int ttime=0,i;
    int j,tArray[n];
    for(i=0;i<n;i++){
        j=i;
        while(a[j].atime<=ttime&&j!=n){
            j++;
        }
        for(int q = i;q<j;q++){
            a[q].wtime=ttime-a[q].atime;
            a[q].rr=(float)(a[q].wtime+a[q].btime)/(float)a[q].btime;
        }
        sort(a+i,a+j,rrtimeSort);
        tArray[i]=ttime;
        cout<<endl;
        ttime+=a[i].btime;
    }
    tArray[i] = ttime;
    float averageWaitingTime=0;
    float averageResponseTime=0;
    float averageTAT=0;
    cout<<"\n";
    cout<<"P.Name  AT\tBT\tCT\tTAT\tWT\tRT\n";
    for (i=0; i<n; i++){
        cout <<'P'<< a[i].pname << "\t"; 
        cout << a[i].atime << "\t";
        cout << a[i].btime << "\t";
        cout << tArray[i+1] << "\t"; 
        cout << tArray[i]-a[i].atime+a[i].btime << "\t"; 
        averageTAT+=tArray[i]-a[i].atime+a[i].btime;
        cout << a[i].wtime << "\t"; 
        averageWaitingTime+=tArray[i]-a[i].atime;
        cout << tArray[i]-a[i].atime << "\t";  
        averageResponseTime+=tArray[i]-a[i].atime;
        cout <<"\n"; 
    }
    
    cout<<"\n";
    cout<<"Average Response time: "<<(float)averageResponseTime/(float)n<<endl;
    cout<<"Average Waiting time: "<<(float)averageWaitingTime/(float)n<<endl;
    cout<<"Average TA time: "<<(float)averageTAT/(float)n<<endl;
}
int main(){
    
    int n,i;
    cout<<"Enter number of processes\n";
    cin>>n;
   
	for(i=0;i<n;i++)
	{cout<<"Enter  arrival time for process p"<<i+1<<":";
		
		cin>>a[i].atime;
	    a[i].pname=i+1;
	}
    for(i=0;i<n;i++)
	{cout<<"Enter  burst time for process p"<<i+1<<":";
	
		cin>>a[i].btime;
	
	}
    disp(n);
    return 0;
}