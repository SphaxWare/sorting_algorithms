#include "sort.h"
/*
 * selection_sort - sort an array
 * @array:array
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int min;

	if (size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		min = array[i];
		for (j = i + 1;j < size; j++)
		{
			if (array[j] < min)
			{
				min = array[j];
				array[j] = array[i];
				array[i] = min;
				print_array(array, size);
			}
		}
	}
}
