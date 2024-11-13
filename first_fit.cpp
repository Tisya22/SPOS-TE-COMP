#include <iostream>
#include <vector>
using namespace std;

void firstFit(vector<int>& blockSize, int m, vector<int>& processSize, int n) {
    // Array to store the block index of the allocated block to each process
    vector<int> allocation(n, -1); // Initialize all elements to -1, meaning no allocation yet.

    // Iterate over each process
    for (int i = 0; i < n; i++) {
        // Find the first block that can fit the current process
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) { // Check if the block is large enough
                allocation[i] = j;                // Assign block j to process i
                blockSize[j] -= processSize[i];   // Reduce the available block size
                break;                            // Move to the next process
            }
        }
    }

    // Display allocation results
    cout << "Process No.\tProcess Size\tBlock No." << endl;
    for (int i = 0; i < n; i++) {
        cout << " " << i + 1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;           // Block numbers are displayed as 1-based index
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

    firstFit(blockSize, m, processSize, n);

    return 0;
}
