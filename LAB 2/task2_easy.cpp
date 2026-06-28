// EASY
// Sort matrix in increasing order

#include <bits/stdc++.h>
using namespace std;
#define N 3

// Sort order
void sortAllWay(int arr[][N]) {
    // Treat the 2D array as a 1D list and sort 
    int *ptr = (int *)arr;
    sort(ptr, ptr + N * N);
}

int main() {
    // Unsorted numbers
    int arr[N][N] = {7, 2, 9,
                     1, 5, 3,
                     8, 4, 6};

    sortAllWay(arr);

    // Display sorted matrix
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << arr[i][j] << " ";
        cout << "\n";
    }

    return 0;
}