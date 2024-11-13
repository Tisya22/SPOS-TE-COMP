#include <iostream>
#include <vector>
using namespace std;

void worstFit(vector<int>& blockSize, int m, vector<int>& processSize, int n) {
    vector<int> allocation(n, -1); // Initialize allocation array with -1 (not allocated)

    // Allocate each process to the worst-fitting block
    for (int i = 0; i < n; i++) {
        int wstIdx = -1;
        for (int j = 0; j < m; j++) 
        {
            if (processSize[i] <= blockSize[j]) {
                if (wstIdx == -1 || blockSize[wstIdx] < blockSize[j]) {
                    wstIdx = j;
                }
            }
        }

        // If a suitable block is found, allocate the process to that block
        if (wstIdx != -1) {
            allocation[i] = wstIdx;
            blockSize[wstIdx] -= processSize[i];
        }
    }

    // Output the allocation results
    cout << "Process no\tProcess Size\tBlock no." << endl;
    for (int i = 0; i < n; i++) {
        cout << i + 1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1) {
            cout << allocation[i] + 1;
        } else {
            cout << "Not Allocated";
        }
        cout << endl;
    }
}

int main() {
    int m, n;
    cout << "Enter the value of blockSize array and processSize array respectively: ";
    cin >> m >> n;

    vector<int> processSize(n);
    vector<int> blockSize(m);

    cout << "Enter the values in Process size array:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> processSize[i];
    }

    cout << "Enter the values in Block size array:" << endl;
    for (int i = 0; i < m; i++) {
        cin >> blockSize[i];
    }

    worstFit(blockSize, m, processSize, n);

    return 0;
}
