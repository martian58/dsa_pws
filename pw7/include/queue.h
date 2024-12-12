#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

typedef struct {
    int *data;
    int front;
    int rear;
    int size;
    int capacity;
} Queue;

/**
 * @brief Creates a new queue with a given capacity.
 * 
 * @param capacity The maximum number of elements the queue can hold.
 * @return A Queue object initialized with the specified capacity.
 */
Queue createQueue(int capacity);

/**
 * @brief Enqueues an element into the queue.
 * 
 * @param queue Pointer to the Queue object.
 * @param value The value to enqueue into the queue.
 * @return true if the value was successfully enqueued, false if the queue is full.
 */
bool enqueue(Queue *queue, int value);

/**
 * @brief Dequeues an element from the queue.
 * 
 * @param queue Pointer to the Queue object.
 * @param value Pointer to store the dequeued value.
 * @return true if a value was successfully dequeued, false if the queue is empty.
 */
bool dequeue(Queue *queue, int *value);

/**
 * @brief Frees the resources used by the queue.
 * 
 * @param queue Pointer to the Queue object.
 */
void freeQueue(Queue *queue);

/**
 * @brief Prints the elements in the queue from front to rear.
 * 
 * @param queue Pointer to the Queue object.
 */
void printQueue(const Queue *queue);

#endif 
