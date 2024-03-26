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
	int currentElementCount; //���� ������ ����
	LinkedQueueNode* pFrontNode; //Front ��� ������
	LinkedQueueNode* pRearNode; //Rear ��� ������
} LinkedQueue;

LinkedQueue* CreateLinkedQueue();
void DeleteLinekdQueue(LinkedQueue* _pQueue);
int IsLinkedQueueEmpty(LinkedQueue* _pQueue);

int EnqueueLQ(LinkedQueue* _pQueue, LinkedQueueNode element);
LinkedQueueNode DequeueLQ(LinkedQueue* _pQueue);
LinkedQueueNode PeekLQ(LinkedQueue* _pQueue);

#endif	_LINEKD_QUEUE_
