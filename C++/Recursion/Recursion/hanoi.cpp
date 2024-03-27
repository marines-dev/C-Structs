#include <iostream>
using namespace std;

void hanoi(int n, char source, char auxiliary, char target) 
{
    if (n == 1) 
    {
        cout << "원판 1을 " << source << "에서 " << target << "로 옮깁니다." << endl;
        return;
    }

    hanoi(n - 1, source, target, auxiliary);
    cout << "원판 " << n << "을(를) " << source << "에서 " << target << "로 옮깁니다." << endl;
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