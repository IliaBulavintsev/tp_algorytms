//1_1. Ящики.
//На склад привезли много пустых ящиков. Все ящики пронумерованы по порядку поступления от 0.
//Известно, что их все можно сложить один в один (то есть так, что каждый следующий помещается в
//предыдущий). Один ящик можно вложить в другой, если его можно перевернуть так,
//что размеры одного ящика по всем осям станут строго меньше размеров другого ящика по соответствующим осям.
//Требуется определить, в какой последовательности они будут вложены друг в друга. Вывести номера ящиков.

#include <iostream>
#include "assert.h"

template <class a_type>
class Box {
public:
    Box(){ }
    ~Box() { }
    void Set(a_type x, a_type y, a_type z, a_type index) {
        _x[0] = x;
        _x[1] = y;
        _x[2] = z;
        _index = index;

    }
    bool operator<(Box const & right){
        return  (this->_x[0] < right._x[0] && this->_x[1] < right._x[1] && this->_x[2] < right._x[2]);
    }
    void Print_Index();
    a_type _x[3];
    a_type _index;
};

template <class a_type>
void Box<a_type>::Print_Index() {
     std::cout << _index << " ";
}

template <typename T>
void insertion_sort(T *arr, int size){
    for (int i = 1; i < size; ++i) {
        T tmp = arr[i];
        int k = i;
        for (; k > 0 && tmp < arr[k-1] ; --k) {
            std::swap(arr[k], arr[k-1]);
        }

    }
}

int main(){
    int n;
    std::cin >> n;
    assert(n > 0);
    Box<int> *boxes = new Box<int>[n];
    for (int i = 0; i < n; ++i) {
        int x, y, z;
        std::cin >> x >> y >> z;
        assert(x > 0 && y > 0 && z > 0);
        boxes[i].Set(x, y, z, i);
    }
    for (int j = 0; j < n ; ++j) {
        insertion_sort(boxes[j]._x, 3);
    }
    insertion_sort(boxes, n);
    for (int k = 0; k < n; ++k) {
        boxes[k].Print_Index();
    }
    delete[](boxes);
    return 0;
}