#include <iostream>
#include <assert.h>
#include <random>

struct Node {
    int Data;
    Node* Next;
    Node() : Data(0), Next(0) {}
    Node(int data) : Data(data), Next(0) {}
};

class Queue{
public:
    Queue();
    ~Queue();

    void Enque(int data);
    int Dequeue();

    bool IsEmpty() const;

private:
    Node* head;
    Node* tail;
};

Queue::Queue() :
        head(0),
        tail(0)
{

}

Queue::~Queue() {
    while ( !IsEmpty() ){
        Dequeue();
    }
}

void Queue::Enque(int data) {
    Node* newNode = new Node(data);
    if (tail == 0){
        assert(head == 0);
        tail = head = newNode;
    } else {
        tail->Next = newNode;
        tail = newNode;
    }
}

int Queue::Dequeue() {
    if (head == 0)
        return -1;
    int data = head->Data;
    if (head == tail) {
        delete(head);
        head = tail = 0;
    } else {
        Node* tmp = head;
        head = head->Next;
        delete(tmp);
    }
    return data;
}

bool Queue::IsEmpty() const {
    return head == 0;
}
//Queue::~Queue() {
//    while ( !IsEmpty() ){
//        Dequeue();
//    }
//}
FILE * f;

void GenerateTest(){

}
int main() {
//    freopen(&f, "Output.txt", "w", stdout);
//    Queue queue;
//    int n = 1000;
//    std::cout << n << "\n";
//    for (int i = 0; i < n ; ++i) {
//        int operation = rand()%2 +2;
//        switch ( operation ) {
//            case 2:
//                std::cout << operation << " " << queue.Dequeue() << "\n";
//                break;
//            case 3:
//                int number = rand();
//                queue.Enque(number);
//                std::cout << operation << " "<< number << "\n";
//                break;
//        }
//    }
    int n = 0;
    std::cin >> n;
    Queue queue;
    bool result = true;
    for (int i = 0; i < n; ++i) {

        int operation = 0;
        std::cin >> operation;
        int number = 0;
        std::cin >> number;
        switch ( operation ) {
            case 2:
                if (number != queue.Dequeue()) {
                    result = false;
                }
                break;
            case 3:
                queue.Enque( number );
                break;
        }
    }

    std::cout << (result ? "YES" : "NO");
    return 0;
}