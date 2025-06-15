#include <iostream>
#include <cstdlib>
#include <chrono>
using namespace std;
using namespace std::chrono;

int partition(int (&A)[], int l, int r) {
    int pivot = A[l];
    int i = l + 1;
    for (int j = l + 1; j <= r; j++) {
        if (A[j] < pivot) {
            swap(A[i], A[j]);
            ++i;
        }
    }
    swap(A[l], A[i - 1]);
    return i - 1;
}

void quickSort(int (&A)[], int l, int r) {
    if (l < r) {
        int p = partition(A, l, r);
        quickSort(A, l, p - 1);
        quickSort(A, p + 1, r);
    }
}

int main() {
    int n, c;
    cin >> n >> c;
    int A[n];

    for (int i = 0; i < n; i++) {
        if (c == 1)
            A[i] = rand() % 10000;
        if (c == 2)
            A[i] = 1;
        if (c == 3)
            A[i] = n - i;
    }

    auto start = high_resolution_clock::now();
    quickSort(A, 0, n - 1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << duration.count() << " ms" << endl;
    return 0;
}