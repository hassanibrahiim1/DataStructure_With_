#include "global.h"
#include "queue.h"
#include<stdlib.h>

void QueueInit(Queue * pq){
    #ifdef LIMITED_MOMORY
        pq->front = 0;
        pq->rear = -1;
        pq->size = 0;
    #else
        pq->front = NULL;
        pq->rear = NULL;
        pq->size = 0;
    #endif
}

int IsQueueFull(Queue * pq){
    #ifdef LIMITED_MOMORY
        return (pq->size == MAX_QUEUE);
    #else
        return 0 ;
    #endif
}
void InQueue(QueueEntry e, Queue * pq)
{
    #ifdef LIMITED_MOMORY
        pq->rear = (pq->rear+1) % MAX_QUEUE ; 
        pq->enrty[pq->rear] = e ;
        pq->size++;
    #else
    QueueNode* pn = (QueueNode*)malloc(sizeof(QueueNode));
    pn->entry = e;
    pn->next = NULL;
    if(!pq->size)
    {
        pq->front = pn;
    }
    else
    {
        pq->rear->next = pn;
    }
    pq->rear = pn;
    pq->size++;
    #endif
}

int IsQueueEmpty(Queue * pq){
    return !(pq->size);
}
QueueEntry DeQueue( Queue * pq){
    QueueEntry e ;
#ifdef LIMITED_MOMORY
    e = pq->enrty[pq->front];
    pq->front = (pq->front+1) % MAX_QUEUE;
    pq->size--;
    return e;
#else
    e = pq->front->entry;
    QueueNode* pn = pq->front;
    if (pq->size == 1)
    {
        pq->rear = NULL;
    }
    pq->front = pn->next;
    free(pn);
    pq->size--;
    return e;
#endif
}

int QueueSize(Queue * pq){
    return pq->size;
}
void ClearQueue(Queue * pq){
#ifdef LIMITED_MOMORY
    pq->rear = -1 ;
    pq->front = 0;
    pq->size = 0;
#else
    while (pq->front)
    {
        pq->rear = pq->front->next;
        free(pq->front);
        pq->front = pq->rear;
    }
    pq->size = 0;
#endif
}
void TraverseQueue(Queue * pq, void(*visit)(QueueEntry)){
#ifdef LIMITED_MOMORY
/*Here We use count to count number of iterations and i for access array index*/
int i = pq->front ; 
for(int count = 0; count < pq->size ; count++){
    (*visit)(pq->enrty[i]);
    i =( i + 1 ) % MAX_QUEUE ; 
}
#else
QueueNode *pn = pq->front;
    while (pn)
    {
        (*visit)(pn->entry);
        pn = pn->next;
    }
#endif
}