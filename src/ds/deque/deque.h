struct list;

struct list* list_new(int);

struct deque;
typedef struct deque deque;

struct deque* empty();
int is_empty(struct deque* q);

void add_right(struct deque*, int);
void add_left(struct deque*, int);

int peek_left(struct deque*);
int peek_right(struct deque*);

void pop_left(struct deque*);
void pop_right(struct deque*);

void deque_print(struct deque*);
