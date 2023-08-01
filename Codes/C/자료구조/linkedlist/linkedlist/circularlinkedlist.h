#pragma once
#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE	1
#define FALSE	0

#endif


#ifndef _CIRCULARLIST_
#define _CIRCULARLIST_

typedef struct CircularNodeType
{
	int data;
	struct CircularNode* pLink;
} CircularNode;

typedef struct CircularListType
{
	int currentElementCount; //현재 저장된 원소의 개수
	CircularNode* pLink; //헤드 포인터
} CircularList;

CircularList* CreateCircularLinkedList();
void DeleteCircularList(CircularList* _pList);
void ClearCircularList(CircularList* _pList);
int GetCircularListLength(CircularList* _pList);

int IsCircularListEmpty(CircularList* _pList);

int AddCLElement(CircularList* _pList, int _index, CircularNode _element);
int RemoveCLElement(CircularList* _pList, int _index);
CircularNode* GetCLElement(CircularList* _pList, int _index);

#endif _CIRCULARLIST_
