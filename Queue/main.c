#include "global.h"
#include "queue.h"
#include <stdio.h>


void printelement(QueueEntry e)
{
    printf("%d\t", e);
}
int main()
{
    Queue q ; 
    QueueInit(&q);
    for(int i = 1 ; i < 20 ; i+=2)
    {
        InQueue(i, &q);
    }
    printf("size = %d\n", QueueSize(&q));
    TraverseQueue(&q, &printelement);
    printf("\n");
    for (int i = 0; i < 3; i++)
    {
        printf("QeQueue = %d\n", DeQueue(&q));
    }
    printf("size of Queue = %d\n", QueueSize(&q));
    
    return 0;
}