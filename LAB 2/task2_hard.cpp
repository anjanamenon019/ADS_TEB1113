//HARD
//Matrix Chain Multiplication

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Find min cost of multiplication
int minMultRec(vector<int> &arr, int i, int j) {
    // Base case: only one matrix
    if (i + 1 == j) return 0;

    int res = INT_MAX;

    // Split product at every possible position k
    for (int k = i + 1; k < j; k++) {
        int curr = minMultRec(arr, i, k) + 
                   minMultRec(arr, k, j) + 
                   arr[i] * arr[k] * arr[j];

        res = min(curr, res);
    }
    return res;
}

int matrixMultiplication(vector<int> &arr) {
    return minMultRec(arr, 0, arr.size() - 1);
}

int main() {
    // Array representing dimensions of matrices (10x20, 20x30, 30x40, 40x30)
    vector<int> arr = {10, 20, 30, 40, 30};
    
    cout << "Minimum multiplication cost: " << matrixMultiplication(arr) << endl;
    
    return 0;
}