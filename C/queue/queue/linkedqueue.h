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
	char data;
	struct LinkedQueueNode* pLink;
} LinkedQueueNode;

typedef struct
{
	int currentElementCount; //현재 원소의 개수
	LinkedQueueNode* pFrontNode; //Front 노드 포인터
	LinkedQueueNode* pRearNode; //Rear 노드 포인터
} LinkedQueue;

LinkedQueue* CreateLinkedQueue();
void DeleteLinekdQueue(LinkedQueue* _pQueue);
int IsLinkedQueueEmpty(LinkedQueue* _pQueue);

int EnqueueLQ(LinkedQueue* _pQueue, LinkedQueueNode element);
LinkedQueueNode DequeueLQ(LinkedQueue* _pQueue);
LinkedQueueNode PeekLQ(LinkedQueue* _pQueue);

#endif	_LINEKD_QUEUE_
