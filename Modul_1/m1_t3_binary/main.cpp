//Даны два массива неповторяющихся целых чисел, упорядоченные по возрастанию. A[0..n­1] и B[0..m­1].
//n >> m. Найдите их пересечение. Требуемое время работы: O(m * log k), где k ­ позиция элементта B[m­1] в
//массиве A.. В процессе поиска очередного элемента B[i] в массиве A пользуйтесь результатом поиска
//элемента B[i­1].
//n, k ≤ 10000.

#include <iostream>

bool bin_search(int *a, int left, int right, int value){
    int middle = 0;
    while(1) {
        middle = (right+left)/2;
        if (value < a[middle]) {
            right = middle - 1;
        } else if (value > a[middle]){
            left = middle + 1;
        } else {
            return true;
        }
        if (left > right)
            return false;
    }
}

int subsearch(int *a, int i_b, int* result, int n, int iter,int *real_size){
    for (int i = iter; i < n ; i*=2) {
        if (a[i] == i_b){
            result[*real_size] = a[i];
            (*real_size)++;
            return i;
        }
        if (a[i] > i_b){
            if(bin_search(a, i/2, i, i_b)){
                result[*real_size] = i_b;
                (*real_size)++;
            }
            return i;
        } else {
            if (i*2 >= n){
                if(bin_search(a, i, n-1, i_b)){
                    result[*real_size] = i_b;
                    (*real_size)++;
                }
                return i;
            }
            continue;
        }
    }
    return 0;
}

int search(int* a, int* b,int* result, int n, int m, int *real_size){
    int iter_for_subsearch = 1;
    for (int i = 0; i < m ; ++i) {
        iter_for_subsearch = subsearch(a, b[i], result, n, iter_for_subsearch,  real_size);
        if(!iter_for_subsearch){
            break;
        }
    }
    return 0;
}

int main() {
    int n, m, real_size = 0;
    std::cin >> n;
    std::cin >> m;
    int *a = new int[n];
    int *b = new int[m];
    int *result = new int[m];
    for (int i = 0; i < n ; ++i) {
        std::cin >> a[i];
    }
    for (int i = 0; i < m ; ++i) {
        std::cin >> b[i];
    }
    search(a, b, result, n, m, &real_size);
    for (int j = 0; j < real_size; ++j) {
        std::cout << result[j] << ' ';
    }
    delete[](a);
    delete[](b);
    return 0;
}