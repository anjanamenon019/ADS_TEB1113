#include <iostream>

// SELECTION SORT 

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minj = i; // Track index of minimum element

        // Find minimum element in remaining unsorted array
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minj]) {
                minj = j; // Update index if  found smaller element
            }
        }

        // Swap new minimum element with first unsorted element
        int temp = arr[minj];
        arr[minj] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int numbers[] = {5, 1, 12, -5, 16, 2, 12, 14}; 
    int n = sizeof(numbers) / sizeof(numbers[0]);

    selectionSort(numbers, n);

    // Print sorted array
    for (int i = 0; i < n; i++) {
        std::cout << numbers[i] << " ";
    }

    return 0;
}