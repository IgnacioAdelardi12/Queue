# Queue in C
This project implements a dynamic queue (FIFO) as an abstract data type in C, using a linked list internally to ensure that all core operations run in O(1) time.
## Build & Run
### Compile and run tests:
```sh
make test
```
### Clean build files:
```sh
make clean
```

## Features
- Fully generic via void * (can store any pointer type)
- All operations guaranteed in constant time O(1)
- Safe memory handling with optional deep destruction
- lean separation of interface (includes/) and implementation (src/)
- Includes automated tests with assert and stress cases

## API Summary
Queue *queue_create();
void queue_destroy(Queue *);
void queue_destroy_all(Queue *, void (*destroy_func)(void *));
bool queue_enqueue(Queue *, void *);
void *queue_dequeue(Queue *);
void *queue_front(Queue *);
bool queue_is_empty(Queue *);
size_t queue_size(Queue *);