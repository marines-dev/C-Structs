#include <iostream>
using namespace std;


// 오름차순
void insertionSort(int arr[], int length) 
{
    for (int i = 1; i < length; ++i) 
    {
        int key = arr[i]; // 현재 인덱스가 정렬되어야 하는 기준값

        int j = i - 1;
        // 정렬된 배열에서 원소 값이 key보다 클때까지 
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j]; //오른쪽으로 이동
            --j;
        }

        // 마지막으로 이동된 원소의 원래 위치에 key를 삽입
        arr[j + 1] = key;
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

int main() {
    int arr[] = { 76, 37, 55, 12, 23, 41, 90 };
    int length = sizeof(arr) / sizeof(arr[0]);

    //정렬 전
    printArray(arr, length);

    //정렬 후
    insertionSort(arr, length);
    printArray(arr, length);

    return 0;
}