#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

Queue createQueue(int capacity) {
    Queue queue;
    queue.data = (int *)malloc(sizeof(int) * capacity); // Allocate memory to store `capacity`.
    queue.front = 0;  // front pointer at the beginning.
    queue.rear = -1; // Rear is -1 in empty queue.
    queue.size = 0;  
    queue.capacity = capacity; 
    return queue;                         
}

bool enqueue(Queue *queue, int value) {
    if (queue->size == queue->capacity) { // Check if the queue is full.
        printf("Queue Overflow\n");  // If full, print the error message.
        return false;                               
    }
    queue->rear = (queue->rear + 1) % queue->capacity; // Move rear to the next position.
    queue->data[queue->rear] = value; // Add the new value at the rear position.
    queue->size++;// Increment the size of the queue.
    return true; 
}

bool dequeue(Queue *queue, int *value) {
    if (queue->size == 0) { // Check if the queue is empty.
        printf("Queue Underflow\n"); // If empty, print error message.
        return false;                                  
    }
    *value = queue->data[queue->front]; // Get the value at the front of the queue.
    queue->front = (queue->front + 1) % queue->capacity; // Move the front pointer (circularly).
    queue->size--; // Decrease the size of the queue.
    return true;                                       
}

void freeQueue(Queue *queue) {
    free(queue->data); // Free the allocated memory for the queue data.
    queue->data = NULL;  // Set the data pointer to NULL
    // Reset the Queue.
    queue->front = 0; 
    queue->rear = -1; 
    queue->size = 0;  
    queue->capacity = 0; 
}

void printQueue(const Queue *queue) {
    if (queue->size == 0) {   // Check if the queue is empty.
        printf("Queue is empty.\n"); // Print a message if the queue is empty.
        return;
    }

    printf("Queue (front to rear): ");
    for (int i = 0; i < queue->size; i++) { // Loop through the queue.
        int index = (queue->front + i) % queue->capacity; // Calculate the actual index.
        printf("%d ", queue->data[index]); // Print each element.
    }
    printf("\n");
}
