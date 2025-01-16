// Iterative binary search function
int binarySearchIterative(int arr[], int size, int target) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // Calculate the middle index

        // Check if the middle element is the target
        if (arr[mid] == target) {
            return mid;
        }

        // If target is smaller, search in the left half
        if (target < arr[mid]) {
            right = mid - 1;
        }
        // If target is larger, search in the right half
        else {
            left = mid + 1;
        }
    }

    return -1; // Element not found
}
