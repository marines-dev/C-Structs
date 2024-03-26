#pragma once
#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE	1
#define FALSE	0

#endif

#ifndef _DOUBLYLIST_
#define _DOUBLYLIST_

typedef struct
{
	int data;
	struct DoublyNode* pLLink;
	struct DoublyNode* pRLink;
} DoublyNode;

typedef struct
{
	int currentElementCount; //현재 저장된 원소의 개수
	DoublyNode headerNode; //헤더 노드
} DoublyList;

DoublyList* CreateDoublyList();
void DeleteDoublyList(DoublyList* _pList);
void ClearDoublyList(DoublyList* _pList);
int GetDoublyListLength(DoublyList* _pList);

int IsDoublyListEmpty(DoublyList* _pList);

int AddDLElement(DoublyList* _pList, int _index, DoublyNode _element);
int RemoveDLElement(DoublyList* _pList, int _index);
DoublyNode* GetDLElement(DoublyList* _pList, int _index);

#endif _DOUBLYLIST_