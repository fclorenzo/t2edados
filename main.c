#include <stdio.h>
#include "t2.h"

int main()
{
    int qt, element, choice, capacity;
    
    printf("\nEnter the total capacity for the queue: ");
    do
    {
        scanf("%d", &capacity);
    } while (capacity < 1);
    
    PriorityQueue *queue = createPriorityQueue(capacity);

    do
    {   
        options();
        getchar();
        scanf("%i", &choice);

        switch (choice)
        {
        case 1:
            if (queue->size == queue->capacity){
                printf("\nThe capacity of the heap is full");
                break;
            }

            printf("\nEnter the quantity of elements to insert in the queue: ");
            do {
                scanf("%i", &qt);
            } while (qt + queue->size > queue->capacity);

            for (int i = 0; i < qt; i++)
            {
                printf("\nEnter the element to be inserted: ");
                fflush(stdin);
                scanf("%i", &element);
                insert(queue, element);
            }
            printf("\nPriority Queue: ");
            print_queue(queue);
            break;

        case 2:
            printf("\nPriority Queue: ");
            print_queue(queue);
            break;

        case 3:
            extractMax(queue);
            printf("\nPriority Queue after removing the highest priority element: ");
            print_queue(queue);
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
