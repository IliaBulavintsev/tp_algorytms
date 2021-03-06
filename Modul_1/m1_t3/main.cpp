#include <iostream>

int intersection(int* a, int* b, int n, int m){
    int buffer = 0;
    for (int i = 0; i < n ; ++i) {
        if (a[i] < b[buffer])
           continue;
        if (a[i] == b[buffer]){
            std::cout << a[i] << " ";
            if(buffer >= m-1)
                break;
            else {
                buffer++;
                continue;
            }
        }
        if (a[i] > b[buffer]){
            while(buffer < m-1){
                buffer++;
                if(b[buffer] > a[i]){
                    break;
                }
                if (b[buffer] == a[i]){
                    std::cout << a[i] << " ";
                    break;
                }
            }
        }
    }
    return 0;
}

int main() {
    int n = 0, m = 0;
    std::cin >> n;
    std::cin >> m;
    int *array_a = new int[n];
    int *array_b = new int[m];
    for (int i = 0; i < n ; ++i) {
        std::cin >> array_a[i];
    }
    for (int i = 0; i < m ; ++i) {
        std::cin >> array_b[i];
    }
    intersection(array_a, array_b, n, m);
    delete[](array_a);
    delete[](array_b);
    return 0;
}