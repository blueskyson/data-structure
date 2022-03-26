#include <stdbool.h>
#define MAXSIZE 100

typedef struct {
    int size;
    int data[MAXSIZE];
} stack_t;

void init_stack(stack_t *s) {
    s->size = 0;
}

bool is_empty(stack_t *s) {
    return s->size < 1;
}

int get_size(stack_t *s)
{
    return s->size;
}

int peek(stack_t *s)
{
    if (s->size) {
        return s->data[s->size - 1];
    }
    return -1;   // stack empty
}

bool push(stack_t *s, int x) {
    if (s->size < MAXSIZE) {
        s->data[s->size++] = x;
        return true;
    }
    return false; // stack overflow
}

int pop(stack_t *s) {
    if (s->size) {
        return s->data[--s->size];
    }
    return -1;
}