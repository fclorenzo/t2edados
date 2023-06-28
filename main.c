#include <stdio.h>
#include "t2.h"

int main()
{
    printf("\nEnter the total capacity for the queue: ");
    int capacity, qt, element, choice;
    scanf("%i", &capacity);
    PriorityQueue *queue = createPriorityQueue(capacity);

    do
    {
        printf("\nMenu");
        printf("\nOptions: ");
        printf("\n1: Insert element(s)");
        printf("\n2: Print the queue");
        printf("\n3: Dequeue the element with the highest priority");
        printf("\n0: Exit the program");
        printf("\nEnter your choice: ");
        scanf("%i", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the quantity of elements to insert in the queue: ");
            scanf("%i", &qt);
            for (int i = 0; i < qt; i++)
            {
                printf("\nEnter the element to be inserted: ");
                fflush(stdin);
                scanf("%i", &element);
                insert(queue, element);
            }
            break;

        case 2:
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
            break;

        case 3:
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
            break;

        case 0:
            destroyPriorityQueue(queue);
            return 0;

        default:
            printf("\nInvalid option");
        }
    } while (choice != 0);
    return 0;
}
