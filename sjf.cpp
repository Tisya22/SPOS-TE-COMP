#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// Structure to represent a process
struct Process {
    int at, bt, pno, ct, tat, wt, rt; 
};

void findAvgTime(Process proc[], int n) {
    int time = 0;                            // Current time
    int completed = 0;                       // Number of completed processes
    int shortest = -1;                       // Index of the shortest remaining time process
    int min_rt = INT_MAX;                    // Minimum remaining time
    bool found = false;

    for (int i = 0; i < n; i++) {
        proc[i].rt = proc[i].bt; // Initialize remaining time
    }

    while (completed < n) {
        // Find the process with the minimum remaining time that has arrived
        for (int i = 0; i < n; i++) {
            if (proc[i].at <= time && proc[i].rt > 0 && proc[i].rt < min_rt) {
                min_rt = proc[i].rt;
                shortest = i;
                found = true;
            }
        }

        if (!found) {  // If no process is ready, increment time
            time++;
            continue;
        }

        // Process the shortest remaining time process
        proc[shortest].rt--;
        min_rt = proc[shortest].rt;

        // Update minimum if the process finishes
        if (proc[shortest].rt == 0) {
            min_rt = INT_MAX;
            proc[shortest].ct = time + 1;
            proc[shortest].tat = proc[shortest].ct - proc[shortest].at;
            proc[shortest].wt = proc[shortest].tat - proc[shortest].bt;
            completed++;
            found = false;
        }

        time++;
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
    int n;
    cout << "Enter the total number of processes: ";
    cin >> n;

    Process proc[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter the Arrival time and Burst time for process " << (i + 1) << ": ";
        cin >> proc[i].at >> proc[i].bt;
        proc[i].pno = i + 1;  
    }

    findAvgTime(proc, n);
    return 0;
}
