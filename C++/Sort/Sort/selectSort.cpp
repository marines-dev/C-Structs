#include <iostream>
using namespace std;

// ��������
void selectionSort(int arr[], int length) 
{
    for (int i = 0; i < length - 1; ++i) 
    {
        int minIndex = i; // ���� �ε����� �ּڰ��� �ε����� ����

        // ������ �迭�� Ž���Ͽ� �ּڰ��� ã��
        for (int j = i + 1; j < length; ++j) 
        {
            if (arr[j] < arr[minIndex]) 
            {
                minIndex = j;
            }
        }

        // ������ �迭���� Ž���� �ּڰ��� ���� �ε����� ���Ҹ� ��ü
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

    // ���� ��
    printArray(arr, length);
    
    //���� ��
    selectionSort(arr, length);
    printArray(arr, length);

    return 0;
}