#pragma once
#ifndef _ARRAY_STACK_
#define _ARRAY_STACK_

typedef struct
{
	char data;
} ArrayStackNode;

typedef struct
{
	int maxElementCount; //�ִ� ���� ����
	int currentElementCount; //���� ���� ����
	ArrayStackNode* pElement; //��� ������ ���� 1���� �迭
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

