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
    if (queue->size == queue->capacity - 1)
    {
        printf("\nPriority queue is full. Cannot insert more elements.");
        return;
    }

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

int extractMax(PriorityQueue *queue)
{
    if (queue->size < 0)
    {
        printf("\nPriority queue is empty. Cannot extract maximum element.");
        return -1; // or any other appropriate error value
    }

    int maxElement = queue->heap[0];
    queue->heap[0] = queue->heap[queue->size];
    queue->size--;
    shiftDown(queue, 0);
    return maxElement;
}
