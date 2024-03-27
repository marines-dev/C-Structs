#include <iostream>
using namespace std;

// Factorial : ! n = n ~ 1까지 모두 곱한 수 
unsigned long long factorial(int n) 
{
    if (n <= 1) //마지막 수 '1'
    { 
        return 1; 
    }
    else 
    {
        return n * factorial(n - 1);
    }
}

int main() 
{
    unsigned int num = 5;
    unsigned long long result = factorial(num);
    cout << num << "의 팩토리얼은 " << result << "입니다." << endl;

    return 0;
}