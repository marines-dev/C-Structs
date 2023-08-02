#pragma once
#ifndef _COMMON_QUEUE_DEF_
#define _COMMON_QUEUE_DEF_

#define TRUE	1
#define FALSE	0

#endif	_COMMON_QUEUE_DEF_

#ifndef _ARRAY_QUEUE_
#define _ARRAY_QUEUE_

typedef struct
{
	char element;
} ArrayQueueNode;

typedef struct
{
	int maxElementCount; //최대 원소 개수
	int currentElementCount; //현재 원소 개수
	int front;
	int rear;
	ArrayQueueNode* pElement;
} ArrayQueue;

ArrayQueue* CreateArrayQueue(int _maxElementCount);
void DeleteArrayQueue(ArrayQueue* _pQueue);
int IsArrayQueueFull(ArrayQueue* _pQueue);
int IsArrayQueueEmpty(ArrayQueue* _pQueue);

int EnqueueAQ(ArrayQueue* _pQueue, ArrayQueueNode _element);
ArrayQueueNode DequeueAQ(ArrayQueue* _pQueue);
ArrayQueueNode PeekAQ(ArrayQueue* _pQueue);

#endif	_ARRAY_QUEUE_
