 void Heapify(vector<int>& arr, int n, int i) {
        int largest = i;
        int leftIndex = 2 * i + 1;
        int rightIndex = 2 * i + 2;

        if (leftIndex < n && arr[largest] < arr[leftIndex]) {
            largest = leftIndex;
        }
            
        if (rightIndex < n && arr[largest] < arr[rightIndex]) {
            largest = rightIndex;
        }

        if (largest != i) {
            swap(arr[i], arr[largest]);
            Heapify(arr, n, largest);
        }
    }

    void convertMinToMaxHeap(vector<int> &arr, int N){
        for (int i = N / 2 - 1; i >= 0; i--) {
            Heapify(arr, N, i);
        }
    }