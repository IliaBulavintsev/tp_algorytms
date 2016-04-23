//Сортировка подсчетом
//
#include <iostream>
#include <vector>
#include <string.h>

void countSort(std::vector<std::string> data, int n){
    int *ch = new int[256];
    for (int i = 0; i < n; ++i) {
        std::string str = data[i];
        ch[static_cast<int>(str.at(0))]++;
    }
}



int main() {
    std::vector<std::string> arr;
    std::string str = " ";
    while (std::cin >> str){
        arr.push_back(str);
    }
    for (int i = 0; i < arr.size() ; ++i) {
        std::cout << arr[i] << ", ";
    }
    return 0;
}