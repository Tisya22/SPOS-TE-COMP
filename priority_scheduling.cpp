#include<bits/stdc++.h>
using namespace std;

struct process {
    int at, bt, pr, pno, ct, tat, wt; 
};

bool compare(process a, process b) {
    if(a.at == b.at) {
        return a.pr < b.pr;  
    } else {
        return a.at < b.at;   
    }
}

void findAvgTime(process proc[], int n) {
   
    sort(proc, proc + n, compare);
    
    int stime[n], ctime[n]; 
    double wavg = 0, tavg = 0; 

    // First process start time and completion time
    stime[0] = proc[0].at;
    ctime[0] = stime[0] + proc[0].bt;
    proc[0].ct = ctime[0];
    proc[0].tat = ctime[0] - proc[0].at;
    proc[0].wt = proc[0].tat - proc[0].bt;

    // For remaining processes, calculate start time, completion time, waiting time, and turnaround time
    for(int i = 1; i < n; i++) {
        // Set the start time as the maximum of the arrival time or the previous process's completion time
        stime[i] = max(ctime[i - 1], proc[i].at);
        ctime[i] = stime[i] + proc[i].bt;
        proc[i].ct = ctime[i];
        proc[i].tat = ctime[i] - proc[i].at;   // TAT = CT - AT
        proc[i].wt = proc[i].tat - proc[i].bt;  // WT = TAT - BT
    }

    // Calculate the averages of waiting time and turnaround time
    for(int i = 0; i < n; i++) {
        wavg += proc[i].wt;
        tavg += proc[i].tat;
    }

    cout << "Process No.\tArrival Time\tBurst Time\tPriority\tStart Time\tCompletion Time\tWaiting Time\tTurnaround Time" << endl;
    for(int i = 0; i < n; i++) {
        cout << proc[i].pno << "\t\t" << proc[i].at << "\t\t" << proc[i].bt << "\t\t"
             << proc[i].pr << "\t\t" << stime[i] << "\t\t" << proc[i].ct << "\t\t"
             << proc[i].wt << "\t\t" << proc[i].tat << endl;
    }

    cout << "Average Waiting Time: " << (wavg / n) << endl;
    cout << "Average Turnaround Time: " << (tavg / n) << endl;
}

int main() {
    int n;
    cout << "Enter the total number of processes: ";
    cin >> n;

    process proc[n];

    // Input arrival time, burst time, and priority for each process
    for(int i = 0; i < n; i++) {
        cout << "Enter the Arrival time, Burst time, and Priority respectively for process " << (i + 1) << ": ";
        cin >> proc[i].at >> proc[i].bt >> proc[i].pr;
        proc[i].pno = i + 1;  // Assign process number (1-based index)
    }

    // Calculate and display average waiting time and turnaround time
    findAvgTime(proc, n);

    return 0;
}