//Дано N кубиков. Требуется определить каким количеством способов можно
//выстроить из этих кубиков пирамиду.
//Широкая пирамида.​
//Каждый вышележащий слой пирамиды должен быть строго меньше
//нижележащего.

#include <iostream>
#include <cassert>

unsigned long long count(int n){
    long long **table = new long long* [n];
    unsigned long long result = 0;
    if (n<=2){
        delete[](table);
        return 1;
    }
    for (int i = 0; i < n ; ++i) {
        table[i] =new long long[n];
    }
    for (int i1 = 0; i1 < n ; ++i1) {
        for (int i = 0; i < n ; ++i) {
          table[i1][i] = 0;
        }
    }
    table[0][0]=1;
    table[1][0]=0;
    table[1][1]=1;
    int buffer = 0;
    if (n >= 2) {
        for (int i = 2; i < n; ++i) {
            table[i][i] = 1;
            for (int j = i-1; j >= 0 ; --j) {
                buffer = i - j -1;
                if (buffer < i/2){
                    for (int k = 0; k <= buffer ; ++k) {
                        table[i][j]+= table[buffer][k];
                    }
                } else{
                    for (int k = 0; k < j; ++k) {
                        table[i][j]+= table[buffer][k];
                    }
                }
            }
        }
    }
    for (int l = 0; l < n; ++l) {
        result+=table[n-1][l];
    }
    for (int m = 0; m < n; ++m) {
        delete  []table[m];
    }
    delete[](table);

    return result;
}


int main() {
    int n;
    std::cin >> n;
    assert( n > 0 );
    std::cout << count(n);

//    for (int i = 1; i < 501; ++i) {
//        std::cout << i << " - " << count(i) << "\n";
//    }
    return 0;
}