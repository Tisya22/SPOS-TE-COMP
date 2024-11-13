#include<bits/stdc++.h>
using namespace std;

void bestFit(vector<int>& blockSize, int m, vector<int>& processSize, int n){
    vector<int> allocation(n,-1);

    for(int i=0;i<n;i++) // go through each process to compare
    {
        int best_idx=-1;    //stores the index of bext block for current process

        // Check each block to find the smallest one that fits the process
        for(int j=0;j<m;j++)    //go through each block to compare if the process fits into the block, blocksize must be greater and best available
        {
            if(blockSize[j] >= processSize[i]){
                if(best_idx == -1 || blockSize[best_idx] > blockSize[j]){
                    best_idx= j;
                }
            }
        }

            if(best_idx!= -1)
            {
                allocation[i]= best_idx;
                blockSize[best_idx]-=processSize[i];
            }
    }

    //Print Allocation Results
    cout<<"Process No.\tProcess Size\tBlock No."<<endl;
    for(int i=0;i<n;i++){
        cout<<i+1<< "\t\t" << processSize[i] << "\t\t"<<endl;
        if(allocation[i]!=-1){
            cout<<allocation[i]+1<<endl;
        }else{
            cout<<"Not Allocated"<<endl;
        }
    }
}

int main()
{
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

    bestFit(blockSize, m, processSize, n);

    return 0;
}