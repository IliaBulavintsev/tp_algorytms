//Стековые анаграммы.
//Пара слов называется стековой анаграмой, если одно слово можно получить из другого, проведя
//последовательность стековых операций с его буквами (взять очередную букву исходного слова и поместить
//ее в стек; взять букву из стека и добавить ее в конец выходного слова).
//Для заданной пары слов требуется определить, можно ли выполнить последовательность стековых
//операций, переводящую первое слово во второе. Все буквы в слове различные.
//Длина анаграммы ≤ 10000.

#include <iostream>
#include "stdio.h"
#include <string.h>
#include <assert.h>

class Stack{
public:
    Stack(): buffer(0), size(0), real_size(0) {}
    Stack(size_t n): buffer(new char[n]), size(n), real_size(0) {}
    ~Stack();
    char Pop();
    void Push(char);
    bool IsEmpty();
    char GetTop();

private:
    char *buffer;
    size_t size;
    int real_size;
};

Stack::~Stack() {
    delete[](buffer);
}

void Stack::Push(char ch) {
    buffer[real_size] = ch;
    real_size++;
}

char Stack::Pop() {
    if (!IsEmpty()){
        real_size--;
        char ch = buffer[real_size];
        return ch;
    } else
        return -1;
}


bool Stack::IsEmpty() {
    if (real_size > 0)
        return 0;
    else return 1;
}

char Stack::GetTop() {
    if(IsEmpty())
        return -1;
    else
        return buffer[real_size - 1];
}


bool detect (char* str1, char* str2, size_t len){
    char* buffer = new char[len];
    Stack stack(len);
    int iter_buffer = 0;
    for (int i = 0, j = 0; i < len ; ++i) {
        while (j < len + 1){
            if (str1[j] == str2[i]){
                stack.Push(str1[j]);
                buffer[iter_buffer] = stack.Pop();
                iter_buffer++;
                j++;
                break;
            } else if (stack.GetTop() != -1 && stack.GetTop() == str2[i]){
                buffer[iter_buffer] = stack.Pop();
                iter_buffer++;
                break;
            } else {
                stack.Push(str1[j]);
                j++;
            }
        }
    }
    for (int k = 0; k < len ; ++k) {
        if (buffer[k] != str2[k]){
            delete[](buffer);
            return false;
        }
    }
    delete[](buffer);
    return true;
}

int main() {
    char *str1(new char[10001]), *str2(new char[10001]);
    int i = scanf("%s%s", str1, str2);
    if (i!=2 || strlen(str1)!= strlen(str2) ){
        std:: cout << "NO";
    } else {
        std::cout << (detect(str1, str2, strlen(str1)) ? "YES" : "NO");
    }
    delete[](str1);
    delete[](str2);
    return 0;
}