#include <assert.h>
#include <stdio.h>
#include "queue.h"

void test_queue_operations() {
    Queue *q = queue_create();
    assert(queue_is_empty(q));
    assert(queue_size(q) == 0);
    assert(queue_front(q) == NULL);

    int a = 10, b = 20, c = 30;
    assert(queue_enqueue(q, &a));
    assert(queue_enqueue(q, &b));
    assert(queue_enqueue(q, &c));

    assert(!queue_is_empty(q));
    assert(queue_size(q) == 3);
    assert(*(int *)queue_front(q) == 10);
    assert(*(int *)queue_dequeue(q) == 10);
    assert(*(int *)queue_dequeue(q) == 20);
    assert(*(int *)queue_dequeue(q) == 30);
    assert(queue_dequeue(q) == NULL);
    assert(queue_is_empty(q));
    assert(queue_size(q) == 0);

    queue_destroy(q);
    printf("All basic queue tests passed!\n");
}

int main() {
    test_queue_operations();
    return 0;
}
