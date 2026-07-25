
// BUBBLE SORT 

#include <iostream>

void bubbleSort(int arr[], int n) {
    // Loop through all array elements
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Swap if the current element is greater than the next
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int numbers[] = {34, 45, 56, 23, 12};
    int n = sizeof(numbers) / sizeof(numbers[0]);

    bubbleSort(numbers, n);

    // Print the sorted array
    for (int i = 0; i < n; i++) {
        std::cout << numbers[i] << " ";
    }
    
    return 0;
}