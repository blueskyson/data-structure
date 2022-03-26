#include "queue.h"
#include <stdio.h>

int main()
{
    queue_t q;
    init_queue(&q);
    printf("size: %d\n", q.size);
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    printf("size: %d\n", q.size);
    printf("dequeue: %d\n", dequeue(&q));
    printf("dequeue: %d\n", dequeue(&q));
    printf("dequeue: %d\n", dequeue(&q));
    printf("dequeue: %d\n", dequeue(&q));
    printf("dequeue: %d\n", dequeue(&q));

    return 0;
}