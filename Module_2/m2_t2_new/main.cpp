#include <iostream>
#include "assert.h"

class Heap{
public:
    Heap(int n): realsize(n), size(n), heap(new int[n]) {};
    ~Heap() {}
    int size;
    int realsize;
    int *heap;
    void SiftUp(int);
    void AddElem(int);
    int DelLastElem();
};

void Heap::AddElem(int elem) {
    assert(realsize < size);
    heap[realsize] = elem;
    realsize++;
}

int Heap::DelLastElem() {
    assert(realsize > 0);
    realsize--;
    return heap[realsize];
}

void Heap::SiftUp(int index) {
    for (int i = index; i > 0;) {
        if (heap[i] > heap[(i - 1)/2]){
            std::swap(heap[i], heap[(i - 1)/2]);
            i = (i - 1)/2;
        }
        else break;
    }
}

int count(Heap *heap){
    int res = 0;
    int a, b, c;
    while (heap->realsize > 1){
        if (heap->realsize % 2 || heap->realsize == 2) {
            a = heap->DelLastElem();
            b = heap->DelLastElem();
        } else  {
            a = heap->DelLastElem();
            b = heap->DelLastElem();
            c = heap->DelLastElem();
            if (b < c){
                heap->AddElem(c);
            } else {
                heap->AddElem(b);
                b = c;
            }
        }
        res+= a + b;
        heap->AddElem(a+b);
        heap->SiftUp(heap->realsize - 1);
    }
    return res;
}
template <typename T>
void siftUp(T *arr, int index, int size){
    for (int i = index; 2*i+2 <= size;) {
        int left = 2*i + 1;
        int right = 2*i + 2;
        int min = i;
        if (left < size && arr[min] > arr[left])
            min = left;
        if (right < size && arr[min] > arr[right])
            min = right;
        if (i != min){
            std::swap(arr[i], arr[min]);
            i = min;
        } else
            break;
    }
}
template <typename T>
void heapSort(T *arr, int size){
    for (int i = size/2 - 1; i >= 0 ; --i) {
        siftUp(arr, i, size);
    }
    for (int j = 0; j < size; ++j) {
        std::swap(arr[0], arr[size - j - 1]);
        siftUp(arr, 0, size - j - 1);
    }
}
//
//long long count(long long* arr, int size){
//    heapSort(arr, size);
////    for (int i = 0; i <size ; ++i) {
////        std::cout<< arr[i]<<" ";
////    }
////    std::cout<<"_________\n";
//    long long result = 0;
//    for (int j = size - 1; j > 0 ;) {
//        long long a = arr[j];
//        long long b = arr[--j];
//        result += a + b;
//        arr[j] = a + b;
//        heapSort(arr, j+1);
//    }
//    return result;
//}

int main() {
    int n = 0;
    std::cin >> n;
    assert(n >= 0);
    Heap heap(n);
    for (int i = 0; i < n; ++i) {
        int buf;
        std::cin >> buf;
        if(buf < 0)
            buf = 0 - buf;
        heap.heap[i] = buf;
    }
    heapSort(heap.heap, heap.realsize);
//    for (int j = 0; j < heap.realsize ; ++j) {
//        std::cout << heap.heap[j] << " _ ";
//    }
    std::cout << count(&heap);

//    int *arr = new int[n];
//    for (int i = 0; i < n; ++i) {
//        std::cin >> arr[i];
//    }
    //std::cout << count(arr, n);
    return 0;
}