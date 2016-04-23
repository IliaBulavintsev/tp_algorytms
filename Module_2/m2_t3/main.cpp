#include <iostream>
#include "assert.h"
template <class a_type>
struct Point{
    a_type _val;
    bool _isEnd;
    Point(): _val(0), _isEnd(false) {}
    Point(int val, bool isEnd): _val(val), _isEnd(isEnd) {}
    ~Point() {}
    bool operator<(Point const & right){
        return _val < right._val;
    }
};

template <typename T>
void siftDown(T *arr, int index, int size){
    for (int i = index; 2*i+2 <= size; ) {
        int left = 2*i + 1;
        int right = 2*i + 2;
        int max = i;

        if (left < size && arr[max] < arr[left])
            max = left;
        if (right < size && arr[max] < arr[right])
            max = right;
        if (i != max) {
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
        std::swap(arr[0], arr[size - j- 1]);
        siftDown(arr, 0, size - j - 1);
    }
}
template <class a_type>
int count(Point <a_type>*point, int size){
    int result = 0;
    int fl = 0;
    int start = 0;
    heapSort(point, size);
    for (int i = 0; i < size; ++i) {
        Point<a_type> tmp = point[i];
        if (fl == 0){
            fl++;
            start = tmp._val;
        } else {
            if (tmp._isEnd) fl--;
            else fl++;
        }
        if (fl == 0)
            result += (tmp._val - start);

    }
    return result;
}

int main() {
    int n;
    std::cin >> n;
    Point<int> *points = new Point<int>[2*n];
    for (int i = 0; i < n*2; ++i) {
        int start, end;
        std::cin >> start >> end;
        assert(start <= end);
        points[i]._val = start;
        points[++i]._val = end;
        points[i]._isEnd = true;
    }
    std::cout << count(points, n*2);
       delete []points;

    return 0;
}