#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraystack.h"

ArrayStack* CreateArrayStack(int _maxElementCount)
{
    ArrayStack* pReturn = NULL;
    
    if (_maxElementCount > 0)
    {
        pReturn = (ArrayStack*)malloc(sizeof(ArrayStack));
        if (pReturn != NULL)
        {
            memset(pReturn, 0, sizeof(ArrayStack));
            pReturn->maxElementCount = _maxElementCount;
        }
        else
        {
            printf("Falied : Allocate Memory\n");
            return NULL;
        }

        pReturn->pElement = (ArrayStackNode*)malloc(sizeof(ArrayStackNode) * _maxElementCount);
        if (pReturn->pElement != NULL)
        {
            memset(pReturn->pElement, 0, sizeof(ArrayStackNode) * _maxElementCount);
        }
        else
        {
            printf("Falied : Allocate Memory\n");
            return NULL;
        }

        return pReturn;
    }
}

void DeleteArrayStack(ArrayStack* _pStack)
{
    if (_pStack != NULL)
    {
        if (_pStack->pElement != NULL)
        {
            free(_pStack->pElement);
        }

        free(_pStack);
    }
}

int IsArrayStackFull(ArrayStack* _pStack)
{
    int ret = FALSE;

    if (_pStack != NULL)
    {
        if (_pStack->currentElementCount == _pStack->maxElementCount)
        {
            ret = TRUE;
        }
    }

    return ret;
}

int IsArrayStackEmpty(ArrayStack* _pStack)
{
    int ret = FALSE;

    if (_pStack->currentElementCount == 0)
    {
        ret = TRUE;
    }

    return ret;
}

int PushAS(ArrayStack* _pStack, ArrayStackNode element)
{
    int ret = FALSE;

    if (_pStack != NULL)
    {
        if (IsArrayStackFull(_pStack) == FALSE)
        {
            _pStack->pElement[_pStack->currentElementCount] = element;
            _pStack->currentElementCount++;
            ret = TRUE;
        }
        else
        {
            printf("Failed : Stack is Full\n");
        }
        
        return;
    }
}

ArrayStackNode PopAS(ArrayStack* _pStack)
{
    ArrayStackNode pReturn;

    if (_pStack != NULL)
    {
        if (IsArrayStackEmpty(_pStack) == FALSE)
        {
            pReturn = _pStack->pElement[_pStack->currentElementCount - 1];
            _pStack->currentElementCount--;
        }
        else
        {
            printf("Failed : Stack is Empty");
        }
    }

    return pReturn;
}

ArrayStackNode PeekAS(ArrayStack* _pStack)
{
    ArrayStackNode pReturn;
    if (IsArrayStackEmpty(_pStack) == FALSE)
    {
        pReturn = _pStack->pElement[_pStack->currentElementCount - 1];
    }
    else
    {
        printf("Failed : Stack is Empty");
    }

    return pReturn;
}
