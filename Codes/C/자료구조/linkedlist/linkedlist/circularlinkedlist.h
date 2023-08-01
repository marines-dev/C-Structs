#pragma once
#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE	1
#define FALSE	0

#endif


#ifndef _CIRCULARLINKEDLIST_
#define _CIRCULARLINKEDLIST_

typedef struct
{
	int data;
	struct CircularNode* pLink;
} CircularNode;

typedef struct
{
	int currentElementCount; //���� ����� ������ ����
	CircularNode* pLink; //��� ������
} CircularList;

CircularList* CreateCircularLinkedList();
void DeleteCircularLinkedList(CircularList* _pList);
void ClearCircularLinkedList(CircularList* _pList);
int GetCircularLinkedListLength(CircularList* _pList);

int IsCircularLinkedListEmpty(CircularList* _pList);

int AddCLElement(CircularList* _pList, int _index, CircularNode _element);
int RemoveCLElement(CircularList* _pList, int _index);
CircularNode* GetCLElement(CircularList* _pList, int _index);

#endif _CIRCULARLINKEDLIST_
