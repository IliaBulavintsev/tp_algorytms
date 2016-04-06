#include <iostream>
class Heap{
public:
    Heap(int n): size(n), buffer(new long long[n]) {}
    ~Heap() {
        delete[](buffer);
    }
    int GetSize(){ return size; }
    long GetElem(int n){ return buffer[n]; }
    void SetElem (long long elem,int n) { buffer[n] = elem; }
    void AddElem (long long elem) { buffer[size] = elem; size++; }
    void SiftDownMinMax(int, int);
    int GetMinIndex(int, int);
    void SiftDownMaxMin(int, int);
    int GetMaxIndex(int, int);
    long long DelLastElem ();
private:
    int size;
    long long *buffer;
};

long long Heap::DelLastElem() {
    size--;
    return buffer[size];
}
int Heap::GetMinIndex(int left, int right) {
    if (GetElem(left) >= GetElem(right))
        return right;
    else
        return left;
}
void Heap::SiftDownMinMax(int n, int size) {
    int max_index = n;
    long long tmp = buffer[n];
    while (true){
        int left = n * 2 + 1;
        int right = n * 2 + 2;
        if ( left < size && right >= size && buffer[left] < tmp)
            max_index = left;
        if (left < size && right < size && buffer[GetMinIndex(left, right)] < tmp)
            max_index = GetMinIndex(left, right);
        if (max_index == n)
            break;
        buffer[n] = buffer[max_index];
        buffer[max_index] = tmp;
        n = max_index;
    }
}
int Heap::GetMaxIndex(int left, int right) {
    if (GetElem(left) >= GetElem(right))
        return left;
    else
        return right;
}
void Heap::SiftDownMaxMin(int n, int size) {
    int max_index = n;
    long long tmp = buffer[n];
    while (true){
        int left = n * 2 + 1;
        int right = n * 2 + 2;
        if ( left < size && right >= size && buffer[left] > tmp)
            max_index = left;
        if (left < size && right < size && buffer[GetMaxIndex(left, right)] > tmp)
            max_index = GetMaxIndex(left, right);
        if (max_index == n)
            break;
        buffer[n] = buffer[max_index];
        buffer[max_index] = tmp;
        n = max_index;
    }
}

long long count (Heap *heap){
    long long result = 0;
    while (heap->GetSize() > 1) {
        long long a = heap->DelLastElem();
        long long b = heap->DelLastElem();
        result+= a;
        result+= b;
        heap->AddElem(a+b);
        heap->SiftDownMaxMin(heap->GetSize() / 2 - 1, heap->GetSize());
    }
    return result;
}

int main() {
    int n;
    std::cin >> n;
    Heap *heap = new Heap(n);
    for (int i = 0; i < n; ++i) {
        long long elem = 0;
        std::cin >> elem;
        if (elem < 0){
            elem = 0 - elem;
        }
       heap->SetElem(elem, i);
    }
    //Create Heap Min
    for (int k = heap->GetSize() / 2 - 1; k >= 0; --k) {
        heap->SiftDownMinMax(k, heap->GetSize());
    }
    //Heap Sort Max
    for (int l = heap->GetSize() - 1; l >= 1 ; --l) {
        long long tmp = heap->GetElem(0);
        heap->SetElem(heap->GetElem(l), 0);
        heap->SetElem(tmp, l);
        heap->SiftDownMinMax(0, l);
    }
//    for (int j = 0; j < heap->GetSize(); ++j) {
//        std::cout << heap->GetElem(j) << " ";
//    }
    std::cout << count(heap);

    return 0;
}