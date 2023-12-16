#include "sort.h"
/**
 * selection_sort - sort array
 * @array: array
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int min, index, tmp;

	if (size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		min = array[i];
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < min)
			{
				min = array[j];
				index = j;
			}
		}
		if (min < array[i])
		{
			tmp = array[i];
			array[i] = min;
			array[index] = tmp;
			print_array(array, size);
		}
	}
}
