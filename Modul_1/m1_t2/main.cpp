//Copyright 2016 Bulavintsev
//​Даны два массива целых чисел одинаковой длины A[0..n­1] и B[0..n­1].
//Необходимо найти первую пару индексов i0 и j0, i0 ≤ j0,
//такую что A[i0] + B[j0] = max {A[i] + B[j], где 0 <= i < n, 0 <= j < n, i <= j}.
//Время работы ­ O(n).
//n ≤ 100000.
#include <iostream>

//search index
int search(int *array_a, int *array_b, int *n) {
    int a_place = 0;
    int b_place = 0;
    int buffer = 0;
    int max = array_a[a_place] + array_b[b_place];
    for (int i = 1; i <*n ; ++i) {
        if (array_a[buffer] < array_a[i]) {
            buffer = i;
        }
        if (max < array_a[buffer] + array_b[i]) {
            max = array_a[buffer] + array_b[i];
            a_place = buffer;
            b_place = i;
        }
    }
    *n = b_place;
    return a_place;
}
int main() {
    int n = 0;
    std::cin >> n;
    int *array_a = new int[n];
    int *array_b = new int[n];
//    std::cout<<"arr_a"<<std::endl;
    for (int i = 0; i < n ; ++i) {
        std::cin >> array_a[i];
    }
//    std::cout<<"arr_b"<<std::endl;
    for (int i = 0; i < n ; ++i) {
        std::cin >> array_b[i];
    }
//    int array_a[4]={4,-8,6,0};
//    int array_b[4]={-10,3,1,1};
    std::cout << search(array_a, array_b, &n) << " ";
    std::cout << n;
    delete[](array_a);
    delete[](array_b);
    return 0;
}