#include <iostream>
using namespace std;

// 오름차순
void bubbleSort(int arr[], int lenth) 
{
    for (int i = 1; i < lenth - 1; ++i) 
    {
        for (int j = 0; j < lenth - i; ++j) 
        {
            // 인접한 두 원소를 비교하여 순서를 교체한다.
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printArray(int arr[], int lenth) 
{
    for (int i = 0; i < lenth; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() 
{
    int arr[] = { 76, 37, 55, 12, 23, 41, 90 };
    int length = sizeof(arr) / sizeof(arr[0]);

    //정렬 전
    printArray(arr, length);

    // 정렬 후
    bubbleSort(arr, length);
    printArray(arr, length);

    return 0;
}