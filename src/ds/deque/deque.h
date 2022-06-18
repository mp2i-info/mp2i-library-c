typedef struct list {
    int val;
    struct list* next;
    struct list* prev;
} list;

list* list_new(int);

typedef struct deque {
    list* left;
    list* right;
} deque;

deque* empty();
int is_empty(deque*);

void add_right(deque*, int);
void add_left(deque*, int);

int peek_left(deque*);
int peek_right(deque*);

void pop_left(deque*);
void pop_right(deque*);

void deque_print(deque*);
