#pragma once
#ifndef _ARRAYLIST_
#define _ARRAYLIST_

typedef struct
{
	int data;
} ArrayListNode;

typedef struct
{
	int maxElementCount;
	int currentElementCount;
	ArrayListNode* pElement;
} ArrayList;

ArrayList* CreateArrayList(int _maxElementCount); //리스트 생성
void DeleteArrayList(ArrayList* _pList); //리스트 삭제
int AddElement(ArrayList* _pList, int _position, ArrayListNode _element); //원소 추가
int RemoveElement(ArrayList* _pList, int _position); //원소 제거
int IsArrayListFull(ArrayList* _pList); //원소 추가 가능 여부 검사
ArrayListNode* GetElement(ArrayList* _pList, int _position); //원소 반환
void ClearArrayList(ArrayList* _pList); // 리스트 초기화
int GetArrayListLength(ArrayList* _pList); //원소반환

#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE 1
#define FALSE 0

#endif