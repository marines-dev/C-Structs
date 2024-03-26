#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraylist.h"

ArrayList* CreateArrayList(int _maxElementCount)
{
	ArrayList* pReturn = NULL;
	int i = 0;

	if (_maxElementCount > 0)
	{
		pReturn = (ArrayList*)malloc(sizeof(ArrayList));

		if (pReturn != NULL)
		{
			pReturn->maxElementCount = _maxElementCount;
			pReturn->currentElementCount = 0;
			pReturn->pElement = NULL;
		}
		else
		{
			printf("Error : ArrayList 메모리 할당 실패\n");
			return NULL;
		}
	}
	else
	{
		printf("Error : 최대 원소 개수는 0이상이어야 합니다\n");
		return NULL;
	}

	pReturn->pElement = (ArrayListNode*)malloc(sizeof(ArrayListNode) * _maxElementCount);
	if (pReturn->pElement == NULL)
	{
		printf("Error : ArrayListNode 메모리 할당 실패\n");

		free(pReturn);
		return NULL;
	}

	memset(pReturn->pElement, 0, sizeof(ArrayListNode) * _maxElementCount);

	return pReturn;
}

void DeleteArrayList(ArrayList* _pList)
{
	if (_pList != NULL)
	{
		free(_pList->pElement);
		free(_pList);
	}
}

int AddElement(ArrayList* _pList, int _position, ArrayListNode _element)
{
	int ret = FALSE;
	int i = 0;

	if (_pList != NULL)
	{
		if (IsArrayListFull(_pList) != TRUE)
		{
			if (_position >= 0 && _position <= _pList->currentElementCount)
			{
				for (i = _pList->currentElementCount - 1; i >= _position; --i)
				{
					_pList->pElement[i + 1] = _pList->pElement[i];
					//기존 원소들을 오른쪽으로 한 칸씩 이동시킨다.
				}

				_pList->pElement[_position] = _element;
				//새로운 원소 추가

				_pList->currentElementCount++;
				ret = TRUE;
			}
			else
			{
				printf("Error : 위치 인덱스(%d) 범위 초과\n", _position);
			}
		}

		return ret;
	}

	return 0;
}

int RemoveElement(ArrayList* _pList, int _position)
{
	int ret = FALSE;
	int i = 0;

	if (_pList != NULL)
	{
		if (_position >= 0 && _position < _pList->currentElementCount)
		{
			for (i = _position; i < _pList->currentElementCount - 1; ++i)
			{
				_pList->pElement[i] = _pList->pElement[i + 1];
				//기존 원소들을 왼쪽으로 한 칸씩 이동
			}

			_pList->currentElementCount--;
			ret = TRUE;
		}
		else
		{
			printf("Error : 위치 인덱스(%d) 범위 초과\n", _position);
		}
	}

	return ret;
}

int IsArrayListFull(ArrayList* _pList)
{
	int ret = FALSE;
	if (_pList != NULL)
	{
		if (_pList->currentElementCount == _pList->maxElementCount)
		{
			ret = TRUE;
		}
	}

	return ret;
}

ArrayListNode* GetElement(ArrayList* _pList, int _position)
{
	ArrayListNode* pReturn = NULL;
	if (_pList != NULL)
	{
		if (_position >= 0 && _position < GetArrayListLength(_pList))
		{
			pReturn = &(_pList->pElement[_position]);
		}
	}

	return pReturn;
}

int GetArrayListLength(ArrayList* _pList)
{
	int ret = 0;
	if (_pList != NULL)
	{
		ret = _pList->currentElementCount;
	}

	return ret;
}

void ClearArrayList(ArrayList* _pList)
{
}
