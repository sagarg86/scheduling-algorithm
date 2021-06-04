#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of Processes: ";
    cin >> n;
    cout << "Enter Arrival Time for processes: " << endl;
    int at[n];
    for (int i = 0; i < n; i++)
    {

        cin >> at[i];
    }

    cout << "Enter Burst Time for processes: " << endl;
    int bt[n];
    for (int i = 0; i < n; i++)
    {

        cin >> bt[i];
    }

    int wt[n], tat[n], rt[n], ct[n];
    int total_wt = 0, total_tat = 0;
    float avg_wt, avg_tat;

    ct[0] = bt[0] + at[0];
    for (int i = 1; i < n; i++)
    {
        ct[i] = max(ct[i - 1], at[i]) + bt[i];
    }
    for (int i = 0; i < n; i++)
    {
        tat[i] = ct[i] - at[i];
        total_tat += tat[i];
    }
  
    for (int i = 0; i < n; i++)
    {
        wt[i] = tat[i] - bt[i];
        total_wt += wt[i];
    }
    rt[0] = 0;
    for (int i = 1; i < n; i++)
    {

        rt[i] = ct[i - 1] - at[i];
    }

    avg_tat = total_tat / float(n);
    avg_wt = total_wt / float(n);

    cout << "id" << '\t' << "AT" << '\t' << "BT" << '\t' << "CT" << '\t' << "TAT" << '\t' << "WT" << '\t' << "RT" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << '\t' << at[i] << '\t' << bt[i] << '\t' << ct[i] << '\t' << tat[i] << '\t' << rt[i] << '\t' << rt[i] << '\n';
    }
    cout << "Average Turn Around Time: " << avg_tat << '\n'
         << "Average Waiting Time: " << avg_wt << '\n'
         << "Schedule Length: " << ct[n - 1];
}