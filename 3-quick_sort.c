#include "sort.h"
/**
 * quick_sort - sort array
 * @array:array
 * @size:size
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quicksort_recursive(array, 0, size - 1, size);
}
/**
 * swap - swaps two integers
 * @x: first integer
 * @y: second integer
 */
void swap(int *x, int *y, int *array, size_t size)
{
	int temp;

	if (*x != *y)
	{
		temp = *x;
		*x = *y;
		*y = temp;
		print_array(array, size);
	}
}
/**
 * partition - partitions the array and returns the pivot index
 * @array: array to be partitioned
 * @low: starting index
 * @high: ending index
 * @size: size of the array
 * Return: pivot index
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high], j, i = low;

	for (j = low; j < high; j++)
	{
		if (array[j] <  pivot)
		{
			swap(&array[i], &array[j], array, size);
			i++;
		}
	}
	swap(&array[i], &array[high], array, size);
	return (i);
}

/**
 * quicksort_recursive - recursive function to implement quicksort
 * @array: array to be sorted
 * @low: starting index
 * @high: ending index
 * @size: size of the array
 */
void quicksort_recursive(int *array, int low, int high, size_t size)
{
	int pi;

	if (low < high)
	{
		pi = partition(array, low, high, size);
		quicksort_recursive(array, low, pi - 1, size);
		quicksort_recursive(array, pi + 1, high, size);
	}
}
