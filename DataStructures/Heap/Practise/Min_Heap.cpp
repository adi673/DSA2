#include <iostream>
using namespace std;

class MinHeap {
public:
    int arr[101]; // Assuming max heap size is 100
    int size;

    MinHeap() {
        size = 0;
        arr[0] = -1; // Sentinel value
    }

    void insert(int n) {
        size = size + 1;
        arr[size] = n;

        int index = size;
        while (index > 1 && arr[index / 2] > arr[index]) {
            swap(arr[index], arr[index / 2]);
            index = index / 2;
        }
    }

    void removeMin() {
        if (size == 0) {
            cout << "Heap underflow" << endl;
            return;
        }

        swap(arr[1], arr[size]);
        size--;
        Heapify(arr, size, 1);
    }

    void Heapify(int arr[], int n, int i) {
        int smallest = i;
        int leftIndex = 2 * i;
        int rightIndex = 2 * i + 1;

        if (leftIndex <= n && arr[leftIndex] < arr[smallest]) {
            smallest = leftIndex;
        }

        if (rightIndex <= n && arr[rightIndex] < arr[smallest]) {
            smallest = rightIndex;
        }

        if (smallest != i) {
            swap(arr[i], arr[smallest]);
            Heapify(arr, n, smallest);
        }
    }

    void HeapSort(int arr[], int n) {
        for (int i = n / 2; i >= 1; i--) {
            Heapify(arr, n, i);
        }

        int size = n;
        while (size >= 2) {
            swap(arr[1], arr[size]);
            size--;
            Heapify(arr, size, 1);
        }
    }

    void printHeap() {
        for (int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MinHeap heap;
    heap.insert(12);
    heap.insert(11);
    heap.insert(13);
    heap.insert(5);
    heap.insert(6);
    heap.insert(7);

    cout << "Heap before sorting: ";
    heap.printHeap();

    heap.HeapSort(heap.arr, heap.size);

    cout << "Heap after sorting: ";
    heap.printHeap();

    return 0;
}
