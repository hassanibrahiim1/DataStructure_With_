#include "global.h"


//#define LIMITED_MOMORY
#ifdef LIMITED_MOMORY 
/*Array Based Implementation*/
typedef struct queue {
    QueueEntry enrty[MAX_QUEUE];
    int front, rear, size;
}Queue;

#else
/*Pointer Based Implementation*/
typedef struct queuenode {
    QueueEntry entry ;
    struct queuenode *next ; 
}QueueNode;

typedef struct queue {
    QueueNode * front;
    QueueNode * rear;
    int size;
}Queue;

#endif // LIMITED_MOMORY

void QueueInit(Queue * pq);

int IsQueueFull(Queue * pq);
void InQueue(QueueEntry e, Queue * pq);

int IsQueueEmpty(Queue * pq);
QueueEntry DeQueue( Queue * pq);

int QueueSize(Queue * pq);
void TraverseQueue(Queue * pq, void(*visit)(QueueEntry));
void ClearQueue(Queue * pq);