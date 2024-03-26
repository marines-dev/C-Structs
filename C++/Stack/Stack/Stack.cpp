#include <iostream>
using namespace std;
const int MAX_SIZE = 10;

class Stack {
private:
    int arr[MAX_SIZE] = {};
    int top = -1;

public:
    bool isEmpty() const 
    { 
        bool isEmpty = top == -1;
        if (isEmpty) { cout << "Stack이 비어있습니다." << endl; }

        return isEmpty;
    }

    bool isFull() const 
    { 
        bool isFull = top >= MAX_SIZE - 1;
        if (isFull) { cout << "Stack이 꽉찼습니다." << endl; }

        return isFull;
    }

    void push(int value) 
    {
        if (isFull())
            return;

        arr[++top] = value;
        cout << "삽입 : " << value << endl;
    }

    int pop() 
    {
        if (isEmpty())
            return -1;

        int value = arr[top--];
        cout << "삭제 : " << value << endl;
        return value;
    }

    void peek() const 
    {
        if (isEmpty())
            return;

        cout << "Top : " << arr[top] << endl;
    }
};

int main() {
    Stack stack;

    stack.push(5);
    stack.push(10);
    stack.push(7);
    stack.peek();

    stack.pop();
    stack.pop();
    stack.peek();

    return 0;
}