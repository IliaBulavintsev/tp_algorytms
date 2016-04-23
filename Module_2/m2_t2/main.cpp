#include <iostream>
#include <stdint.h>
#include <assert.h>

class Heap{
public:
    Heap(int64_t s): size(s), realsize(s), heap(new int64_t[s]) {}
    ~Heap(){}
    void AddElem(int64_t elem);
    int64_t DelElem();
    int64_t size;
    int64_t realsize;
    int64_t *heap;
};

void Heap::AddElem(int64_t elem) {
    heap[realsize] = elem;
    realsize++;
}

int64_t Heap::DelElem() {
    int64_t res = heap[0];
    realsize--;
    heap++;
    return res;
}

template <typename T>
void heap_insert(T *a, int64_t n, int64_t x) {
    a[n] = x;
    for (int64_t i = n; i > 1;) {
        if (a[i] > a[i/2]) {
            std::swap(a[i], a[i/2]);
            i = i/2;
        } else {
            break;
        }
    }
}

template <typename T>
void heap_pop(T *a, int64_t n) {
    std::swap(a[n-1],a[0]);
    for (int64_t i = 0; 2*i < n;) {
        i *= 2;
        if (i+1 < n && a[i] < a[i+1]) {
            i += 1;
        }
        if (a[i/2] < a[i]) {
            std::swap(a[i/2], a[i]);
        }
    }
}

template <typename T>
void heap_sort(T *data, int64_t n) {
    T *buff = new T[n];
    for (int64_t i = 0; i < n; ++i) {
        heap_insert(buff, i, data[i]);
    }
    for (int64_t i = 0; i < n; ++i) {
        data[n-1-i] = buff[0];
        heap_pop(buff, n - i);
    }
    delete [] buff;
}


int64_t count (Heap *heap){
    int64_t res = 0;
    while (heap->realsize > 1){
        int64_t a = heap->DelElem();
        int64_t b = heap->DelElem();
        res+= a + b;
        heap->AddElem(a+b);
        heap_sort(heap->heap, heap->realsize);
    }
    return res;
}
int main() {
    int64_t n;
    std::cin >> n;
    Heap *heap = new Heap(n);
    for (int i = 0; i < n; ++i) {
        int64_t elem;
        std::cin >> elem;
        heap->heap[i] = elem;
    }
    heap_sort(heap->heap, n);
    std::cout << count(heap);

    return 0;
}