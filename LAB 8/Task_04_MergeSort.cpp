#include <iostream>

/* MERGE SORT:
  - Concept: A "Divide and Conquer" algorithm
  - Step 1 (Divide): Cut the unsorted array in half repeatedly
  - Step 2 (Base Case): Stop when sub-lists have only 1 element
  - Step 3 (Conquer/Merge): Stitch adjacent pairs back together in sorted order[
  - Time Complexity: O(n log n)
*/

// COMBINE STEP: Merges two pre-sorted half
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create sub-lists
    int* L = new int[n1];
    int* R = new int[n2];

    // Fill sub-lists
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    
    // Sort items into main array
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    // Grab leftovers
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    // Free memory
    delete[] L;
    delete[] R;
}

// DIVIDE STEP: Splits array and trigger merge
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        // Find cut point
        int mid = left + (right - left) / 2;

        // Split left, then right
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Combine them back
        merge(arr, left, mid, right);
    }
}

int main() {

    int numbers[] = {724, 521, 2, 98, 529, 31, 189, 451}; 
    int n = sizeof(numbers) / sizeof(numbers[0]);

    // Run sort
    mergeSort(numbers, 0, n - 1);

    // Print output
    for (int i = 0; i < n; i++) {
        std::cout << numbers[i] << " ";
    }

    return 0;
}