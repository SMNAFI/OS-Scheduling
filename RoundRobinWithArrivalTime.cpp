#include <bits/stdc++.h>
    using namespace std;

struct Process {
    int id, at, bt, rt, wt, tt;
};

int main() {
    int n;

    cout << "Enter the number of processes: ";
    cin >> n;
    Process p[n];

    cout << "Enter Process id, arrival time & burst time: ";
    for(int i = 0; i < n; i++) {
        cin >> p[i].id >> p[i].at >> p[i].bt;
        p[i].rt = p[i].bt;
    }

    int quantum;
    cout << "Enter time quantum: ";
    cin >> quantum;

    int current_time = 0;
    int completed = 0;

    deque<Process> q;
    vector<bool> visited(n, false);

    while (completed != n) {
        bool flag = false;
        for(int i = 0; i < n; i++) {
            if(p[i].arrival_time <= current_time && p[i].remaining_time > 0 && !visited[i]) {
                q.push(p[i]);
                visited[i] = true;
            }
        }

        if(q.size()) {

        }
                if(p[i].remaining_time > quantum) {
                    p[i].remaining_time -= quantum;
                    current_time += quantum;
                }
                else {
                    current_time += p[i].remaining_time;
                    p[i].remaining_time = 0;
                    p[i].waiting_time = current_time - p[i].burst_time - p[i].arrival_time;
                    p[i].turnaround_time = p[i].burst_time + p[i].waiting_time;
                    completed++;
                }
            }
        }

        if(flag == false) {
            current_time++;
        }
    }

    double total_wt = 0, total_tat = 0;
    for(int i = 0; i < n; i++) {
        total_wt += p[i].waiting_time;
        total_tat += p[i].turnaround_time;
    }

    cout << "\nProcess | " << "Burst time | " << "Waiting time | " << "Turnaround time\n";
    for(int i = 0; i < n; i++) {
        cout << " " << p[i].id << "\t\t" << p[i].burst_time << "\t\t" << p[i].waiting_time << "\t\t" << p[i].turnaround_time<< '\n';
    }

    cout << "\nAverage waiting time: " << total_wt / (double)n << '\n';
    cout << "Average turn around time: " << total_tat / (double)n << '\n';
}
