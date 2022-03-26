#include "stack.h"
#include <stdio.h>

int main() {
    stack_t s;
    init_stack(&s);
    if (is_empty(&s)) {
        puts("hello");
        printf("size: %d\n", get_size(&s));
    }
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    printf("size: %d\n", get_size(&s));
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    return 0;
}