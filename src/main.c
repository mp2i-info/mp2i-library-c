#include <stdio.h>

#include "deque.h"

int main() {
    deque* q = empty();
    add_right(q, 1);
    add_right(q, 2);
    printf("%d\n", peek_left(q));
    printf("%d\n", peek_right(q));
}