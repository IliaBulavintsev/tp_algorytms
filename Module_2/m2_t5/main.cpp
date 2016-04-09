#include <iostream>
#include <vector>
#include <stdint.h>

template <typename T>
T Merge(std::vector<T> *a, std::vector<T> *b, unsigned long na, unsigned long nb, std::vector<T> *c){
    T res = 0;
    unsigned long i = 0, j = 0;
    while (i < na && j < nb){
        if (a[i] <= b[j]){
            c[i + j] = a[i];
            ++i;
            ++res;
        } else {
            c[i + j] = b[i];
            ++j;
            ++res;
        }
    }
    if (i < na){
        while (i < na){
            c[i + j] = a[i];
            ++i;
        }
    }
    if (j < nb){
        while (j < nb){
            c[i + j] = a[j];
            ++j;
        }
    }
    return res;
}
template <typename T>
T MergeSort(std::vector<T> *arr, unsigned long size){
    T res = 0;
    if (size < 2)
        return 0;
    if (size == 2){
        if (arr[0] > arr[1]){
            std::swap(arr[0], arr[1]);
            return  1;
        } else {
            return 0;
        }
    }
    res += MergeSort(arr, size/2);
    res += MergeSort(arr + size/2, size - size/2);
    std::vector<T> arr_merge(size);
    res +=Merge(arr,  arr + size/2, size/2, size - size/2, &arr_merge);
    return res;
}

int main() {
    std::vector<int64_t> v;
    int64_t buf;
    while(std::cin >> buf){
        v.push_back(buf);
    }
   std::cout << MergeSort(&v, v.size());
    return 0;
}