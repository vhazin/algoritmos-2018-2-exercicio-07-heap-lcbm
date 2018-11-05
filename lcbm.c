#include <stdio.h>
#include <stdlib.h>

void HeapSortAlgorithm(int *, int);
void Heapify(int *, int, int);
void swap(int *, int *);

int main(void){
	int array[] = {12, 11, 13, 5, 6, 7};
	int length = sizeof(array) / sizeof(array[0]);
	HeapSortAlgorithm(array, length);

	for (int i = 0; i < length; ++i)
		printf("%d ", array[i]);
}

void HeapSortAlgorithm(int *array, int length){
	for (int i = length / 2 - 1; i >= 0; i--)
		Heapify(array, length, i);

	for (int i = length - 1; i >= 0; i--){
		swap(&array[0], &array[i]);
		Heapify(array, i, 0);
	}
}

void Heapify(int *array, int length, int root){
	int largest = root;  
	int left = 2 * root + 1; 
	int right = 2 * root + 2;

	if (left < length && array[left] > array[largest])
		largest = left;
	if (right < length && array[right] > array[largest])
		largest = right;

	if (largest != root){
		swap(&array[root], &array[largest]);
		Heapify(array, length, largest);
	}
}

void swap(int *min, int *iterator){
    int temp  = *min;                                                                                
    *min      = *iterator;                                     
    *iterator = temp;                                        
}
