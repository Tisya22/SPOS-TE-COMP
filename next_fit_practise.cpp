#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

void nextFit(vector<int>& blockSize, int m, vector<int>& processSize, int n) {
    vector<int> allocation(n, -1);
    int j = 0; // Start block index

    for (int i = 0; i < n; i++) {
        int startIdx = j; 

        while(true){                                     // Loop to find the next available block that can fit the process
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j; 
                blockSize[j] -= processSize[i]; 
                j = (j + 1) % m; 
                break;
            }
            j = (j + 1) % m;                            // Move to the next block

		if(j==startIdx) break;                          // If j returns to the starting index, no suitable block was found
        } 
    }

    // Output the allocation result
    cout << "Process No.\tProcess Size\tBlock No." << endl;
    for (int i = 0; i < n; i++) {
        cout << " " << i + 1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1; // Output 1-based block index
        else
            cout << "Not Allocated";
        cout << endl;
    }
}

int main() {
    int m, n;
    cout << "Enter the number of blocks and the number of processes: ";
    cin >> m >> n;

    vector<int> blockSize(m), processSize(n);

    cout << "Enter the sizes of the blocks:" << endl;
    for (int i = 0; i < m; i++) {
        cin >> blockSize[i];
    }

    cout << "Enter the sizes of the processes:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> processSize[i];
    }

    nextFit(blockSize, m, processSize, n);

    return 0;
}
