#include "CircularQueue.h"

void CreateCQueue(CQueue *cqueue, int capacity, int datasize)
{
	int i;

	cqueue->CQarray = (Node *)malloc(sizeof(Node)*capacity);

	for (i = 0; i<capacity; i++)
	{
		(cqueue->CQarray + i)->data = malloc(sizeof(datasize));
	}
	cqueue->front = 0;
	cqueue->rear = 0;

	cqueue->capacity = capacity;
	cqueue->datasize = datasize;

	cqueue->isEmpty = isEmpty;
	cqueue->isFull = isFull;
	cqueue->Enqueue = Enqueue;
	cqueue->Dequeue = Dequeue;
	cqueue->DeleteQueue = DeleteQueue;
}

int isEmpty(CQueue *cqueue)
{
	if (cqueue->front == cqueue->rear)
		return TRUE;
	else
		return FALSE;
}

int isFull(CQueue *cqueue)
{
	if ((cqueue->rear) - (cqueue->front) == (cqueue->capacity) - 1)
		return TRUE;
	else
		return FALSE;
}

int Enqueue(CQueue *cqueue, void *endata)
{
	if (cqueue->isFull(cqueue))
	{
		return FALSE;
	}
	else
	{
		Node *enNode = cqueue->CQarray + ((cqueue->rear) % (cqueue->capacity));
		memcpy(enNode->data, endata, cqueue->datasize);
		cqueue->rear++;
		return TRUE;
	}
}

int Dequeue(CQueue *cqueue, void *dedata)
{
	if (cqueue->isEmpty(cqueue))
	{
		return FALSE;
	}
	else
	{
		Node *deNode = cqueue->CQarray + ((cqueue->front) % (cqueue->capacity));
		memcpy(dedata, deNode->data, cqueue->datasize);
		cqueue->front++;
		return TRUE;
	}
}

void DeleteQueue(CQueue *cqueue)
{
	free(cqueue->CQarray);
	free(cqueue);
}
