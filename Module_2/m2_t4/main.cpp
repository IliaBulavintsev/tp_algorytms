//​Даны неотрицательные целые числа n,k и массив целых чисел из [0..10^9] размера n. Требуется
//найти k­ю порядковую статистику. т.е. напечатать число, которое бы стояло на позиции с индексом k
//(0..n­1) в отсортированном массиве.
//Реализуйте стратегию выбора опорного элемента “медиана трёх”. Функцию Partition реализуйте
//методом прохода двумя итераторами от начала массива к концу.


#include <iostream>
#include <assert.h>
template <typename T>
T med (T *arr, int a, int b, int c)
{
    if (arr[a] > arr[b]) {
        if (arr[c] > arr[a])
            return a;
        return (arr[b] > arr[c]) ? b : c;
    }
    if (arr[c] > arr[b])
        return b;
    return (arr[a] > arr[c]) ? a : c;
}

template <typename T>
void  quicksort(T *arr, int start,int end){
    if (end - start == 1)
        return;
    std::swap(arr[end - 1], arr[med(arr,start, (start + end - 1)/2, end - 1)]);
    int i = start, j = start, buf = arr[end - 1];
    while (j != end - 1) {
        if (arr[j] <= arr[end - 1]){
            std::swap(arr[i], arr[j]);
            i++;
            j++;
        } else {
            j++;
        }
    }
    std::swap(arr[end - 1], arr[i]);
    if (start < i - 1){
        quicksort(arr, start, i);
    }
    if (end - 1 > i + 1){
        quicksort(arr, i, end);
    }
}

int main() {
    int n, m;
    std::cin >> n >> m;
    assert(n >= 0 && m >= 0);
    int *arr = new int[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    quicksort(arr, 0 , n);
    std::cout << arr[m];
    delete[](arr);
    return 0;
}