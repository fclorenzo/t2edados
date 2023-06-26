#include <stdio.h>
#include "t2.h"

int main()
{
    int capacity = 50;
    PriorityQueue *queue = createPriorityQueue(capacity);

    insert(queue, 45);
    insert(queue, 20);
    insert(queue, 14);
    insert(queue, 12);
    insert(queue, 31);
    insert(queue, 7);
    insert(queue, 11);
    insert(queue, 13);
    insert(queue, 7);

    printf("\mPriority Queue: ");
    for (int i = 0; i <= queue->size; i++)
    {
        printf("\n%i ", queue->heap[i]);
    }

    printf("\nNode with maximum priority: %i", extractMax(queue));

    printf("Priority Queue after extracting maximum: ");
    for (int i = 0; i <= queue->size; i++)
    {
        printf("\m%i ", queue->heap[i]);
    }

    changePriority(queue, 2, 49);

    printf("\nPriority Queue after priority change: ");
    for (int i = 0; i <= queue->size; i++)
    {
        printf("\n%i ", queue->heap[i]);
    }

    removeElement(queue, 3);

    printf("\nPriority Queue after removing the element: ");
    for (int i = 0; i <= queue->size; i++)
    {
        printf("\n%i ", queue->heap[i]);
    }

    destroyPriorityQueue(queue);

    return 0;
}
