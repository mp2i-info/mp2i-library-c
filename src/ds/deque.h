typedef struct list {
    int val;
    struct list* next;
    struct list* prev;
} list;

typedef struct deque {
    list* left;
    list* right;
} deque;

list* list_new(int val);

deque* empty();

int is_empty(deque* q);

void add_right(deque* q, int x);

int peek_left(deque* q);

int peek_right(deque* q);

void pop_left(deque* q);

void pop_right(deque* q);

void deque_print(deque* q);
