#include <assert.h>

#include "deque.h"

int main() {
    deque* q = empty();
    add_right(q, 1);
    add_right(q, 2);
    deque_print(q);
    assert(peek_left(q) == 1);
    assert(peek_right(q) == 2);
}
