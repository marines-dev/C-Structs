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
    cout << num << "번째 피보나치 수는 " << result << "입니다." << endl;

    return 0;
}