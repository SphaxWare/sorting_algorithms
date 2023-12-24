#include "sort.h"
/**
 * quick_sort_hoare - Sort an array
 * @array: An array.
 * @size: The size.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
/**
 * hoare_partition - Order a subset of an array of integers.
 * @array: The array.
 * @size: The size.
 * @left: The start.
 * @right: The ending index.
 * Return:final partition index.
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot, above, below;

	pivot = array[right];
	for (above = left - 1, below = right + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pivot);
		do {
			below--;
		} while (array[below] > pivot);

		if (above < below)
		{
			simple_swap(array + above, array + below);
			print_array(array, size);
		}
	}

	return (above);
}
/**
 * hoare_sort - Implement the quicksort.
 * @array: An array.
 * @size: The size.
 * @left: The start.
 * @right: The ending index.
 *
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, part - 1);
		hoare_sort(array, size, part, right);
	}
}
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
