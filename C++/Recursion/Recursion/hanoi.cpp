#include <iostream>
using namespace std;

void hanoi(int n, char source, char auxiliary, char target) 
{
    if (n == 1) 
    {
        cout << "���� 1�� " << source << "���� " << target << "�� �ű�ϴ�." << endl;
        return;
    }

    hanoi(n - 1, source, target, auxiliary);
    cout << "���� " << n << "��(��) " << source << "���� " << target << "�� �ű�ϴ�." << endl;
    hanoi(n - 1, auxiliary, source, target);
}

int main() 
{
    int number = 4;
    char source = 'A';
    char auxiliary = 'B';
    char target = 'C';
    hanoi(number, source, auxiliary, target);

    return 0;
}