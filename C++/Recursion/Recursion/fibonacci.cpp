#include <iostream>
using namespace std;

unsigned long long fibonacci(int n) 
{
    if (n <= 1) 
    {
        return n;
    }
    else 
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() 
{
    unsigned int num = 10;
    unsigned long long result = fibonacci(num);
    cout << num << "��° �Ǻ���ġ ���� " << result << "�Դϴ�." << endl;

    return 0;
}