#ifndef T2_H
#define T2_H

typedef struct
{
    int *heap;
    int size;
    int capacity;
} PriorityQueue;

PriorityQueue *createPriorityQueue(int capacity);
void destroyPriorityQueue(PriorityQueue *queue);
int parent(int i);
int leftChild(int i);
int rightChild(int i);
void shiftUp(PriorityQueue *queue, int i);
void shiftDown(PriorityQueue *queue, int i);
void insert(PriorityQueue *queue, int p);
int extractMax(PriorityQueue *queue);
void changePriority(PriorityQueue *queue, int i, int p);
int getMax(PriorityQueue *queue);
void removeElement(PriorityQueue *queue, int i);

#endif
