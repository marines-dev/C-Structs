// stack.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <stdio.h>
#include <stdlib.h>
#include "arraystack.h"

void DisplayArrayStack(ArrayStack* _pStack)
{
    int i = 0;
    
    if (_pStack != NULL)
    {
        int size = _pStack->maxElementCount;
        int top = _pStack->currentElementCount;

        printf("스택 크기 : %d\n", size);
        printf("현재 원소 개수 : %d\n", top);

        for (i = size - 1; i >= top; --i)
        {
            printf("index(%d) : Empty\n", i);
        }

        for (i = top - 1; i >= 0; --i)
        {
            printf("index(%d) : %c\n", i, _pStack->pElement[i].data);
        }
    }
}

int main()
{
    ArrayStack* pStack = NULL;
    ArrayStackNode node;
    char value = 0;

    pStack = CreateArrayStack(6);
    if (pStack != NULL)
    {
        ArrayStackNode node1 = { 'A' };
        ArrayStackNode node2 = { 'B' };
        ArrayStackNode node3 = { 'C' };
        ArrayStackNode node4 = { 'D' };
        ArrayStackNode node5 = { 'E' };

        PushAS(pStack, node1);
        PushAS(pStack, node2);
        PushAS(pStack, node3);
        PushAS(pStack, node4);
        PushAS(pStack, node5);
        DisplayArrayStack(pStack);

        node = PopAS(pStack);
        printf("Pop : %c\n", node.data);

        node = PopAS(pStack);
        printf("Pop : %c\n", node.data);
        DisplayArrayStack(pStack);

        node = PeekAS(pStack);
        printf("Peek : %c\n", node.data);

        DisplayArrayStack(pStack);
    }

    return 0;
}
