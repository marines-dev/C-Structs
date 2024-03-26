#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "singlylinkedlist.h"

SinglyList* CreateSinglyList()
{
    SinglyList* pReturn = NULL;
    int i = 0;
    pReturn = (SinglyList*)malloc(sizeof(SinglyList));
    if (pReturn != NULL)
    {
        memset(pReturn, 0, sizeof(SinglyList)); //구조체의 속성값을 모두 0으로 초기화
    }
    else
    {
        printf("Error : 메모리 할당 실패\n");
        return NULL;
    }

    return pReturn;
}

void DeleteSinglyList(SinglyList* _pList)
{
    if (_pList != NULL)
    {
        ClearSinglyList(_pList);
        free(_pList);
    }
}

void ClearSinglyList(SinglyList* _pList)
{
    if (_pList != NULL)
    {
        if (_pList->currentElementCount > 0)
        {
            RemoveSLElement(_pList, 0);
        }
    }
}

int GetSinglyListLength(SinglyList* _pList)
{
    int ret = 0;

    if (_pList != NULL)
    {
        ret = _pList->currentElementCount;
    }

    return ret;
}

int IsSinglyListEmpty(SinglyList* _pList)
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

int AddSLElement(SinglyList* _pList, int _index, SinglyNode _element)
{
    int ret = FALSE;
    int i = 0;
    SinglyNode* pPreNode = NULL;
    SinglyNode* pNewNode = NULL;
    if (_pList != NULL)
    {
        if (_index >= 0 && _index <= _pList->currentElementCount)
        {
            pNewNode = (SinglyNode*)malloc(sizeof(SinglyNode));
            if (pNewNode != NULL)
            {
                *pNewNode = _element; //노드 값 설정
                pNewNode->pLink = NULL; //링크 초기화

                pPreNode = &(_pList->headerNode);
                for (i = 0; i < _index; ++i)
                {
                    pPreNode = pPreNode->pLink; //노드가 추가될 위치로 이동
                }

                pNewNode->pLink = pPreNode->pLink;
                pPreNode->pLink = pNewNode; 
                //추가된 노드와 기존 노드 사이의 링크 재설정

                _pList->currentElementCount++;
                ret = TRUE;
            }
            else
            {
                printf("Error : 메모리 할당 실패\n");
                return ret;
            }
        }
        else
        {
            printf("Error : Index[%d] 범위 초과\n", _index);
        }

        return ret;
    }
    return 0;
}

int RemoveSLElement(SinglyList* _pList, int _index)
{
    int ret = FALSE;
    int i = 0;
    int count = 0;
    SinglyNode* pNode = NULL;
    SinglyNode* pDelNode = NULL;
    if (_pList != NULL)
    {
        count = GetSinglyListLength(_pList);
        if (_index >= 0 && _index < count)
        {
            pNode = &(_pList->headerNode);
            for (i = 0; i < _index; ++i)
            {
                pNode = pNode->pLink;
                //제거할 노드 위치로 이동
            }

            pDelNode = pNode->pLink;
            pNode->pLink = pDelNode->pLink;
            //제거할 노드와 기존 노드 사이의 링크 재설정
            free(pDelNode); //제거할 노드 메모리 해제
            _pList->currentElementCount--;
            ret = TRUE;
        }
        else
        {
            printf("Error : Index[%d] 범위 초과\n", _index);
        }

        return ret;
    }
}

SinglyNode* GetSLElement(SinglyList* _pList, int _index)
{
    SinglyNode* pReturn = NULL;
    int i = 0;
    SinglyNode* pNode = NULL;
    if (_pList != NULL)
    {
        if (_index >= 0 && _index < _pList->currentElementCount)
        {
            pNode = &(_pList->headerNode);
            for (i = 0; i <= _index; ++i)
            {
                pNode = pNode->pLink;
            }

            pReturn = pNode;
        }
    }

    return pReturn;
}
