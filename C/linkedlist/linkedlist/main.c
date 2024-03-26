// linkedlist.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

//#include <stdio.h>
//#include <stdlib.h>
//#include "singlylinkedlist.h"
//
//void DisplayLinkedList(SinglyList* _pList)
//{
//	int i = 0;
//	if (_pList != NULL)
//	{
//		printf("현재 원소 개수 : %d\n", _pList->currentElementCount);
//
//		for (i = 0; i < _pList->currentElementCount; ++i)
//		{
//			printf("Index[%d] : %d\n", i, GetSLElement(_pList, i)->data);
//		}
//	}
//	else
//	{
//		printf("원소가 없습니다.\n");
//	}
//}
//
//int main()
//{
//	int i = 0;
//	SinglyList* pList = NULL;
//	SinglyNode* pNode = NULL;
//	SinglyNode node;
//
//	pList = CreateLinkedList();
//	if (pList != NULL)
//	{
//		node.data = 10;
//		AddElement(pList, 0, node);
//
//		node.data = 20;
//		AddElement(pList, 1, node);
//
//		node.data = 30;
//		AddElement(pList, 2, node);
//		DisplayLinkedList(pList);
//
//		RemoveElement(pList, 1);
//		DisplayLinkedList(pList);
//
//		RemoveElement(pList, 0);
//		DisplayLinkedList(pList);
//
//		DeleteLinkedList(pList);
//	}
//
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include "circularlinkedlist.h"
//
//void DisplayLinkedList(CircularList* _pList)
//{
//	int i = 0;
//	if (_pList != NULL)
//	{
//		printf("현재 원소 개수 : %d\n", _pList->currentElementCount);
//
//		for (i = 0; i < _pList->currentElementCount; ++i)
//		{
//			printf("Index[%d] : %d\n", i, GetCLElement(_pList, i)->data);
//		}
//	}
//	else
//	{
//		printf("원소가 없습니다.\n");
//	}
//}
//
//int main()
//{
//	int i = 0;
//	CircularList* pList = NULL;
//	CircularNode* pNode = NULL;
//	CircularNode node;
//
//	pList = CreateCircularList();
//	if (pList != NULL)
//	{
//		node.data = 10;
//		AddCLElement(pList, 0, node);
//
//		node.data = 20;
//		AddCLElement(pList, 1, node);
//
//		node.data = 30;
//		AddCLElement(pList, 2, node);
//		DisplayLinkedList(pList);
//
//		RemoveCLElement(pList, 1);
//		DisplayLinkedList(pList);
//
//		RemoveCLElement(pList, 0);
//		DisplayLinkedList(pList);
//
//		DeleteCircularList(pList);
//	}
//
//	return 0;
//}

#include <stdio.h>
#include <stdlib.h>
#include "doublylinkedlist.h"

void DisplayLinkedList(DoublyList* _pList)
{
	int i = 0;
	if (_pList != NULL)
	{
		printf("현재 원소 개수 : %d\n", _pList->currentElementCount);

		for (i = 0; i < _pList->currentElementCount; ++i)
		{
			printf("Index[%d] : %d\n", i, GetDLElement(_pList, i)->data);
		}
	}
	else
	{
		printf("원소가 없습니다.\n");
	}
}

int main()
{
	int i = 0;
	DoublyList* pList = NULL;
	DoublyNode* pNode = NULL;
	DoublyNode node;

	pList = CreateDoublyList();
	if (pList != NULL)
	{
		node.data = 10;
		AddDLElement(pList, 0, node);

		node.data = 20;
		AddDLElement(pList, 1, node);

		node.data = 30;
		AddDLElement(pList, 2, node);
		DisplayLinkedList(pList);

		RemoveDLElement(pList, 1);
		DisplayLinkedList(pList);

		RemoveDLElement(pList, 0);
		DisplayLinkedList(pList);

		DeleteDoublyList(pList);
	}

	return 0;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
