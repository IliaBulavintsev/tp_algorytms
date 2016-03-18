//​
//Реализовать очередь с помощью двух стеков. Использовать стек, реализованный с помощью
//динамического буфера.

#include <iostream>
#include <cstdio>
#include <cstdlib>

class Stack {
public:
    Stack():  head(NULL), size(0), real_size(0) {}
    Stack(int n): head(new int[n]) ,size(n), real_size(0) {}
    ~Stack();
    void Push(int);
    int Pop();
    bool is_Empty();
    int Real_size();
    int Size();

private:
    int* head;
    int size;
    int real_size;
};

Stack::~Stack() {
    delete[](head);
}
void Stack::Push(int n) {
    head[real_size] = n;
    real_size++;
}
int Stack::Pop() {
    real_size--;
    int res = head[real_size];
    return res;
}
bool Stack::is_Empty(){
    if (real_size == 0){
        return true;
    } else {
        return 0;
    }
}
int Stack::Real_size(){
    return real_size;
}
int Stack::Size() {
    return size;
}



class Queue{
public:
    Queue(int n);
    ~Queue();

    void Enqueue(int data);
    int Dequeue();
    void Moove_data();

private:
    Stack *left;
    Stack *right;
};
Queue::~Queue() {
    left->~Stack();
    right->~Stack();
//    delete(left);
//    delete(right);
}
Queue::Queue(int n) : left(new Stack(n)), right(new Stack(n)) {}

void Queue::Enqueue(int data) {
    if (left->Real_size() < left->Size()) {
        left->Push(data);
    }
}

int Queue::Dequeue() {
    if (left->is_Empty() && right->is_Empty()){
        return -1;
    }
    if (right->is_Empty() && !(left->is_Empty())){
        Moove_data();
        return right->Pop();
    }
    if (!right->is_Empty()){
        return right->Pop();
    }
}

void Queue::Moove_data() {
//    for (int i = 0; i < left->Real_size(); ++i) {
    while (!left->is_Empty()) {
        right->Push(left->Pop());
    }
}

int main() {
    bool result = true;
    int n = 0;
    std::cin >> n;
    int num_operation = 0, number = 0, i_result;
    Queue queue(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> num_operation >> number ;
        switch ( num_operation ) {
            case 2:
                i_result = queue.Dequeue();
                if(i_result != number)
                    result = false;
                break;
            case 3:
                queue.Enqueue(number);
                break;
        }
    }
    std::cout << (result ? "YES" : "NO");
    return 0;
}