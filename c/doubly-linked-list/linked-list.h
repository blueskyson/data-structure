#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
typedef struct node {
    int data;
    struct node *prev, *next;
} node_t;

bool insert_head(node_t **h, int data)
{
    node_t *new_node = malloc(sizeof(node_t));
    if (!new_node)
        return false;
    new_node->data = data;
    new_node->prev = NULL;
    if (!*h) {
        new_node->next = NULL;
        *h = new_node;
        return true;
    }

    (*h)->prev = new_node;
    new_node->next = *h;
    *h = new_node;
    return true;
}

void delete_head(node_t **h) {
    if (!*h)
        return;
    node_t *del = *h;
    *h = (*h)->next;
    (*h)->prev = NULL;
    free(del);
}

bool insert_tail(node_t **h, int data) {
    node_t *new_node = malloc(sizeof(node_t));
    if (!new_node)
        return false;

    new_node->data = data;
    new_node->next = NULL;
    node_t **indirect = h;
    while ((*indirect)->next)
        indirect = &(*indirect)->next;

    new_node->prev = *indirect;
    (*indirect)->next = new_node;
    return true;
}

void delete_tail(node_t **h) {
    if (!*h)
        return;
    node_t **indirect = h;
    while ((*indirect)->next)
        indirect = &(*indirect)->next;
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

void print_list_reverse(node_t *h) {
    node_t *ptr = NULL;
    while (h) {
        ptr = h;
        h = h->next;
    }
    printf("list reverse data:");
    while (ptr) {
        printf(" %d", ptr->data);
        ptr = ptr->prev;
    }
    printf("\n");
}