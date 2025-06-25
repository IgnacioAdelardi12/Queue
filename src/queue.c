#include "queue.h"
#include <stdlib.h>

typedef struct node {
    void *data;
    struct node *next;
} node_t;

struct queue {
    node_t *first;
    node_t *last;
    size_t size;
};

Queue *queue_create() {
    Queue *queue = malloc(sizeof(Queue));
    if (!queue) return NULL;
    queue->first = NULL;
    queue->last = NULL;
    queue->size = 0;
    return queue;
}

bool queue_enqueue(Queue *queue, void *value) {
    node_t *new_node = malloc(sizeof(node_t));
    if (!new_node) return false;

    new_node->data = value;
    new_node->next = NULL;

    if (queue->last) {
        queue->last->next = new_node;
    } else {
        queue->first = new_node;
    }

    queue->last = new_node;
    queue->size++;
    return true;
}

void *queue_dequeue(Queue *queue) {
    if (!queue->first) return NULL;

    node_t *node = queue->first;
    void *data = node->data;

    queue->first = node->next;
    if (!queue->first) {
        queue->last = NULL;
    }

    free(node);
    queue->size--;
    return data;
}

void *queue_front(Queue *queue) {
    if (!queue->first) return NULL;
    return queue->first->data;
}

bool queue_is_empty(Queue *queue) {
    return queue->size == 0;
}

size_t queue_size(Queue *queue) {
    return queue->size;
}

void queue_destroy(Queue *queue) {
    while (!queue_is_empty(queue)) {
        queue_dequeue(queue);
    }
    free(queue);
}

void queue_destroy_all(Queue *queue, void (*destroy_func)(void *)) {
    while (!queue_is_empty(queue)) {
        void *data = queue_dequeue(queue);
        if (destroy_func) destroy_func(data);
    }
    free(queue);
}
