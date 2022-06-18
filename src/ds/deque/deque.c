#include "deque.h"

#include <stdio.h>
#include <stdlib.h>

list* list_new(int val) {
    list* l = malloc(sizeof(list));
    l->val = val;
    l->next = NULL;
    l->prev = NULL;
    return l;
}

deque* empty() {
    deque* d = malloc(sizeof(deque));
    d->left = NULL;
    d->right = NULL;
    return d;
}

int is_empty(deque* q) {
    return q->left == NULL;
}

void add_right(deque* q, int x) {
    list* l = list_new(x);
    if (q->left == NULL) {
        q->left = l;
        q->right = l;
    } else {
        l->prev = q->right;
        q->right->next = l;
        q->right = l;
    }
}

int peek_left(deque* q) {
    return q->left->val;
}

int peek_right(deque* q) {
    return q->right->val;
}

void pop_left(deque* q) {
    if (q->left == NULL) {
        return;
    }
    list* l = q->left;
    q->left = l->next;
    if (q->left == NULL) {
        q->right = NULL;
    } else {
        q->left->prev = NULL;
    }
    free(l);
}

void pop_right(deque* q) {
    if (q->right == NULL) {
        return;
    }
    list* l = q->right;
    q->right = l->prev;
    if (q->right == NULL) {
        q->left = NULL;
    } else {
        q->right->next = NULL;
    }
    free(l);
}

void deque_print(deque* q) {
    list* l = q->left;
    while (l) {
        printf("%d ", l->val);
        l = l->next;
    }
    printf("\n");
}
