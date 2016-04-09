#include <iostream>
#include "assert.h"

struct Point{
    int _val;
    bool _isEnd;
    Point(): _val(0), _isEnd(false) {}
    Point(int val, bool isEnd): _val(val), _isEnd(isEnd) {}
    bool operator<(Point const & right){
        return _val < right._val;
    }
};

template <typename T>
void siftDown(T *arr, int index, int size){
    for (int i = index; 2*i+2 <= size; ) {
        int left = 2*i + 1;
        int right = 2*i + 2;
        int largest = i;

        if (left < size && arr[largest] < arr[left])
            largest = left;
        if (right < size && arr[largest] < arr[right])
            largest = right;
        if (i != largest) {
            std::swap(arr[i], arr[largest]);
            i = largest;
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
        std::swap(arr[0], arr[size - j- 1]);
        siftDown(arr, 0, size - j - 1);
    }
}
int count(Point *point, int size){
    int result = 0;
    int fl = 0;
    int start = 0;
    heapSort(point, size);
    for (int i = 0; i < size; ++i) {
        Point tmp = point[i];
        if (fl == 0 && !tmp._isEnd){
            start = tmp._val;
            fl++;
            continue;
        }
        if (fl == 1 && !tmp._isEnd){
            fl++;
            result += tmp._val - start;
            continue;
        }
        if (fl == 2 && tmp._isEnd){
            start = tmp._val;
            fl--;
            continue;
        }
        if (fl == 1 && tmp._isEnd){
            result+= tmp._val - start;
            start = tmp._val;
            fl--;
            continue;
        }
        if (tmp._isEnd){
            fl--;
        } else
            fl++;

    }
    return result;
}
int main() {
    int n;
    std::cin >> n;
    Point *points = new Point[2*n];
    for (int i = 0; i < n*2; ++i) {
        int start, end;
        std::cin >> start >> end;
        assert(start <= end);
        points[i]._val = start;
        points[++i]._val = end;
        points[i]._isEnd = true;
    }
    std::cout << count(points, n*2);
    return 0;
}