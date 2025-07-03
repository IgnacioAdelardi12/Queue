#include <assert.h>
#include <stdio.h>
#include "../includes/queue.h"


void test_queue_operations() {
    printf("=== Basic operations ===\n");
    Queue *q = queue_create();
    printf("Created queue\n");

    assert(queue_is_empty(q));
    printf("Queue is empty (✓)\n");

    int a = 10, b = 20, c = 30;
    assert(queue_enqueue(q, &a));
    printf("Enqueued 10\n");
    assert(queue_enqueue(q, &b));
    printf("Enqueued 20\n");
    assert(queue_enqueue(q, &c));
    printf("Enqueued 30\n");

    assert(queue_size(q) == 3);
    assert(*(int *)queue_front(q) == 10);
    printf("Front is 10 (✓)\n");

    assert(*(int *)queue_dequeue(q) == 10);
    printf("Dequeued 10\n");
    assert(*(int *)queue_dequeue(q) == 20);
    printf("Dequeued 20\n");
    assert(*(int *)queue_dequeue(q) == 30);
    printf("Dequeued 30\n");

    assert(queue_is_empty(q));
    assert(queue_size(q) == 0);
    printf("Queue is empty again (✓)\n");

    queue_destroy(q);
    printf("Queue destroyed\n");

    printf("\n=== Edge cases ===\n");

    q = queue_create();
    printf("Created new queue\n");

    assert(queue_dequeue(q) == NULL);
    printf("Dequeue from empty queue returns NULL (✓)\n");

    assert(queue_front(q) == NULL);
    printf("Front on empty queue returns NULL (✓)\n");

    assert(queue_enqueue(q, NULL));
    printf("Enqueued NULL\n");

    assert(queue_size(q) == 1);
    assert(queue_front(q) == NULL);
    printf("Front is NULL (✓)\n");

    assert(queue_dequeue(q) == NULL);
    printf("Dequeued NULL\n");

    assert(queue_is_empty(q));
    queue_destroy(q);
    printf("Queue destroyed after NULL test\n");

    printf("\n=== Stress test ===\n");

    q = queue_create();
    const int N = 10000;
    int *array = malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        array[i] = i;
        assert(queue_enqueue(q, &array[i]));
    }
    printf("Enqueued %d integers\n", N);
    assert(queue_size(q) == (size_t)N);

    for (int i = 0; i < N; i++) {
        int *ptr = (int *)queue_dequeue(q);
        assert(ptr != NULL);
        assert(*ptr == i);
    }
    printf("Dequeued and verified %d integers (FIFO ✓)\n", N);

    free(array);
    queue_destroy(q);
    printf("Stress test passed and queue destroyed\n");

    printf("All extended queue tests passed! ✅\n");
}

int main() {
    test_queue_operations();
    return 0;
}
