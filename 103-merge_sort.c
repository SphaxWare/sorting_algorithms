#include "sort.h"
/**
 * merge_sort - sort
 * @array:array
 * @size:size
 */
void merge_sort(int *array, size_t size)
{
	int *n;
	size_t i;

	if (!array || size < 2)
		return;

	n = malloc(sizeof(int) * size);
	if (!n)
		return;
	for (i = 0; i < size; i++)
		n[i] = array[i];
	top_down(n, 0, size, array);
	free(n);
}
/**
 * top_down - helper func
 * @array:array
 * @start:first index
 * @stop:stop index
 * @n: output
 */
void top_down(int *array, size_t start, size_t stop, int *n)
{
	size_t mid;

	mid = (start + stop) / 2;
	if (stop - start < 2)
		return;
	top_down(n, start, mid, array);
	top_down(n, mid, stop, array);
	compare(array, start, stop, n);
}
/**
 * compare - helper function
 * @array:array to sort
 * @start:start index
 * @stop:stop index
 * @n: output
 */
void compare(int *array, size_t start, size_t stop, int *n)
{
	size_t i, j, k, mid;

	i = start;
	j = mid = (start + stop) / 2;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + start, mid - start);
	printf("[right]: ");
	print_array(array + mid, stop - mid);
	for (k = start; k < stop; k++)
	{
		if (i < mid && (j >= stop || array[i] <= array[j]))
		{
			n[k] = array[i++];
		}
		else
		{
			n[k] = array[j++];
		}
	}
	printf("[Done]: ");
	print_array(n + start, stop - start);
}
