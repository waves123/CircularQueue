#include "CircularQueue.h"

int main()
{
	CQueue *intcqueue = (CQueue*)malloc(sizeof(CQueue));
	int i[5] = { 0, 1, 2, 3, 4 };
	char *s[3] = { "aa", "bbb", "c" };
	void *dedata = malloc(sizeof(char));
	int j = 5;

	CreateCQueue(intcqueue, 3, sizeof(int));
	if (intcqueue->Enqueue(intcqueue, &i[0]))
		printf("Enqueue\n");
	else
		printf("Full\n");
	if (intcqueue-> Enqueue(intcqueue, &i[1]))
		printf("Enqueue\n");
	else
		printf("Full\n");
	if (intcqueue-> Enqueue(intcqueue, &i[2]))
		printf("Enqueue\n");
	else
		printf("Full\n");
	if (intcqueue-> Enqueue(intcqueue, &i[3]))
		printf("Enqueue\n");
	else
		printf("Full\n");

	if (intcqueue->Dequeue(intcqueue, dedata))
		printf("Deqeueu : %d\n", *(int *)dedata);
	else
		printf("Empty\n");

	intcqueue->DeleteQueue(intcqueue);
}