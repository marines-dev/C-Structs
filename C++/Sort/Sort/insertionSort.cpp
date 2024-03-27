#include <iostream>
using namespace std;


// ��������
void insertionSort(int arr[], int length) 
{
    for (int i = 1; i < length; ++i) 
    {
        int key = arr[i]; // ���� �ε����� ���ĵǾ�� �ϴ� ���ذ�

        int j = i - 1;
        // ���ĵ� �迭���� ���� ���� key���� Ŭ������ 
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j]; //���������� �̵�
            --j;
        }

        // ���������� �̵��� ������ ���� ��ġ�� key�� ����
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

    //���� ��
    printArray(arr, length);

    //���� ��
    insertionSort(arr, length);
    printArray(arr, length);

    return 0;
}