#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedqueue.h"

LinkedQueue* CreateLinkedQueue()
{
    LinkedQueue* pReturn = NULL;
    int i = 0;
    pReturn = (LinkedQueue*)malloc(sizeof(LinkedQueue));
    if (pReturn != NULL)
    {
        memset(pReturn, 0, sizeof(LinkedQueue));
    }
    else
    {
        printf("Failed : Allocate memory\n");
    }

    return pReturn;
}

void DeleteLinekdQueue(LinkedQueue* _pQueue)
{
    LinkedQueueNode* pNode = NULL;
    LinkedQueueNode* pDelNode = NULL;

    if (_pQueue != NULL)
    {
        pNode = _pQueue->pFrontNode;
        while (pNode != NULL)
        {
            pDelNode = pNode;
            pNode = pNode->pLink;
            
            free(pDelNode);
        }
        
        free(_pQueue);
    }
}

int IsLinkedQueueEmpty(LinkedQueue* _pQueue)
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

int EnqueueLQ(LinkedQueue* _pQueue, LinkedQueueNode element)
{
    int ret = FALSE;
    LinkedQueueNode* pNode = NULL;
    pNode = (LinkedQueueNode*)malloc(sizeof(LinkedQueueNode));
    if (pNode != NULL)
    {
        *pNode = element;
        pNode->pLink = NULL;

        if (IsLinkedQueueEmpty(_pQueue) == TRUE)
        {
            _pQueue->pFrontNode = pNode;
            _pQueue->pRearNode = pNode;
        }
        else
        {
            _pQueue->pRearNode->pLink = pNode;
            _pQueue->pRearNode = pNode;
        }
        _pQueue->currentElementCount++;
        ret = TRUE;
    }
    else
    {
        printf("Failed : Allocate memory\n");
    }

    return ret;
}

LinkedQueueNode DequeueLQ(LinkedQueue* _pQueue)
{
    LinkedQueueNode returnNode;
    LinkedQueueNode* pDelNode = NULL;
    if (_pQueue != NULL)
    {
        if (IsLinkedQueueEmpty(_pQueue) == FALSE)
        {
            returnNode = *(_pQueue->pFrontNode);
            returnNode.pLink = NULL;
            
            pDelNode = _pQueue->pFrontNode;

            _pQueue->pFrontNode = _pQueue->pFrontNode->pLink;
            _pQueue->currentElementCount--;

            free(pDelNode);

            if (IsLinkedQueueEmpty(_pQueue) == TRUE)
            {
                _pQueue->pRearNode = NULL;
            }


        }
    }

    return returnNode;
}

LinkedQueueNode PeekLQ(LinkedQueue* _pQueue)
{      
    LinkedQueueNode returnNode;
    if (_pQueue != NULL)
    {
        if (IsLinkedQueueEmpty(_pQueue) == FALSE)
        {
            returnNode = *(_pQueue->pFrontNode);
        }
    }

    return returnNode;
}
