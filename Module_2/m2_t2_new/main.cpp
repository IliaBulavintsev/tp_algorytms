#include <iostream>
#include "assert.h"

template <typename T>
void siftDown(T *arr, int index, int size);
class Heap{
public:
    Heap(int n): realsize(n), size(n), heap(new long long[n]) {};
    ~Heap() {}
    int size;
    int realsize;
    long long *heap;
    void SiftDown(int);
    void AddElem(long long);
    long long DelFirstElem();
};

void Heap::AddElem(long long elem) {
    assert(realsize < size);
    heap--;
    heap[0] = elem;
    realsize++;
}

long long Heap::DelFirstElem() {
    assert(realsize > 0);
    SiftDown(0);
    long long ret = heap[0];
    realsize--;
    heap++;
    SiftDown(0);
    return ret;
}

void Heap::SiftDown(int index) {
    for (int i = index; i < realsize;) {
        int tmp = i;
        int left = i*2 + 1;
        int right = i*2 + 2;
        if (left < realsize && heap[left] < heap[tmp]){
            i = left;
        }
        if (right < realsize && heap[right] < heap[tmp] && heap[right] < heap[left]){
            i = right;
        }
        if (tmp == i)
            break;
        else{
            std::swap(heap[i], heap[tmp]);
        }


    }
}


template <typename T>
void siftDown(T *arr, int index, int size){
    for (int i = index; 2*i+2 <= size;) {
        int left = 2*i + 1;
        int right = 2*i + 2;
        int max = i;
        if (left < size && arr[max] < arr[left])
            max = left;
        if (right < size && arr[max] < arr[right])
            max = right;
        if (i != max){
            std::swap(arr[i], arr[max]);
            i = max;
        } else
            break;
    }
}
template <typename T>
void heapSort(T *arr, int size){
    for (int i = size/2 - 1; i >= 0 ; --i) {
        siftDown(arr, i, size);
    }
    for (int j = 0; j < size; ++j) {
        std::swap(arr[0], arr[size - j - 1]);
        siftDown(arr, 0, size - j - 1);
    }
}

long long count(Heap *heap){
    long long res = 0;
    long long a, b;
    while (heap->realsize > 1){
        //heap->SiftDown(0);
        a = heap->DelFirstElem();
        //heap->SiftDown(0);
        b = heap->DelFirstElem();
        res+= a + b;
        heap->AddElem(a+b);
    }
    return res;
}
int main() {
    int n = 0;
    std::cin >> n;
    assert(n >= 0);
    Heap heap(n);
    for (int i = 0; i < n; ++i) {
        long long buf;
        std::cin >> buf;
        if(buf < 0)
            buf = 0 - buf;
        heap.heap[i] = buf;
    }
    heapSort(heap.heap, heap.realsize);
    std::cout << count(&heap);
    return 0;
}