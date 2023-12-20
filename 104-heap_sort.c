#include "sort.h"
#include <stdio.h>

/**
 * simple_swap - Swaps two integers.
 * @x: Pointer to the first integer.
 * @y: Pointer to the second integer.
 */
void simple_swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}
/**
 * maxHeapify - Maintains the max-heap property.
 * @array: Array to be sorted.
 * @size: Size of the array.
 * @idx: Index of the current node.
 * @n: Size of the heap to be heapified.
 */
void maxHeapify(int *array, size_t size, int idx, size_t n)
{
	int largest = idx;
	int left = 2 * idx + 1;
	int right = 2 * idx + 2;

	if (left < (int)n && array[left] > array[largest])
		largest = left;

	if (right < (int)n && array[right] > array[largest])
		largest = right;

	if (largest != idx)
	{
		simple_swap(&array[idx], &array[largest]);
		print_array(array, size);
		maxHeapify(array, size, largest, n);
	}
}
/**
 * heap_sort - Sorts an array using the heap sort algorithm.
 * @array: Array to be sorted.
 * @size: Size of the array.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size - 2) / 2; i >= 0; --i)
		maxHeapify(array, size, i, size);

	for (i = (size - 1); i > 0; --i)
	{
		simple_swap(&array[0], &array[i]);
		print_array(array, size);
		maxHeapify(array, size, 0, i);
	}
}
