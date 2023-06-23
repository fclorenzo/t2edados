#include <stdio.h>
#include "t2.h"

int main()
{
	// Insert the element to the
	// priority queue
	insert(45);
	insert(20);
	insert(14);
	insert(12);
	insert(31);
	insert(7);
	insert(11);
	insert(13);
	insert(7);

	int i = 0;

	// Priority queue before extracting max
	printf("Priority Queue : ");
	while (i <= size)
	{
		printf("\n%i", H[i]);
		i++;
	}

	// Node with maximum priority
	printf("Node with maximum priority : ");
	printf("%i", extractMax());

	// Priority queue after extracting max
	printf("Priority queue after extracting maximum : ");
	int j = 0;
	while (j <= size)
	{
		printf("%i", H[j]);
		j++;
	}

	// Change the priority of element
	// present at index 2 to 49
	changePriority(2, 49);
	printf("Priority queue after priority change : ");
	int k = 0;
	while (k <= size)
	{
		printf("\n%i", H[k]);
		k++;
	}

	// Remove element at index 3
	remove_element(3);
	printf("Priority queue after removing the element : ");
	int l = 0;
	while (l <= size)
	{
		printf("\n%i", H[l]);
		l++;
	}
	return 0;
}
