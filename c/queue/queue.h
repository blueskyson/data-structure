#include <stdbool.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node *next;
} node_t;

typedef struct {
    int size;
    node_t *head; 
} queue_t;

void init_queue(queue_t *q)
{
    q->size = 0;
    q->head = NULL;
}

bool enqueue(queue_t *q, int x)
{
    node_t *new_node = malloc(sizeof(node_t));
    if (!new_node)
        return false;

    new_node->data = x;
    new_node->next = q->head;
    q->head = new_node;
    q->size++;
    return true;
}

int dequeue(queue_t *q)
{
    if (!q->head)
        return -1;
    
    node_t **indirect = &q->head;
    while ((*indirect)->next)
        indirect = &(*indirect)->next;
    node_t *del = *indirect;
    *indirect = NULL;
    int ret = del->data;
    free(del);
    q->size--;
    return ret;
}