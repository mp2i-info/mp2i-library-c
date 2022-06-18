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

int* minimum_sliding(int* a, int n, int k) {
    int* min_a = malloc(sizeof(int) * (n - k + 1));
    deque* q = empty();
    for (int i = 0; i < n; i++) {
        deque_print(q);
        while (!is_empty(q) && a[i] <= a[peek_right(q)]) {
            deque_print(q);
            pop_right(q);
        }
        add_right(q, i);
        deque_print(q);
        if (q->left && i - peek_left(q) >= k) {
            pop_left(q);
        }
        deque_print(q);
        if (i - k + 1 >= 0) {
            min_a[i - k + 1] = a[peek_left(q)];
        }
    }
    return min_a;
}

// int main() {
//     int a[] = {-5, 1, 3, -1, -3, 5, 3, 6, 7, 9};
//     int n = sizeof(a) / sizeof(int);
//     int* min_a = minimum_sliding(a, n, 3);
//     for (int i = 0; i < n - 3 + 1; i++) {
//         printf("%d ", min_a[i]);
//     }
//     return 0;
// }