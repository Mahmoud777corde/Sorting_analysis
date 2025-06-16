
#include <iostream>
#include <cstdlib>
#include <chrono>
using namespace std;
using namespace std::chrono;

// merge function without fixed size array
void merge(int* A, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++)
        L[i] = A[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = A[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            A[k++] = L[i++];
        } else {
            A[k++] = R[j++];
        }
    }

    while (i < n1)
        A[k++] = L[i++];
    while (j < n2)
        A[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void mergeSort(int* A, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(A, l, m);
        mergeSort(A, m + 1, r);
        merge(A, l, m, r);
    }
}


int main()
{
    int n, c;
    cin >> n >> c;
    int* A = new int[n];

    for (int i = 0; i < n; i++) {
        if (c == 1)
            A[i] = rand() % 200;
        else if (c == 2)
            A[i] = i;
        else if (c == 3)
            A[i] = n - i;
    }

    auto start = high_resolution_clock::now();
    mergeSort(A, 0, n - 1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Execution Time: " << duration.count() << " ms" << endl;
}
