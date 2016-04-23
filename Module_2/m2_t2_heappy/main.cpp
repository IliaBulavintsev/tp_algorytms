#include <iostream>
#include "assert.h"

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

long long count(long long* arr, int size){
    heapSort(arr, size);
    long long result = 0;
    for (int j = size - 1; j > 0 ;) {
        long long a = arr[j];
        long long b = arr[--j];
        result += a + b;
        arr[j] = a + b;
        heapSort(arr, j+1);
    }
    return result;
}
int main() {
    int n = 0;
    std::cin >> n;
    assert(n >= 0);
    long long *arr = new long long[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    std::cout << count(arr, n);
    return 0;
}