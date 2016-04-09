//Сортировка подсчетом
//
#include <iostream>
#include <vector>
#include <string.h>

void countSort(int *data, int n){

    int minValue = data[0];
    int maxValue = data[0];
    for (int i = 0; i < n; ++i) {
        minValue = std::min(minValue, data[i]);
        maxValue = std::max(maxValue, data[i]);
    }
    int valuesCount = maxValue - minValue + 1;
    int * valuesData = new int [valuesCount];
    memset(valuesData, 0, valuesCount * sizeof(int));

    for (int j = 0; j < n; ++j) {
        valuesData[data[j] - minValue]++;
    }
//НЕСТАБИЛЬНО
//    int index = 0;
//    for (int k = 0 k < valuesCount; ++k) {
//        for (int i = 0; i <valuesData[k] ; ++i) {
//            data[index] = minValue + k;
//            index++;
//        }
//    }

//СТабильно
    for (int i = 0; i < valuesCount; ++i) {
        valuesData[i] += valuesData[i-1];
    }
    int *tmp = new int[n];
    for (int i = n - 1; i >= 0; --i) {
        int value = data[i] - minValue;
        valuesData[value]--;
        int valuePos = valuesData[value];
        tmp[valuePos] = data[i];
    }
    memcpy(data, tmp, n * sizeof(int));
//
    delete(tmp);
    delete valuesData;
}

int main() {
    std::vector<int> arr;
    int value = 0;
    while (std::cin >> value){
        arr.push_back(value);
    }

    countSort(&arr[0], arr.size());
    for (int i = 0; i < arr.size() ; ++i) {
        std::cout << arr[i] << ", ";
    }
    return 0;
}