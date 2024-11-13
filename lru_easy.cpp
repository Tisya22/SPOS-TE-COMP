#include <iostream>
#include <vector>
#include <unordered_set>
#include<bits/stdc++.h>

using namespace std;

void lruPageReplacement(const vector<int>& pages, int capacity) {
    vector<int> frame;      // Holds the pages in memory (vector instead of list)
    unordered_set<int> frameSet;  // For fast lookups to check if the page is already in memory
    int pageFaults = 0;

    for (int page : pages) {
        // If page is not in frame
        auto it = find(frame.begin(), frame.end(), page);

        if (it == frame.end()) {
            // If frame is full, remove the least recently used (front of the vector)
            if (frame.size() == capacity) {
                frame.erase(frame.begin());
                frameSet.erase(frame[0]); // Remove from set
            }
            // Add the new page to the end of the vector
            frame.push_back(page);
            frameSet.insert(page); // Add page to set
            pageFaults++;
        } else {
            // If the page is already in the frame, move it to the end (mark as recently used)
            frame.erase(it);     // Remove the page
            frame.push_back(page); // Insert the page at the end
        }

        // Display frame contents after each page access
        cout << "Frame Contents: ";
        for (int p : frame) {
            cout << p << " ";
        }
        cout << std::endl;
    }

    cout << "No. of page faults: " << pageFaults << std::endl;
}

int main() {
    int n, capacity;
    cout << "Enter the value of n: ";
    cin >> n;

    vector<int> pages(n);
    cout << "Enter the page numbers:\n";
    for (int i = 0; i < n; i++) {
        cin >> pages[i];
    }

    cout << "Enter the number of frames: ";
    cin >> capacity;

    lruPageReplacement(pages, capacity);

    return 0;
}
