//// main.c : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
////
//#include <stdio.h>
//#include <stdlib.h>
//#include "arrayqueue.h"
//
//void DisplayArrayQueue(ArrayQueue* _pQueue)
//{
//    int i = 0;
//    int maxElementIndex = 0;
//    int index = 0;
//
//    if (_pQueue != NULL)
//    {
//        printf("Max element count : %d\n", _pQueue->maxElementCount);
//        printf("Current element count : %d\n", _pQueue->currentElementCount);
//
//        maxElementIndex = _pQueue->front + _pQueue->currentElementCount;
//        for (i = _pQueue->front + 1; i <= maxElementIndex; ++i)
//        {
//            index = i % _pQueue->maxElementCount; //front -> rear로 이동하기 위한 인덱스
//            printf("index(%d) : %c\n", index, _pQueue->pElement[index].element);
//        }
//    }
//}
//
//int main()
//{
//    ArrayQueue* pQueue = NULL;
//    char value = 0;
//
//    pQueue = CreateArrayQueue(5);
//    if (pQueue != NULL)
//    {
//        ArrayQueueNode node1 = { 'A' };
//        ArrayQueueNode node2 = { 'B' };
//        ArrayQueueNode node3 = { 'C' };
//        ArrayQueueNode node4 = { 'D' };
//
//        EnqueueAQ(pQueue, node1);
//        EnqueueAQ(pQueue, node2);
//        EnqueueAQ(pQueue, node3);
//        DisplayArrayQueue(pQueue);
//
//        DequeueAQ(pQueue);
//        DisplayArrayQueue(pQueue);
//
//        DequeueAQ(pQueue);
//        DisplayArrayQueue(pQueue);
//
//        EnqueueAQ(pQueue, node4);
//        DisplayArrayQueue(pQueue);
//    }
//
//    return 0;
//}

// main.c : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <stdio.h>
#include <stdlib.h>
#include "linkedqueue.h"

void DisplayLinkedQueue(LinkedQueue *_pQueue)
{
    LinkedQueueNode* pNode = NULL;
    int i = 0;

    if (_pQueue != NULL)
    {
        printf("Current element count : %d\n", _pQueue->currentElementCount);
        pNode = _pQueue->pFrontNode;
        while (pNode != NULL)
        {
            printf("index(%d) : %c\n", i, pNode->data);
            ++i;
            pNode = pNode->pLink;
        }
    }
}

int main()
{
    LinkedQueue* pQueue = NULL;
    char value = 0;

    pQueue = CreateLinkedQueue(5);
    if (pQueue != NULL)
    {
        LinkedQueueNode node1 = { 'A' };
        LinkedQueueNode node2 = { 'B' };
        LinkedQueueNode node3 = { 'C' };
        LinkedQueueNode node4 = { 'D' };

        EnqueueLQ(pQueue, node1);
        EnqueueLQ(pQueue, node2);
        EnqueueLQ(pQueue, node3);
        DisplayLinkedQueue(pQueue);

        DequeueLQ(pQueue);
        DisplayLinkedQueue(pQueue);

        DequeueLQ(pQueue);
        DisplayLinkedQueue(pQueue);

        EnqueueLQ(pQueue, node4);
        DisplayLinkedQueue(pQueue);
    }

    return 0;
}
