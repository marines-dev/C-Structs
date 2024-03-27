#include <iostream>
using namespace std;

// 배열의 특정 범위를 분할하고 피벗의 위치를 반환하는 함수
int partition(int arr[], int low, int high) 
{
    int pivot = arr[high]; // 피벗은 배열의 마지막 원소로 선택
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) 
    {
        if (arr[j] < pivot) 
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

//오름차순
void quickSort(int arr[], int lowIdx, int highIdx) 
{
    int pivotIdx = 0;
    if (lowIdx < highIdx) 
    {
        //배열의 특정 범위를 분할하고 피벗의 위치를 설정한다.
        {
            int pivot = arr[highIdx]; //피벗을 마지막 원소로 선택
            int swapIdx = lowIdx - 1;

            //분할된 부분 배열을 정렬
            for (int j = lowIdx; j < highIdx; j++)
            {
                //피벗보다 값이 작으면 서로 교환
                if (arr[j] < pivot) 
                {
                    swapIdx++; //교환할 위치 증가
                    swap(arr[swapIdx], arr[j]);
                }
            }

            swap(arr[swapIdx + 1], arr[highIdx]);
            pivotIdx = swapIdx + 1;
        }

        //피벗을 기준으로 왼쪽과 오른쪽 부분 배열을 재귀적으로 정렬
        quickSort(arr, lowIdx, pivotIdx - 1);
        quickSort(arr, pivotIdx + 1, highIdx);
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

    //정렬 후
    quickSort(arr, 0, length - 1);
    printArray(arr, length);

    return 0;
}