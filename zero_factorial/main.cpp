#include <iostream>

int calcul(int n){
    return n/5+n/25;

}

int main() {
    int n=0;
    std::cin>>n;
    std::cout<<calcul(n);
    return 0;
}