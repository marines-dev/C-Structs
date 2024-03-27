#include <iostream>
using namespace std;


// 두 부분 배열을 결합하는 함수
void merge(int arr[], int lowIdx, int midIdx, int highIdx) 
{
    int left_length = midIdx - lowIdx + 1;
    int right_length = highIdx - midIdx;

    // 임시 배열을 생성하여 데이터 복사
    int* left_arr = new int[left_length];
    int* right_arr = new int[right_length];
    for (int i = 0; i < left_length; i++)
    {
        left_arr[i] = arr[lowIdx + i];
    }

    for (int j = 0; j < right_length; j++)
    {
        right_arr[j] = arr[midIdx + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = lowIdx;
    //두 부분 배열을 합침
    while (i < left_length && j < right_length) 
    {
        if (left_arr[i] <= right_arr[j]) //값이 작거나 같으면
        {
            arr[k] = left_arr[i]; //left_arr에 저장
            i++;
        }
        else //높으면
        {
            arr[k] = right_arr[j]; //right_arr에 저장
            j++;
        }
        k++;
    }

    //남은 원소들을 복사
    while (i < left_length) 
    {
        arr[k] = left_arr[i];
        i++;
        k++;
    }

    while (j < right_length) 
    {
        arr[k] = right_arr[j];
        j++;
        k++;
    }

    //동적 할당된 메모리 해제
    delete[] left_arr;
    delete[] right_arr;
}

//병합 정렬
void mergeSort(int arr[], int lowIdx, int highIdx) 
{
    //배열을 더이상 나눌 수 없을 때까지 중간으로 분할
    if (lowIdx < highIdx) 
    {
        int midIdx = lowIdx + (highIdx - lowIdx) / 2;
        mergeSort(arr, lowIdx, midIdx);
        mergeSort(arr, midIdx + 1, highIdx);

        //정렬된 부분 배열을 결합
        merge(arr, lowIdx, midIdx, highIdx);
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
    mergeSort(arr, 0, length - 1);
    printArray(arr, length);

    return 0;
}
