#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
typedef struct node {
    int data;
    struct node *next;
} node_t;

bool insert_head(node_t **h, int data) {
    node_t *new_node = malloc(sizeof(node_t));
    if (!new_node)
        return false;
    new_node->data = data;
    new_node->next = *h;
    *h = new_node;
    return true;
}

bool insert_tail(node_t **h, int data) {
    node_t *new_node = malloc(sizeof(node_t));
    if (!new_node)
        return false;
    new_node->data = data;
    new_node->next = NULL;
    node_t **indirect = h;
    while (*indirect)
        indirect = &(*indirect)->next;
    *indirect = new_node;
    return true;
}

void delete_head(node_t **h) {
    if (!*h)
        return;
    node_t *del = *h;
    *h = (*h)->next;
    free(del);
}

void delete_tail(node_t **h) {
    if (!*h)
        return;
    node_t **indirect = h;
    while ((*indirect)->next) {
        indirect = &(*indirect)->next;
    }
    node_t *del = *indirect;
    *indirect = NULL;
    free(del);
}

void print_list(node_t *h) {
    printf("list data:");
    while (h) {
        printf(" %d", h->data);
        h = h->next;
    }
    printf("\n");
}