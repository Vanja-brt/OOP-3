#include <iostream>
using namespace std;

class MyVec {
    int size;
    int capacity;
    int *elements;
public:
    MyVec(int capacity =4,int size=0) {
        elements = new int[capacity];
        this->capacity = capacity;
        this->size = size;
    }
    MyVec(int size) {
        int capacity = 4;
        while (size >= capacity) {
            capacity*=2;
        }
        elements = new int[capacity];
        this->capacity = capacity;
        this->size = size;
    }
    MyVec(const MyVec &v) {
        this->size = v.size;
        this->capacity = v.capacity;
        elements=new int[capacity];
        for (int i = 0; i < this->size; i++) {
            elements[i] = v.elements[i];
        }
    }
    ~MyVec() {
        delete [] elements;
    }
    void push_back(int val);
    void pop();
    void print() {
        for (int i = 0; i < this->size; i++) {
            cout<<elements[i]<<" ";
        }
    }
    void Size() {
        cout << this->size;
    }
    void Capacity() {
        cout << this->capacity;
    }
    void clear() {
        this->size = 0;

    }
    MyVec &operator=( MyVec &v) {
        if (this != &v) {
            delete [] elements;
        }
        this->size = v.size;
        this->capacity = v.capacity;
        this->elements = new int[this->capacity];
        for (int i = 0; i < this->size; i++) {
            elements[i] = v.elements[i];
        }
        return *this;
    }
    int &operator[](int i) {
        return elements[i];
    }
};
void MyVec::push_back(int element) {
    if (size >= capacity) {
        capacity *= 2;
    }
    int i=0;
    while (i<size) {
        i++;
    }
    size++;
    elements[i] = element;
}
void MyVec::pop() {
    if (size<1) return;
    size--;
}

int main() {
    MyVec v;
    v.push_back(999);
    v.push_back(777);
    v.push_back(777);
    v.push_back(333);
    v.push_back(122);
    v.print();
    cout<<endl;
    cout<<v[3]<<endl;
    MyVec v2=v;
    v2.print();
}