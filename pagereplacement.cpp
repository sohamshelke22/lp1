#include <iostream>
using namespace std;

int main() {
    int n, frames;
    cout << "Enter number of pages: ";
    cin >> n;

    int pages[n];
    cout << "Enter page reference string:\n";
    for (int i = 0; i < n; i++) cin >> pages[i];
    
    cout << "Enter number of frames: ";
    cin >> frames;

    int mem[frames];     // memory frames
    for (int i = 0; i < frames; i++) mem[i] = -1; // initialize empty

    int faults = 0, next = 0; // next points to FIFO index

    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < frames; j++)
            if (mem[j] == pages[i]) found = true;

        if (!found) {
            mem[next] = pages[i];      // replace oldest page
            next = (next + 1) % frames; // move pointer in circular manner
            faults++;
        }

        // display current memory
        cout << "Frames: ";
        for (int j = 0; j < frames; j++)
            if (mem[j] != -1) cout << mem[j] << " ";
        cout << endl;
    }

    cout << "Total Page Faults: " << faults << endl;
    return 0;
}
