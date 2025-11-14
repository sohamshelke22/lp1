#include <iostream>
using namespace std;

class Synchronization {
    int buffer[5];     // buffer of size 5
    int mutex = 1;     // binary semaphore (1 means unlocked)
    int empty = 5;     // number of empty slots
    int full = 0;      // number of filled slots

    // semaphore operations
    void wait(int &x) {
        if (x > 0)
            x--;
    }

    void signal(int &x) {
        x++;
    }

public:
    void producer() {
        cout << "Empty: " << empty << " Full: " << full << " Mutex: " << mutex << endl;
        if (empty != 0 && mutex == 1) {
            int item;
            cout << "Data to be produced: ";
            cin >> item;
            wait(empty);
            wait(mutex);

            buffer[full] = item;
            cout << "Data produced: " << item << endl;

            signal(mutex);
            signal(full);
        } else {
            cout << "Producer is waiting… Buffer is full!\n";
        }
    }

    void consumer() {
        cout << "Empty: " << empty << " Full: " << full << " Mutex: " << mutex << endl;
        if (full != 0 && mutex == 1) {
            wait(full);
            wait(mutex);

            int item = buffer[full];
            cout << "Data consumed: " << item << endl;

            signal(mutex);
            signal(empty);
        } else {
            cout <<  "Consumer is waiting… Buffer is empty!\n";
        }
    }
};

int main() {
    Synchronization s;
    int choice;
    do {
        cout << "\n----------- MENU -----------\n";
        cout << "1. Produce\n2. Consume\n3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: s.producer(); break;
            case 2: s.consumer(); break;
            case 3: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 3);

    return 0;
}
