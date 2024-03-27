#include <iostream>
using namespace std;

// 이중 연결 리스트의 노드
struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

/// <summary>
/// 이중 연결 리스트
/// </summary>
class List {
private:
    Node* headNode = nullptr;

public:
    void append(int value) 
    {
        Node* newNode = new Node(value);

        if (headNode == nullptr) { headNode = newNode; }
        else 
        {
            Node* tempNode = headNode;
            while (tempNode->next != nullptr) // 마지막 노드를 찾는다.
            {
                tempNode = tempNode->next;
            }

            tempNode->next = newNode; // tempNode의 next 링크에 newNode 추가
            newNode->prev = tempNode; // newNode의 prev 링크에 tempNode 추가
        }
    }

    void remove(int value)
    {
        Node* tempNode = headNode;
        while (tempNode != nullptr)
        {
            if (tempNode->data == value) //값(value)이 같으면
            {
                
                if (tempNode->prev != nullptr) 
                { 
                    //tempNode를 삭제하기 위해 tempNode의 '이전 노드'와 '다음 노드'를 서로 연결
                    tempNode->prev->next = tempNode->next; 
                }
                else 
                { 
                    //tempNode의 '이전 노드'가 없으므로 headNode //headNode를 '다음 노드'로 변경
                    headNode = tempNode->next; 
                } 

                if (tempNode->next != nullptr) //tempNode의 next 링크가 null이 아니면 '중간 노드'
                {
                    tempNode->next->prev = tempNode->prev; //tempNode의 '다음 노드'의 prev 링크에 tempNode의 '이전 노드'를 연결
                }

                delete tempNode; //메모리 해제
                return;
            }

            tempNode = tempNode->next;
        }
        cerr << "삭제할 값(" << value << ")을 찾을 수 없습니다." << endl;
    }

    void display() 
    {
        Node* tempNode = headNode;
        while (tempNode != nullptr) 
        {
            cout << tempNode->data << " ";
            tempNode = tempNode->next;
        }

        cout << endl;
    }

    // 리스트를 역순으로 출력
    void reverseDisplay()
    {
        Node* tempNode = headNode;
        while (tempNode->next != nullptr) //마지막 노드를 찾는다.
        {
            tempNode = tempNode->next;
        }

        while (tempNode != nullptr)
        {
            cout << tempNode->data << " ";
            tempNode = tempNode->prev; //이전 노드를 이용해 역순으로 출력
        }
        cout << endl;
    }

    // 리스트 메모리 해제
    ~List() 
    {
        Node* currNode = headNode;
        Node* nextNode = nullptr;

        while (currNode != nullptr) 
        {
            nextNode = currNode->next;
            delete currNode;
            currNode = nextNode;
        }

        headNode = nullptr;
    }
};


int main() {
    List list;

    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.display();


    list.remove(2);
    list.reverseDisplay();

    return 0;
}
