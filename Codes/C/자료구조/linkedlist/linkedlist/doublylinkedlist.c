#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "doublylinkedlist.h"

DoublyList* CreateDoublyList()
{
    DoublyList* pReturn = NULL;
    int i = 0;

    pReturn = (DoublyList*)malloc(sizeof(DoublyList));
    if (pReturn != NULL)
    {
        memset(pReturn, 0, sizeof(DoublyList));

        pReturn->headerNode.pLLink = &(pReturn->headerNode);
        pReturn->headerNode.pRLink = &(pReturn->headerNode);
    }
    else
    {
        printf("Error : 메모리 할당 실패\n");
        return NULL;
    }

    return pReturn;
}

void DeleteDoublyList(DoublyList* _pList)
{
    if (_pList != NULL)
    {
        ClearDoublyList(_pList);
        free(_pList);
    }
}

void ClearDoublyList(DoublyList* _pList)
{
    if (_pList != NULL)
    {
        while (_pList->currentElementCount > 0)
        {
            RemoveDLElement(_pList, 0);
        }
    }
}

int GetDoublyListLength(DoublyList* _pList)
{
    int ret = 0;
    if (_pList != NULL)
    {
        ret = _pList->currentElementCount;
    }

    return ret;
}

int IsDoublyListEmpty(DoublyList* _pList)
{
    int ret = FALSE;
    if (_pList != NULL)
    {
        if (_pList->currentElementCount == 0)
        {
            ret = TRUE;
        }
    }

    return ret;
}

int AddDLElement(DoublyList* _pList, int _index, DoublyNode _element)
{
    int ret = FALSE;
    int i = 0;
    DoublyNode* pPreNode = NULL;
    DoublyNode* pNewNode = NULL;
    DoublyNode* pTempNode = NULL;

    if (_pList != NULL)
    {
        if (_index >= 0 && _index <= _pList->currentElementCount)
        {
            pNewNode = (DoublyNode*)malloc(sizeof(DoublyNode));
            if (pNewNode == NULL)
            {
                printf("Error : 메모리 할당 실패\n");
                return ret;
            }

            *pNewNode = _element;
            pNewNode->pLLink = NULL;
            pNewNode->pRLink = NULL;

            pPreNode = &(_pList->headerNode);
            for (i = 0; i < _index; ++i)
            {
                pPreNode = pPreNode->pRLink;
            }

            pNewNode->pLLink = pPreNode;
            pNewNode->pRLink = pPreNode->pRLink;
            pPreNode->pRLink = pNewNode;
            pTempNode = pNewNode->pRLink;
            pTempNode->pLLink = pNewNode;

            _pList->currentElementCount++;
            ret = TRUE;
        }
        else
        {
            printf("Error : Index[%d] 범위 초과\n", _index);
        }
    }

    return ret;
}

int RemoveDLElement(DoublyList* _pList, int _index)
{
    int ret = FALSE;
    int i = 0;
    int count = 0;
    DoublyNode* pPreNode = NULL;
    DoublyNode* pDelNode = NULL;
    DoublyNode* pTempNode = NULL;

    if (_pList != NULL)
    {
        count = GetDoublyListLength(_pList);
        if (_index >= 0 && _index < count)
        {
            pPreNode = &(_pList->headerNode);
            for (i = 0; i < _index; ++i)
            {
                pPreNode = pPreNode->pRLink;
            }

            pDelNode = pPreNode->pRLink;
            pPreNode->pRLink = pDelNode->pRLink;
            pTempNode = pDelNode->pRLink;
            pTempNode->pLLink = pPreNode;
            free(pDelNode);

            _pList->currentElementCount--;
            ret = TRUE;
        }
        else
        {
            printf("Error : Index[%d] 범위 초과\n", _index);
        }
    }
    
    return ret;
}

DoublyNode* GetDLElement(DoublyList* _pList, int _index)
{
    DoublyNode* pReturn = NULL;
    int i = 0;
    DoublyNode* pNode = NULL;
    if (_pList != NULL)
    {
        if (_index >= 0 && _index < _pList->currentElementCount)
        {
            pNode = _pList->headerNode.pRLink;
            for (i = 0; i < _index; ++i)
            {
                pNode = pNode->pRLink;
            }
            pReturn = pNode;
        }
        else
        {
            printf("Error : Index[%d] 범위 초과\n", _index);
        }
    }

    return pReturn;
}
