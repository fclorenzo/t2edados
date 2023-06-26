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
        printf("\n%i ", queue->heap[i]);
    }

    printf("\nEnter the position of the element to be removed from the queue: ");
    scanf("%i", &element);
    removeElement(queue, element - 1);

    printf("\nPriority Queue after removing the element: ");
    for (int i = 0; i <= queue->size; i++)
    {
        printf("\n%i ", queue->heap[i]);
    }

    destroyPriorityQueue(queue);

    return 0;
}
