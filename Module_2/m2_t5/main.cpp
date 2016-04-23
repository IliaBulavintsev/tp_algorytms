#include <iostream>
#include <vector>
#include <stdint.h>


void merge(std::vector<int64_t> &a, unsigned long a_start, unsigned long a_end, unsigned long b_start, unsigned long b_end, std::vector<int64_t> &c, int64_t &counter) {

    unsigned long i=a_start, j=b_start, k = 0;

    for (;i < a_end && j < b_end;) {
        if (a.at(i) <= a.at(j)) {
            c[k] = a.at(i);
            ++k;
            ++i;
        } else {
            counter += a_end - i;
            c[k] = a.at(j);
            ++k;
            ++j;
        }
    }

    if (i==a_end) {
        for (;j < b_end;++j) { c[k] = a.at(j); ++k; }
    } else {
        //counter+= b_end - b_start;
        for (;i < a_end;++i) { c[k] = a.at(i); ++k;}
    }
}

void merge_sort(std::vector<int64_t> &data, unsigned long start, unsigned long end, std::vector<int64_t> &buffer, int64_t &counter) {
    unsigned long size = end - start;
//    int64_t ret = 0;
    if (size < 2) return ;
    merge_sort(data, start, end - size / 2, buffer, counter);
    merge_sort(data, end - size / 2, end, buffer, counter);

    merge(data, 0, end - size / 2, end - size / 2, end, buffer, counter);
    for (size_t pos = start; pos < end; ++ pos) {
        data[pos] = buffer[pos];
    }
}
int main() {
    std::vector<int64_t> v;
    std::vector<int64_t > buf;
    int64_t buff;
    while(std::cin >> buff){
        v.push_back(buff);
        buf.push_back(0);
    }
    int64_t ret = 0;
    merge_sort( v, 0, v.size(), buf, ret);
    std::cout << ret;

    return 0;
}