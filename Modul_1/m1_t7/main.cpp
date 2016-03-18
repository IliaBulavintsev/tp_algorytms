//В большой IT­фирме есть только одна переговорная комната. Желающие посовещаться заполняют заявки с
//желаемым временем начала и конца. Ваша задача определить максимальное количество заявок, которое
//может быть удовлетворено.
//Число заявок  ​
//≤ 100000.
//
#include <iostream>
#include <cstdlib>
#include "stdio.h"

void qs (int * array, int left, int right, int * array_b) {
    int i = left, j = right;
    int med = array[(left + right)/2];

    while (i <= j) {
        while (array[i] < med)
            i++;
        while (array[j] > med)
            j--;
        if (i <= j) {
            std::swap(array[i], array[j]);
            std::swap(array_b[i], array_b[j]);
            i++;
            j--;
        }
    }
    if (left < j)
        qs(array, left, j, array_b);
    if (i < right)
        qs(array, i, right, array_b);
}

int max(int *array, int *array_b, int n){
    int  res = 1, tmp = array_b[0];

    for (int i = 1; i <n ; ++i) {
        if(array[i]-array_b[i] >= 0){
            continue;
        }
        if (tmp <= array[i] ) {
            if (array_b[i] > array[i + 1] && array_b[i] > array_b[i+1] && i != n-1)
                continue;
            else {
                res++;
                tmp = array_b[i];
                continue;
            }
        }
        if (tmp > array[i] && tmp > array_b[i]) {
            tmp = array_b[i];
            continue;
        }
        if (array[i] == array[i-1] && array_b[i] < tmp) {
            tmp = array_b[i];
            continue;
        }
    }
    return res;
}

int main() {
    int n = 2;
    int *array = new int[n];
    int *array_b = new int[n];
    int i = 0, j = 0 , z = 0 ;
    int i_scanf =0;
    while (1) {
        i_scanf = scanf("%d%d", &j, &z);
        if (i_scanf !=2)
            break;
        if (i>=n){
            n*=2;
            array = (int*) realloc(array, n * sizeof(int));
            array_b = (int*) realloc(array_b, n * sizeof(int));
        }
        array[i] = j;
        array_b[i] = z;
        i++;
    }
    if (!i) {
        std::cout << i;
        return 0;
    }
    qs(array, 0, i-1, array_b);
    std::cout << max(array, array_b, i);
    delete[](array);
    delete[](array_b);
    return 0;
}