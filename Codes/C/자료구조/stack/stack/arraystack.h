#pragma once
#ifndef _ARRAY_STACK_
#define _ARRAY_STACK_

typedef struct
{
	char data;
} ArrayStackNode;

typedef struct
{
	int maxElementCount; //최대 원소 개수
	int currentElementCount; //현재 원소 개수
	ArrayStackNode* pElement; //노드 저장을 위한 1차원 배열
} ArrayStack;

ArrayStack* CreateArrayStack(int _maxElementCount);
void DeleteArrayStack(ArrayStack* _pStack);
int IsArrayStackFull(ArrayStack* _pStack);
int IsArrayStackEmpty(ArrayStack* _pStack);

int PushAS(ArrayStack* _pStack, ArrayStackNode element);
ArrayStackNode PopAS(ArrayStack* _pStack);
ArrayStackNode PeekAS(ArrayStack* _pStack);

#endif	_ARRAYSTACK_

#ifndef _COMMON_STACK_DEF_
#define	_COMMON_STACK_DEF_

#define TRUE	1
#define FALSE	0

#endif	_COMMON_STACK_DEF_

