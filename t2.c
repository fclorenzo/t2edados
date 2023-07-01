#include <stdio.h>
#include <stdlib.h>
#include "t2.h"

PriorityQueue *createPriorityQueue(int capacity)
{
    PriorityQueue *queue = (PriorityQueue *)malloc(sizeof(PriorityQueue));
    queue->heap = (int *)malloc(capacity * sizeof(int));
    queue->size = -1;
    queue->capacity = capacity;
    return queue;
}

void destroyPriorityQueue(PriorityQueue *queue)
{
    free(queue->heap);
    free(queue);
}

int parent(int i)
{
    return (i - 1) / 2;
}

int leftChild(int i)
{
    return (2 * i) + 1;
}

int rightChild(int i)
{
    return (2 * i) + 2;
}

void shiftUp(PriorityQueue *queue, int i)
{
    while (i > 0 && queue->heap[parent(i)] < queue->heap[i])
    {
        int temp = queue->heap[parent(i)];
        queue->heap[parent(i)] = queue->heap[i];
        queue->heap[i] = temp;
        i = parent(i);
    }
}

void shiftDown(PriorityQueue *queue, int i)
{
    int maxIndex = i;
    int left = leftChild(i);
    int right = rightChild(i);

    if (left <= queue->size && queue->heap[left] > queue->heap[maxIndex])
    {
        maxIndex = left;
    }

    if (right <= queue->size && queue->heap[right] > queue->heap[maxIndex])
    {
        maxIndex = right;
    }

    if (i != maxIndex)
    {
        int temp = queue->heap[i];
        queue->heap[i] = queue->heap[maxIndex];
        queue->heap[maxIndex] = temp;
        shiftDown(queue, maxIndex);
    }
}

void insert(PriorityQueue *queue, int p)
{
    queue->size++;
    queue->heap[queue->size] = p;
    shiftUp(queue, queue->size);
}

int getMax(PriorityQueue *queue)
{
    if (queue->size < 0)
    {
        printf("\nPriority queue is empty.");
        return -1; // or any other appropriate error value
    }

    return queue->heap[0];
}

void extractMax(PriorityQueue *queue)
{
    if (queue->size < 0)
    {
        printf("\nPriority queue is empty. Cannot extract maximum element.");
        return; // or any other appropriate error value
    }

    queue->heap[0] = queue->heap[queue->size];
    queue->size--;
    shiftDown(queue, 0);
}
void options_to_choose()
{
    printf("\nMenu");
    printf("\nOptions: ");
    printf("\n1: Insert element(s)");
    printf("\n2: Print the queue");
    printf("\n3: Dequeue the element with the highest priority");
    printf("\n0: Exit the program");
    printf("\nEnter your choice: ");
}
void print_queue(PriorityQueue *queue)
{
    for (int i = 0; i <= queue->size; i++)
    {
        printf("\n%i (", queue->heap[i]);

        if (i == 0)
            printf("Root node");
        else
            printf("Parent: %i", queue->heap[parent(i)]);

        if (leftChild(i) <= queue->size)
            printf(", Left Child: %i", queue->heap[leftChild(i)]);
            
        if (rightChild(i) <= queue->size)
            printf(", Right Child: %i", queue->heap[rightChild(i)]);
        printf(")");
    }
}
