#include <iostream>

//INSERTION SORT

void insertionSort(int arr[], int n) {
    // Start from the second element
    for (int i = 1; i < n; i++) {
        int x = arr[i];      // Element to be inserted
        int j = i - 1;       // Comparing with left element

        // Move greater elements one position infront
        while (j >= 0 && arr[j] > x) {
            arr[j + 1] = arr[j];
            j--;
        }
        // Put x in the correct sorted position
        arr[j + 1] = x;
    }
}

int main() {
    int numbers[] = {5, 1, 12, -5, 16, 2, 12, 14}; 
    int n = sizeof(numbers) / sizeof(numbers[0]);

    insertionSort(numbers, n);

    // Print sorted array
    for (int i = 0; i < n; i++) {
        std::cout << numbers[i] << " ";
    }

    return 0;
}