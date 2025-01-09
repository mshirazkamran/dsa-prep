#include <iostream>
using namespace std;

// Max Heap class
class MaxHeap {
    int *heapArray; // Array to store heap elements
    int capacity;   // Maximum capacity of the heap
    int heapSize;   // Current number of elements in the heap

public:
    // Constructor to initialize heap
    MaxHeap(int cap) {
        capacity = cap;
        heapSize = 0;
        heapArray = new int[cap];
    }

    // Function to get the parent index of a node
    int parent(int i) {
        return (i - 1) / 2; 
    }

    // Function to get the left child index of a node
    int left(int i) { 
        return 2 * i + 1; 
    }

    // Function to get the right child index of a node
    int right(int i) { 
        return 2 * i + 2; 
    }

    // Function to insert a new key into the heap
    void insert(int key) {
        if (heapSize == capacity) {
            cout << "Heap overflow\n";
            return;
        }

        // Insert the new key at the end
        int i = heapSize++;
        heapArray[i] = key;

        // Fix the max heap property by moving up the tree
        while (i != 0 && heapArray[parent(i)] < heapArray[i]) {
            swap(heapArray[i], heapArray[parent(i)]);
            i = parent(i);
        }
    }

    // Function to remove and return the maximum element
    int extractMax() {
        if (heapSize <= 0) return INT_MIN; // Heap is empty
        if (heapSize == 1) return heapArray[--heapSize]; // Only one element

        // Store the maximum element
        int root = heapArray[0];

        // Replace root with the last element and reduce heap size
        heapArray[0] = heapArray[--heapSize];

        // Fix the max heap property
        maxHeapify(0);

        return root;
    }

    // Function to maintain max heap property
    void maxHeapify(int i) {
        int largest = i;           // Initialize largest as root
        int l = left(i);           // Left child index
        int r = right(i);          // Right child index

        // Check if left child is larger than root
        if (l < heapSize && heapArray[l] > heapArray[largest])
            largest = l;

        // Check if right child is larger than the largest so far
        if (r < heapSize && heapArray[r] > heapArray[largest])
            largest = r;

        // If the largest is not root, swap and continue heapifying
        if (largest != i) {
            swap(heapArray[i], heapArray[largest]);
            maxHeapify(largest);
        }
    }

    // Function to display the heap elements
    void display() {
        for (int i = 0; i < heapSize; i++)
            cout << heapArray[i] << " ";
        cout << endl;
    }
};

int main() {
    MaxHeap heap(10); // Create a max heap with capacity 10

    // Insert elements into the heap
    heap.insert(10);
    heap.insert(20);
    heap.insert(5);
    heap.insert(6);
    heap.insert(1);

    cout << "Max Heap: ";
    heap.display();

    // Extract the maximum element
    cout << "Extracted Max: " << heap.extractMax() << endl;

    cout << "Max Heap after extraction: ";
    heap.display();

    return 0;
}
