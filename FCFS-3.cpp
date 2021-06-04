#include <iostream>
#include <algorithm>
using namespace std;

struct pinfo
{
    int id;
    int AT;
    int BT;
    int CT;
    int TAT;
    int WT;
};

float averageTAT(pinfo info[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += info[i].TAT;
    return (float)sum / n;
}

float averageWT(pinfo info[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += info[i].WT;
    return (float)sum / n;
}

int main()
{
    int n;
    cout << "Enter number of Processes: ";
    cin >> n;
    pinfo info[n];
    for (int i = 0; i < n; i++)
    {
        info[i].id = i + 1;
    }
    cout << "Enter Arrival Time for processes: " << endl;
    for (int i = 0; i < n; i++)
    {

        cin >> info[i].AT;
    }
    cout << "Enter Burst Time for processes: " << endl;
    for (int i = 0; i < n; i++)
    {

        cin >> info[i].BT;
    }
    sort(info, info + n, [](pinfo &a, pinfo &b)
         { return a.AT < b.AT; });

    int curr_time = 0;
    for (int i = 0; i < n; i++)
    {
        info[i].CT = max(curr_time, info[i].AT) + info[i].BT;
        curr_time = info[i].CT;
        info[i].TAT = info[i].CT - info[i].AT;
        info[i].WT = info[i].TAT - info[i].BT;
    }

    cout << "id" << '\t' << "AT" << '\t' << "BT" << '\t' << "CT" << '\t' << "TAT" << '\t' << "WT\n";
    for (int i = 0; i < n; i++)
    {
        cout << info[i].id << '\t' << info[i].AT << '\t' << info[i].BT << '\t' << info[i].CT << '\t' << info[i].TAT << '\t' << info[i].WT << '\n';
    }
    cout << "Average Turn Around Time: " << averageTAT(info, n) << '\n'
         << "Average Waiting Time: " << averageWT(info, n) << '\n'
         << "Schedule Length: " << info[n - 1].CT - info[0].AT;
}