#include "linked-list.h"

int main() {
    node_t *head = NULL;
    print_list(head);
    print_list_reverse(head);
    
    insert_head(&head, 1);
    insert_head(&head, 2);
    insert_head(&head, 3);
    print_list(head);
    print_list_reverse(head);

    insert_tail(&head, 4);
    insert_tail(&head, 5);
    insert_tail(&head, 6);
    print_list(head);
    print_list_reverse(head);

    delete_head(&head);
    delete_head(&head);
    print_list(head);
    print_list_reverse(head);

    delete_tail(&head);
    delete_tail(&head);
    print_list(head);
    print_list_reverse(head);

    return 0;
}
