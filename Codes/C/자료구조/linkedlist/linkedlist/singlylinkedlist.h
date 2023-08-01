#pragma once
#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE	1
#define FALSE	0

#endif

#ifndef _SINGLYLINKEDLIST_
#define _SINGLYLINKEDLIST_

typedef struct
{
	int data;
	struct SinglyNode* pLink;
} SinglyNode;

typedef struct
{
	int currentElementCount; //현재 원소 개수
	SinglyNode headerNode; //헤더 노드
} SinglyList;

SinglyList* CreateSinglyList();
void DeleteSinglyList(SinglyList* _pList);
void ClearSinglyList(SinglyList* _pList);
int GetSinglyListLength(SinglyList* _pList);

int IsSinglyListEmpty(SinglyList* _pList);

int AddSLElement(SinglyList* _pList, int _index, SinglyNode _element);
int RemoveSLElement(SinglyList* _pList, int _index);
SinglyNode* GetSLElement(SinglyList* _pList, int _index);

#endif _SINGLYLINKEDLIST_
