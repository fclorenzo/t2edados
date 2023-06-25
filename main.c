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

    printf("Priority Queue: ");
    for (int i = 0; i <= queue->size; i++)
    {
        printf("%i ", queue->heap[i]);
    }
    printf("\n");

    printf("Node with maximum priority: %i\n", extractMax(queue));

    printf("Priority Queue after extracting maximum: ");
    for (int i = 0; i <= queue->size; i++)
    {
        printf("%i ", queue->heap[i]);
    }
    printf("\n");

    changePriority(queue, 2, 49);

    printf("Priority Queue after priority change: ");
    for (int i = 0; i <= queue->size; i++)
    {
        printf("%i ", queue->heap[i]);
    }
    printf("\n");

    removeElement(queue, 3);

    printf("Priority Queue after removing the element: ");
    for (int i = 0; i <= queue->size; i++)
    {
        printf("%i ", queue->heap[i]);
    }
    printf("\n");

    destroyPriorityQueue(queue);

    return 0;
}
