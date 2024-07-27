// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;


class MaxHeap{
    public:
    int arr[101];
    int size;
    
    MaxHeap(){
        size=0;
        arr[0]=-1;
    }
    
    void insert(int n){
        size=size+1;
        arr[size]=n;
        
        int index=size;
        while(index>1 && arr[index/2]<arr[index]){
            swap(arr[index],arr[index/2]);
            index=index/2;
        }
    }
    
    void delet(){
        if (size == 0) {
            cout << "Heap underflow" << endl;
            return;
        }
        
        swap(arr[size],arr[1]);
        size--;
        int index=1;
        
        while(index<=size){
            int largest=index;
            int leftIndex=2*index;
            int rightIndex=2*index+1;
            
            if(leftIndex<=size && arr[largest]<arr[leftIndex]){
                largest=leftIndex;
            }
            
            if(rightIndex<=size && arr[largest]<arr[rightIndex]){
                largest=rightIndex;
            }
            
            if(index!=largest){
                swap(arr[largest], arr[index]);
            }else{
                break;
            }
        }
    }
    
    
    void Heapify(int arr[], int n, int i){
        int largest=i;
        int leftIndex=2*i;
        int rightIndex=2*i+1;
            
        if(leftIndex<=n && arr[largest]<arr[leftIndex]){
            largest=leftIndex;
        }
            
        if(rightIndex<=n && arr[largest]<arr[rightIndex]){
            largest=rightIndex;
        }
            
        if(i!=largest){
            swap(arr[largest], arr[i]);
            Heapify(arr,n,largest);
        }
            
    }
   
    
    void HeapSort(int arr[], int n){
        for (int i = n / 2; i > 0; i--) {
            Heapify(arr, n, i);
        }
        
        int size=n;
        while(size>1){
            swap(arr[size],arr[1]);
            size--;
            Heapify(arr,size,1);
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
    MaxHeap heap;
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