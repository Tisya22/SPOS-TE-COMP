#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Structure to represent a process
struct Process {
    int at, bt, rt, pno, ct, tat, wt; 
};

void findAvgTime(Process proc[], int n, int quantum) {
    int time = 0;  // Time counter
    int completed = 0;  // Number of completed processes
    queue<int> q;   // Queue for processes

    // Initialize remaining time for each process
    for (int i = 0; i < n; i++) {
        proc[i].rt = proc[i].bt;  // Initially, remaining time is equal to burst time
    }

    while (completed < n) {
        bool processExecuted = false;

        // Loop through all processes to simulate Round Robin
        for (int i = 0; i < n; i++) {
            if (proc[i].rt > 0) {
                processExecuted = true;
                if (proc[i].rt > quantum) {
                    proc[i].rt -= quantum;
                    time += quantum;
                } else {
                    time += proc[i].rt;
                    proc[i].ct = time;
                    proc[i].tat = proc[i].ct - proc[i].at;  // TAT = CT - AT
                    proc[i].wt = proc[i].tat - proc[i].bt; // WT = TAT - BT
                    proc[i].rt = 0;  // Process is finished
                    completed++;
                }
            }
        }

        // If no process was executed in this round, increment time to avoid an infinite loop
        if (!processExecuted) {
            time++;
        }
    }

    // Calculate and display average waiting time and turnaround time
    double wavg = 0, tavg = 0;
    cout << "Process No.\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time" << endl;
    for (int i = 0; i < n; i++) {
        wavg += proc[i].wt;
        tavg += proc[i].tat;
        cout << proc[i].pno << "\t\t" << proc[i].at << "\t\t" << proc[i].bt << "\t\t"
             << proc[i].ct << "\t\t" << proc[i].wt << "\t\t" << proc[i].tat << endl;
    }

    // Output the average waiting time and turnaround time
    cout << "Average Waiting Time: " << (wavg / n) << endl;
    cout << "Average Turnaround Time: " << (tavg / n) << endl;
}

int main() {
    int n, quantum;
    cout << "Enter the total number of processes: ";
    cin >> n;

    Process proc[n];

    // Input arrival time and burst time for each process
    for (int i = 0; i < n; i++) {
        cout << "Enter the Arrival time and Burst time for process " << (i + 1) << ": ";
        cin >> proc[i].at >> proc[i].bt;
        proc[i].pno = i + 1;  // Assign process number (1-based index)
    }

    cout << "Enter the time quantum: ";
    cin >> quantum;

    // Calculate and display average waiting time and turnaround time
    findAvgTime(proc, n, quantum);

    return 0;
}
