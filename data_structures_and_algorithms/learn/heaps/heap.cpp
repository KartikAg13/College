#include <iostream>
#include <vector>

class MinHeap {
private:
    std::vector<int> heap;

    // Helper function to maintain the heap property after insertion
    void heapifyUp(int index) {
        while (index > 0) {
            int parentIndex = (index - 1) / 2;
            if (heap[index] < heap[parentIndex]) {
                std::swap(heap[index], heap[parentIndex]);
                index = parentIndex;
            } 
            else {
                break;
            }
        }
    }

    // Helper function to maintain the heap property after deletion
    void heapifyDown(int index) {
        int n = heap.size();
        while (true) {
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;
            int smallest = index;

            if (leftChild < n && heap[leftChild] < heap[smallest]) {
                smallest = leftChild;
            }
            if (rightChild < n && heap[rightChild] < heap[smallest]) {
                smallest = rightChild;
            }

            if (smallest != index) {
                std::swap(heap[index], heap[smallest]);
                index = smallest;
            } 
            else {
                break;
            }
        }
    }

public:
    // Insert a new element into the heap
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    // Get the minimum element (root of the heap)
    int getMin() {
        return heap[0];
    }

    // Remove the minimum element (root of the heap)
    void removeMin() {
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    // Print the elements of the heap (for debugging purposes)
    void printHeap() {
        for (int value : heap) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    MinHeap heap;

    // Insert elements into the heap
    heap.insert(10);
    heap.insert(20);
    heap.insert(5);
    heap.insert(15);
    heap.insert(30);

    std::cout << "Heap elements after insertion: ";
    heap.printHeap();

    std::cout << "Minimum element: " << heap.getMin() << std::endl;

    // Remove the minimum element
    heap.removeMin();
    std::cout << "Heap elements after removing the minimum: ";
    heap.printHeap();

    return 0;
}
