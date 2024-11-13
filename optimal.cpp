#include <iostream>
#include <vector>
using namespace std;

bool search(int key, const vector<int>& fr) {
    for (int it : fr) {
        if (it == key) return true;
    }
    return false;
}

int predict(const vector<int>& pg, const vector<int>& fr, int pn, int index) {
    int res = -1;
    int farthest = index;
    for (int i = 0; i < fr.size(); i++) {
        int j;
        for (j = index; j < pn; j++) {
            if (fr[i] == pg[j]) {
                if (j > farthest) {
                    farthest = j;
                    res = i;
                }
                break;
            }
        }
        if (j == pn) {
            return i;
        }
    }
    return (res == -1) ? 0 : res;
}

void optimalPage(const vector<int>& pg, int pn, int fn) {
    vector<int> fr;
    int hit = 0;
    
    // Load the first frames
    for (int i = 0; i < fn; i++) {
        fr.push_back(pg[i]);
        cout << "Page " << pg[i] << " added to frame. Frame Contents: ";
        for (int f : fr) cout << f << " ";
        cout << endl;
    }

    // Process remaining pages
    for (int i = fn; i < pn; i++) {
        if (search(pg[i], fr)) {
            hit++;
            cout << "Page " << pg[i] << " is in the frame. Frame Contents: ";
            for (int f : fr) cout << f << " ";
            cout << endl;
        } else {
            int j = predict(pg, fr, pn, i + 1);
            fr[j] = pg[i];  // Replace the page
            cout << "Page " << pg[i] << " is not in the frame. Frame Contents: ";
            for (int f : fr) cout << f << " ";
            cout << endl;
        }
    }

    // Output the result
    cout << "No. of hits = " << hit << endl;
    cout << "No. of misses = " << (pn - hit) << endl;
}

int main() {
    int pn, fn;
    cout << "Enter the number of pages: ";
    cin >> pn;

    vector<int> pg(pn);
    cout << "Enter the page numbers: ";
    for (int i = 0; i < pn; i++) {
        cin >> pg[i];
    }

    cout << "Enter the number of frames: ";
    cin >> fn;

    optimalPage(pg, pn, fn);

    return 0;
}