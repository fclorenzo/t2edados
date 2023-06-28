#include <stdio.h>
#include "t2.h"

int main()
{
    printf("\nEnter the total capacity for the queue: ");
    int capacity, qt, element;
    scanf("%i", &capacity);
    PriorityQueue *queue = createPriorityQueue(capacity);

    printf("\nEnter the quantity of elements to insert in the queue: ");
    scanf("%i", &qt);
    for (int i = 0; i < qt; i++)
    {
        printf("\nEnter the element to be inserted: ");
        fflush(stdin);
        scanf("%i", &element);
        insert(queue, element);
    }

    printf("\nPriority Queue: ");
    for (int i = 0; i <= queue->size; i++)
    {
        printf("\n%i (Parent: %i", queue->heap[i], queue->heap[parent(i)]);
        if (leftChild(i) <= queue->size)
            printf(", Left Child: %i", queue->heap[leftChild(i)]);
        if (rightChild(i) <= queue->size)
            printf(", Right Child: %i", queue->heap[rightChild(i)]);
        printf(")");
    }

    extractMax(queue);
    printf("\nPriority Queue after removing the highest priority element: ");
    for (int i = 0; i <= queue->size; i++)
    {
        printf("\n%i (Parent: %i", queue->heap[i], queue->heap[parent(i)]);
        if (leftChild(i) <= queue->size)
            printf(", Left Child: %i", queue->heap[leftChild(i)]);
        if (rightChild(i) <= queue->size)
            printf(", Right Child: %i", queue->heap[rightChild(i)]);
        printf(")");
    }

    destroyPriorityQueue(queue);

    return 0;
}
