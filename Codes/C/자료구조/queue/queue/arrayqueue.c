#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayqueue.h"

ArrayQueue* CreateArrayQueue(int _maxElementCount)
{
    ArrayQueue* pReturn = NULL;

    if (_maxElementCount > 0)
    {
        pReturn = (ArrayQueue*)malloc(sizeof(ArrayQueue));
        if (pReturn != NULL)
        {
            memset(pReturn, 0, sizeof(ArrayQueue));
            pReturn->maxElementCount = _maxElementCount;
            pReturn->front = -1;
            pReturn->rear = -1;
        }
        else
        {
            printf("Failed : Allocate memory\n");
            return NULL;
        }
    }
    else
    {
        printf("Failed : Unavailable value(%d)\n", _maxElementCount);
        return NULL;
    }

    pReturn->pElement = (ArrayQueueNode*)malloc(sizeof(ArrayQueueNode) * _maxElementCount);
    if (pReturn->pElement != NULL)
    {
        memset(pReturn->pElement, 0, sizeof(ArrayQueueNode) * _maxElementCount);
    }
    else
    {
        printf("Failed : Allocate memory\n");
        free(pReturn);
        return NULL;
    }

    return pReturn;
}

void DeleteArrayQueue(ArrayQueue* _pQueue)
{
    if (_pQueue != NULL)
    {
        if (_pQueue->pElement != NULL)
        {
            free(_pQueue->pElement);
        }
        free(_pQueue);
    }
}

int IsArrayQueueFull(ArrayQueue* _pQueue)
{
    int ret = FALSE;
    
    if (_pQueue != NULL)
    {
        if (_pQueue->currentElementCount == _pQueue->maxElementCount)
        {
            ret = TRUE;
        }
    }

    return ret;
}

int IsArrayQueueEmpty(ArrayQueue* _pQueue)
{
    int ret = FALSE;
    
    if (_pQueue != NULL)
    {
        if (_pQueue->currentElementCount == 0)
        {
            ret = TRUE;
        }
    }

    return ret;
}

int EnqueueAQ(ArrayQueue* _pQueue, ArrayQueueNode _element)
{
    int ret = FALSE;
    
    if (_pQueue != NULL)
    {
        if (IsArrayQueueFull(_pQueue) == FALSE)
        {
            _pQueue->rear = (_pQueue->rear + 1) % _pQueue->maxElementCount;
            _pQueue->pElement[_pQueue->rear] = _element;
            _pQueue->currentElementCount++;

            ret = TRUE;
        }
        else
        {
            printf("Failed : Queue is Full\n");
        }
    }

    return ret;
}

ArrayQueueNode DequeueAQ(ArrayQueue* _pQueue)
{
    ArrayQueueNode returnNode;
    if (_pQueue != NULL)
    {
        if (IsArrayQueueEmpty(_pQueue) == FALSE)
        {
            _pQueue->front = (_pQueue->front + 1) % _pQueue->maxElementCount;
            returnNode.element = _pQueue->pElement[_pQueue->front].element;
            _pQueue->currentElementCount--;
        }
        else
        {
            printf("Failed : Queue is Empty\n");
        }
    }

    return returnNode;
}

ArrayQueueNode PeekAQ(ArrayQueue* _pQueue)
{
    ArrayQueueNode returnNode;
    if (_pQueue != NULL)
    {
        if (IsArrayQueueEmpty(_pQueue) == FALSE)
        {
            returnNode = _pQueue->pElement[_pQueue->front + 1];
        }
        else
        {
            printf("Failed : Queue is Empty\n");
        }
    }

    return returnNode;
}
