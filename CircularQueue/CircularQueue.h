#ifndef __CIRCULAR_QUEUE_
#define __CIRCULAR_QUEUE_

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define TRUE 1
#define FALSE 0

typedef struct Node Node;
typedef struct CQueue CQueue;

typedef struct Node
{
	void *data;
} Node;

typedef struct CQueue
{
	Node *CQarray;
	int front;
	int rear;

	int capacity;
	int datasize;

	int(*isEmpty)(CQueue *cqueue);
	int(*isFull)(CQueue *cqueue);
	int(*Enqueue)(CQueue *cqueue, void *endata);
	int(*Dequeue)(CQueue *cqueue, void *dedata);
	void(*DeleteQueue)(CQueue *cqueue);
} CQueue;

void CreateCQueue(CQueue *cqueue, int capacity, int datasize);
int isEmpty(CQueue *cqueue);
int isFull(CQueue *cqueue);
int Enqueue(CQueue *cqueue, void *endata);
int Dequeue(CQueue *cqueue, void *dedata);
void DeleteQueue(CQueue *cqueue);

#endif
