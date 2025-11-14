#include <iostream>
using namespace std;

// ---------------- Priority Scheduling (Non-Preemptive) ----------------
void priorityScheduling(int n, int at[], int bt[], int pr[]) {
    int ct[20], tat[20], wt[20], done[20] = {0};

    int time = 0, completed = 0;

    while (completed < n) {
        int idx = -1, best = 9999;

        for (int i = 0; i < n; i++)
            if (!done[i] && at[i] <= time && pr[i] < best) {
                best = pr[i];
                idx = i;
            }

        if (idx == -1) { time++; continue; }

        time += bt[idx];
        ct[idx] = time;
        tat[idx] = ct[idx] - at[idx];
        wt[idx] = tat[idx] - bt[idx];
        done[idx] = 1;
        completed++;
    }

    cout << "\nPriority Scheduling (Non-Preemptive)\n";
    cout << "PID\tAT\tBT\tPR\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++)
        cout << i << "\t" << at[i] << "\t" << bt[i] << "\t" << pr[i] 
             << "\t" << ct[i] << "\t" << tat[i] << "\t" << wt[i] << "\n";
}

// ---------------- Round Robin Scheduling (Preemptive) ----------------
void roundRobin(int n, int at[], int bt[], int tq) {
    int rem[20], ct[20], tat[20], wt[20];

    for (int i = 0; i < n; i++) {
        rem[i] = bt[i];
        ct[i] = 0;
    }

    int time = 0, done = 0;

    while (done < n) {
        int idle = 1;

        for (int i = 0; i < n; i++) {
            if (rem[i] > 0 && at[i] <= time) {
                idle = 0;

                if (rem[i] <= tq) {
                    time += rem[i];
                    rem[i] = 0;
                    ct[i] = time;
                    tat[i] = ct[i] - at[i];
                    wt[i] = tat[i] - bt[i];
                    done++;
                } else {
                    rem[i] -= tq;
                    time += tq;
                }
            }
        }

        if (idle) time++;
    }

    cout << "\nRound Robin Scheduling (Preemptive)\n";
    cout << "PID\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++)
        cout << i << "\t" << at[i] << "\t" << bt[i] << "\t"
             << ct[i] << "\t" << tat[i] << "\t" << wt[i] << "\n";
}

// ---------------- SJF Preemptive Scheduling ----------------
void sjfPreemptive(int n, int at[], int bt[]) {
    int rem[20], ct[20], tat[20], wt[20];

    for (int i = 0; i < n; i++) {
        rem[i] = bt[i];
        ct[i] = 0;
    }

    int time = 0, done = 0;

    while (done < n) {
        int idx = -1, minRem = 9999;

        for (int i = 0; i < n; i++)
            if (rem[i] > 0 && at[i] <= time && rem[i] < minRem) {
                minRem = rem[i];
                idx = i;
            }

        if (idx == -1) { time++; continue; }

        rem[idx]--;
        time++;

        if (rem[idx] == 0) {
            ct[idx] = time;
            tat[idx] = ct[idx] - at[idx];
            wt[idx] = tat[idx] - bt[i];
            done++;
        }
    }

    cout << "\nSJF Scheduling (Preemptive)\n";
    cout << "PID\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++)
        cout << i << "\t" << at[i] << "\t" << bt[i] << "\t"
             << ct[i] << "\t" << tat[i] << "\t" << wt[i] << "\n";
}

// ---------------- Main Function ----------------
int main() {
    int n;
    cout << "Enter number of processes: "; 
    cin >> n;

    int at[20], bt[20], pr[20];
    cout << "Enter Arrival Time and Burst Time for each process:\n";
    for (int i = 0; i < n; i++) 
        cin >> at[i] >> bt[i];

    cout << "Enter Priority for each process:\n";
    for (int i = 0; i < n; i++) 
        cin >> pr[i];

    int tq;
    cout << "Enter Time Quantum for Round Robin: ";
    cin >> tq;

    priorityScheduling(n, at, bt, pr);
    roundRobin(n, at, bt, tq);
    sjfPreemptive(n, at, bt);

    return 0;
}
