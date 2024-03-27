#include <iostream>
using namespace std;


// �� �κ� �迭�� �����ϴ� �Լ�
void merge(int arr[], int lowIdx, int midIdx, int highIdx) 
{
    int left_length = midIdx - lowIdx + 1;
    int right_length = highIdx - midIdx;

    // �ӽ� �迭�� �����Ͽ� ������ ����
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
    //�� �κ� �迭�� ��ħ
    while (i < left_length && j < right_length) 
    {
        if (left_arr[i] <= right_arr[j]) //���� �۰ų� ������
        {
            arr[k] = left_arr[i]; //left_arr�� ����
            i++;
        }
        else //������
        {
            arr[k] = right_arr[j]; //right_arr�� ����
            j++;
        }
        k++;
    }

    //���� ���ҵ��� ����
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

    //���� �Ҵ�� �޸� ����
    delete[] left_arr;
    delete[] right_arr;
}

//���� ����
void mergeSort(int arr[], int lowIdx, int highIdx) 
{
    //�迭�� ���̻� ���� �� ���� ������ �߰����� ����
    if (lowIdx < highIdx) 
    {
        int midIdx = lowIdx + (highIdx - lowIdx) / 2;
        mergeSort(arr, lowIdx, midIdx);
        mergeSort(arr, midIdx + 1, highIdx);

        //���ĵ� �κ� �迭�� ����
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

    //���� ��
    printArray(arr, length);

    //���� ��
    mergeSort(arr, 0, length - 1);
    printArray(arr, length);

    return 0;
}
