#include<iostream>
    using namespace std;

int main()
{
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;
    int burst_time[n];
    cout << "Enter burst time: ";
    for(int i = 0; i < n; i++) {
        cin >> burst_time[i];
    }

    int quantum;
    cout << "Enter time quantum: ";
    cin >> quantum;

    int remaining_time[n], wt[n], tat[n];
    for(int i = 0; i < n; i++) remaining_time[i] = burst_time[i];

    bool done;
    int current_time = 0;
    while(1) {
        done = true;
        for(int i = 0; i < n; i++) {
            if(remaining_time[i] > 0) {
                done = false;      // process is remaining
                if(remaining_time[i] > quantum) {
                    remaining_time[i] -= quantum;
                    current_time += quantum;
                }
                else {
                    current_time += remaining_time[i];
                    remaining_time[i] = 0;
                    wt[i] = current_time - burst_time[i];
                }
            }
        }

        if(done) {
            break;
        }
    }

    // turn around time
    double total_wt = 0, total_tat = 0;
    for(int i = 0; i < n; i++) {
        tat[i] = burst_time[i] + wt[i];
        total_wt += wt[i];
        total_tat += tat[i];
    }

    cout << "Process | " << "Burst time | " << "Waiting time | " << "Turnaround time\n";
    for(int i = 0; i < n; i++) {
        cout << " " << i+1 << "\t\t" << burst_time[i] << "\t\t" << wt[i] << "\t\t" << tat[i]<< '\n';
    }

    cout << "Average waiting time: " << total_wt / (double)n << '\n';
    cout << "Average turn around time: " << total_tat / (double)n << '\n';

    return 0;
}
