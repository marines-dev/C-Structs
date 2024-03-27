#include <iostream>
using namespace std;

// �迭�� Ư�� ������ �����ϰ� �ǹ��� ��ġ�� ��ȯ�ϴ� �Լ�
int partition(int arr[], int low, int high) 
{
    int pivot = arr[high]; // �ǹ��� �迭�� ������ ���ҷ� ����
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

//��������
void quickSort(int arr[], int lowIdx, int highIdx) 
{
    int pivotIdx = 0;
    if (lowIdx < highIdx) 
    {
        //�迭�� Ư�� ������ �����ϰ� �ǹ��� ��ġ�� �����Ѵ�.
        {
            int pivot = arr[highIdx]; //�ǹ��� ������ ���ҷ� ����
            int swapIdx = lowIdx - 1;

            //���ҵ� �κ� �迭�� ����
            for (int j = lowIdx; j < highIdx; j++)
            {
                //�ǹ����� ���� ������ ���� ��ȯ
                if (arr[j] < pivot) 
                {
                    swapIdx++; //��ȯ�� ��ġ ����
                    swap(arr[swapIdx], arr[j]);
                }
            }

            swap(arr[swapIdx + 1], arr[highIdx]);
            pivotIdx = swapIdx + 1;
        }

        //�ǹ��� �������� ���ʰ� ������ �κ� �迭�� ��������� ����
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

    //���� ��
    printArray(arr, length);

    //���� ��
    quickSort(arr, 0, length - 1);
    printArray(arr, length);

    return 0;
}