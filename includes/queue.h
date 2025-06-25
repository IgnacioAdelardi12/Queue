#ifndef QUEUE_H_
#define QUEUE_H_

#include <stdlib.h>
#include <stdbool.h>

typedef struct queue Queue;

Queue *queue_create();
void queue_destroy(Queue *);
void queue_destroy_all(Queue *, void (*destroy_func)(void *));

// Each of these functions runs in O(1) time
size_t queue_size(Queue *);
void *queue_front(Queue *);
bool queue_enqueue(Queue *, void *);
void *queue_dequeue(Queue *);
bool queue_is_empty(Queue *);

#endif // QUEUE_H_
