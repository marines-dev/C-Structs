#include <iostream>
using namespace std;

// 오름차순
void selectionSort(int arr[], int length) 
{
    for (int i = 0; i < length - 1; ++i) 
    {
        int minIndex = i; // 현재 인덱스를 최솟값의 인덱스로 가정

        // 나머지 배열을 탐색하여 최솟값을 찾음
        for (int j = i + 1; j < length; ++j) 
        {
            if (arr[j] < arr[minIndex]) 
            {
                minIndex = j;
            }
        }

        // 나머지 배열에서 탐색한 최솟값과 현재 인덱스의 원소를 교체
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
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

    // 정렬 전
    printArray(arr, length);
    
    //정렬 후
    selectionSort(arr, length);
    printArray(arr, length);

    return 0;
}