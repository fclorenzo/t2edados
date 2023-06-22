#include <stdio.h>

int H[50];
int size = -1;

int parent(int i);
int leftChild(int i);
int rightChild(int i);
void shiftUp(int i);
void shiftDown(int i);
void insert(int p);
int extractMax();
void changePriority(int i, int p);
int getMax();
void remove_element(int i);
void swap(int *a, int *b);
