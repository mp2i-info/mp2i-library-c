#include <assert.h>

#include "deque.h"

int main() {
    deque* q = empty();
    add_right(q, 1);
    add_right(q, 2);
    assert(peek_left(q) == 1);
    assert(peek_right(q) == 2);
    pop_left(q);
    add_left(q, 3);
    assert(peek_left(q) == 3);
    assert(peek_right(q) == 2);
    pop_right(q);
    assert(peek_left(q) == 3);
    pop_left(q);
    assert(is_empty(q));
}
