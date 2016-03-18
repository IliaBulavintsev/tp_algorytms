/* Copyright 2016 Bulavintsev */
//​Даны две рациональные дроби: a/b и c/d.
//Сложить их и результат представьте в виде несократимой
//дроби m/n. Вывести числа m и n.
//a, b, c, d ≤ 1000.
#include <iostream>

//НОД
int gcd(int a, int b) {
    return b? gcd(b, a % b) : a;
}

//НОК
int lcm(int a, int b) {
    return a*b/gcd(a, b);
}
int numerator(int &a, int b, int c, int d, int lcm) {
    a*=b;
    c*=d;
    a+=c;
    return gcd(a, lcm);
}
int * result(int* array,int i_lcm,int div){
    array[0]/=div;
    array[1]= i_lcm/div;
    return array;
}
int main() {
    int array_size = 4;
    int *array = new int[array_size];
    for (int i = 0; i <array_size ; ++i) {
        std::cin >> array[i];
    }
    int i_lcm = lcm(array[1], array[3]);
    int gcd = numerator(array[0], i_lcm/array[1], array[2], i_lcm/array[3], i_lcm);
    array = result(array, i_lcm, gcd);
    std::cout << array[0] << " " << array[1];
    delete[](array);
    return 0;
}