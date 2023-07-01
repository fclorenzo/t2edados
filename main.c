#include <stdio.h>
#include "t2.h"

int main()
{
    int qty_of_elements, element, choice, capacity, real_size_queue;

    printf("\nEnter the total capacity for the queue: ");
    do
    {
        scanf("%d", &capacity);
    } while (capacity < 1);

    PriorityQueue *queue = createPriorityQueue(capacity);

    do
    {
        options_to_choose();
        getchar();
        scanf("%i", &choice);

        switch (choice)
        {
        case 1:
            real_size_queue = queue->size + 1;

            if (real_size_queue == queue->capacity)
            {
                printf("\nThe capacity of the heap is full");
                break;
            }

            printf("\nEnter the quantity of elements to insert in the queue: ");
            do
            {
                scanf("%i", &qty_of_elements);
            } while (qty_of_elements + real_size_queue > queue->capacity);

            for (int i = 0; i < qty_of_elements; i++)
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
