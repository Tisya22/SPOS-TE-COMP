#include <iostream>
#include <algorithm>
using namespace std;

// Structure to represent a process
struct Process {
    int at, bt, pno, ct, tat, wt; 
};


bool compare(Process a, Process b) {
    return a.at < b.at;                              // Sort in increasing order of arrival time
}

void findAvgTime(Process proc[], int n) {
    int wavg = 0, tavg = 0; 
   
    sort(proc, proc + n, compare);

    // First process 
    proc[0].ct = proc[0].at + proc[0].bt;
    proc[0].tat = proc[0].ct - proc[0].at;  // TAT = CT - AT
    proc[0].wt = proc[0].tat - proc[0].bt;  // WT = TAT - BT

    // For remaining processes, calculate start time, completion time, waiting time, and turnaround time
    for (int i = 1; i < n; i++) {
        proc[i].ct = max(proc[i-1].ct, proc[i].at) + proc[i].bt; // CT = max(CT of previous, AT of current) + BT
        proc[i].tat = proc[i].ct - proc[i].at;   // TAT = CT - AT
        proc[i].wt = proc[i].tat - proc[i].bt;    // WT = TAT - BT
    }

    // Calculate averages of waiting time and turnaround time
    for (int i = 0; i < n; i++) {
        wavg += proc[i].wt;
        tavg += proc[i].tat;
    }

    cout << "Process No.\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time" << endl;
    for (int i = 0; i < n; i++) {
        cout << proc[i].pno << "\t\t" << proc[i].at << "\t\t" << proc[i].bt << "\t\t"
             << proc[i].ct << "\t\t" << proc[i].wt << "\t\t" << proc[i].tat << endl;
    }
    cout << "Average Waiting Time: " << (wavg / (double)n) << endl;
    cout << "Average Turnaround Time: " << (tavg / (double)n) << endl;
}

int main() {
    int n;
    cout << "Enter the total number of processes: ";
    cin >> n;

    Process proc[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter the Arrival time and Burst time for process " << (i + 1) << ": ";
        cin >> proc[i].at >> proc[i].bt;
        proc[i].pno = i + 1;  // Assign process number (1-based index)
    }

    findAvgTime(proc, n);

    return 0;
}
