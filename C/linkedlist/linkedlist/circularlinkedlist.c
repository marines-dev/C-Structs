#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "circularlinkedlist.h"

CircularList* CreateCircularList()
{
    CircularList* pReturn = NULL;
    int i = 0;
    pReturn = (CircularList*)malloc(sizeof(CircularList));
    if (pReturn != NULL)
    {
        memset(pReturn, 0, sizeof(CircularList)); //구조체의 속성값을 모두 0으로 초기화
    }
    else
    {
        printf("Error : 메모리 할당 실패\n");
        return NULL;
    }

    return pReturn;
}

void DeleteCircularList(CircularList* _pList)
{
    int i = 0;
    if (_pList != NULL)
    {
        ClearCircularList(_pList);
        free(_pList);
    }
}

void ClearCircularList(CircularList* _pList)
{
    if (_pList != NULL)
    {
        if (_pList->currentElementCount > 0)
        {
            RemoveCLElement(_pList, 0);
        }
    }
}

int GetCircularListLength(CircularList* _pList)
{
    int ret = 0;

    if (_pList != NULL)
    {
        ret = _pList->currentElementCount;
    }

    return ret;
}

int IsCircularListEmpty(CircularList* _pList)
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

int AddCLElement(CircularList* _pList, int _index, CircularNode _element)
{
    int ret = FALSE;
    int i = 0;
    CircularNode* pPreNode = NULL;
    CircularNode* pNewNode = NULL;
    CircularNode* pLastNode = NULL;
    if (_pList != NULL)
    {
        if (_index >= 0 && _index <= _pList->currentElementCount)
        {
            pNewNode = (CircularNode*)malloc(sizeof(CircularNode));
            if (pNewNode == NULL)
            {
                printf("Error : 메모리 할당 실패\n");
                return ret;
            }

            *pNewNode = _element;
            pNewNode->pLink = NULL;
            //노드 정보 초기화

            if (_index == 0)
            {
                if (_pList->currentElementCount == 0) // 공백일 때 첫 번째 노드를 추가하는 경우
                {
                    _pList->pLink = pNewNode;
                    pNewNode->pLink = pNewNode;
                }
                else // 공백이 아닐 때 첫 번째 노드를 추가하는 경우
                {
                    pLastNode = _pList->pLink;
                    while (pLastNode->pLink != _pList->pLink)
                    {
                        pLastNode = pLastNode->pLink;
                    }
                    
                    _pList->pLink = pNewNode;
                    pNewNode->pLink = pLastNode->pLink;
                    pLastNode->pLink = pNewNode;
                }
            }
            else //중간에 노드를 추가하는 경우
            {
                pPreNode = _pList->pLink;
                for (i = 0; i < _index - 1; ++i)
                {
                    pPreNode = pPreNode->pLink;
                    //추가하려는 인덱스의 이전 노드를 찾을 때까지 이동한다.
                }

                pNewNode->pLink = pPreNode->pLink;
                pPreNode->pLink = pNewNode;
            }

            _pList->currentElementCount++;
            ret = TRUE;
        }
        else
        {
            printf("Error : Index[%d] 범위 초과\n", _index);
        }

        return ret;
    }
}

int RemoveCLElement(CircularList* _pList, int _index)
{
    int ret = FALSE;
    int i = 0;
    int count = 0;
    CircularNode* pPreNode = NULL;
    CircularNode* pDelNode = NULL;
    CircularNode* pLastNode = NULL;

    if (_pList != NULL)
    {
        count = GetCircularListLength(_pList);
        if (_index >= 0 && _index < count)
        {
            if (_index == 0) //마지막 노드이면서 동시에 첫 번째 노드를 제거하는 경우
            {
                pDelNode = _pList->pLink;
                if (count == 1)
                {
                    free(pDelNode);
                    _pList->pLink = NULL;
                }
                else //마지막 노드가 아닌 첫 번째 노드를 제거하는 경우
                {
                    pLastNode = _pList->pLink;
                    while (pLastNode->pLink != _pList->pLink) //마지막 노드를 찾을 때까지 이동한다.
                    {
                        pLastNode = pLastNode->pLink;
                    }

                    pLastNode->pLink = pDelNode->pLink;
                    _pList->pLink = pDelNode->pLink;
                    free(pDelNode);
                }
            }
            else //중간 노드를 삭제하는 경우
            {
                pPreNode = _pList->pLink;
                for (i = 0; i < _index - 1; ++i)
                {
                    pPreNode = pPreNode->pLink;
                }

                pDelNode = pPreNode->pLink;
                pPreNode->pLink = pDelNode->pLink;
                free(pDelNode);
            }

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

CircularNode* GetCLElement(CircularList* _pList, int _index)
{
    int i = 0;
    CircularNode* pNode = NULL;
    if (_pList != NULL)
    {
        if (_index >= 0 && _index < _pList->currentElementCount)
        {
            pNode = _pList->pLink;
            for (i = 0; i < _index; ++i)
            {
                pNode = pNode->pLink;
            }
        }
    }

    return pNode;
}
