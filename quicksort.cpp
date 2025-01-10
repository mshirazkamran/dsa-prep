#include <iostream>
using namespace std;

// Partition the array using the first element as the pivot
int partition(int arr[], int low, int high) {
    int pivot = arr[low];  // Select the pivot as the first element
    int i = low;           // i is the smaller element index
    int j = high;          // j is the larger element index

    // Move i and j towards each other until they cross
    while (i < j) {
        // Increment i until you find an element larger than the pivot
        while (arr[i] <= pivot && i < high) {
            i++;
        }

        // Decrement j until you find an element smaller than the pivot
        while (arr[j] > pivot) {
            j--;
        }

        // If i < j, swap arr[i] and arr[j]
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }

    // Swap the pivot element at low with arr[j]
    swap(arr[low], arr[j]);

    return j;  // Return the pivot index after placing it in the correct position
}

// Recursive quick sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Partition the array and get the pivot index
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Example usage of quick sort
int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}
