#include <iostream>
using namespace std;

const int MAX_SIZE = 5;

/// <summary>
/// 구현 방법 : 배열을 이용한 원형 큐
/// </summary>
class Queue {
private:
    int arr[MAX_SIZE] = {};
    int front = 0;
    int rear = 0;

public:
    bool isEmpty() const 
    { 
        bool isEmpty = front == rear;
        if(isEmpty){ cout << "Queue가 비어있습니다." << endl; }
        
        return isEmpty;
    }
    bool isFull() const 
    { 
        bool isFull = front == (rear + 1) % MAX_SIZE; // front가 rear보다 한칸 앞에 있는 경우
        if (isFull) { cout << "Queue가 꽉찼습니다." << endl; }
        
        return isFull;
    }

    void enqueue(int value) 
    {
        if (isFull())
            return;

        arr[rear] = value;
        cout << "삽입 : " << value << "(" << rear << "번째)" << endl;

        rear = ++rear % MAX_SIZE; // MAX_SIZE와 같으면 "0"부터 시작.
    }

    int dequeue()
    {
        if (isEmpty())
            return -1;

        int value = arr[front];
        cout << "삭제 : " << value << "(" << front << "번째)" << endl;

        front = ++front % MAX_SIZE; // MAX_SIZE와 같으면 "0"부터 시작.
        return value;
    }

    void peek() const 
    {
        if (isEmpty())
            return;

        cout << "Front : " << arr[front] << endl;
    }
};

int main() {
    Queue queue;

    queue.enqueue(3);
    queue.enqueue(7);
    queue.enqueue(5);
    queue.peek();

    queue.dequeue();
    queue.dequeue();
    queue.peek();

    return 0;
}