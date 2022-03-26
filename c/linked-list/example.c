#include "linked_list.h"

int main() {
    node_t *head = NULL;
    print_list(head);
    insert_head(&head, 1);
    insert_head(&head, 2);
    insert_head(&head, 3);
    print_list(head);
    insert_tail(&head, 4);
    insert_tail(&head, 5);
    insert_tail(&head, 6);
    print_list(head);

    delete_tail(&head);
    print_list(head);

    delete_head(&head);
    print_list(head);
    return 0;
}