#include <iostream>
#include <cstdlib>
#include <chrono>
using namespace std;
using namespace chrono;

// Bubble Sort Function
void BubbleSort(int &n, int A[]) {
    for (int i = 0; i < n - 1; i++) {
        bool b = false;
        for (int j = 1; j < n - i; j++) {
            if (A[j - 1] > A[j]) {
                int temp = A[j - 1];
                A[j - 1] = A[j];
                A[j] = temp;
                b = true;
            }
        }
        if (b == false)
            return;
    }
}

int main() {
    int n, c;
    cout << "Enter array size: ";
    cin >> n;
    cout << "Enter data type (1=Random, 2=Sorted, 3=Reverse): ";
    cin >> c;

    int A[n];
    for (int i = 0; i < n; i++) {
        if (c == 1)
            A[i] = rand() % 200;
        else if (c == 2)
            A[i] = i;
        else if (c == 3)
            A[i] = n - i;
    }

    auto start = high_resolution_clock::now();
    BubbleSort(n, A);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Execution Time: " << duration.count() << " milliseconds" << endl;

    return 0;
}
