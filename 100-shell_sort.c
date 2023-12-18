#include "sort.h"
/**
 * shell_sort - sorting func
 * @array:array to sort
 * @size: size of array
 */
void shell_sort(int *array, size_t size)
{
	int gap = 1;
	int i, j, temp;

	if (!array || size < 2)
		return;
	while (gap < (int)size)
	{
		gap = gap * 3 + 1;
	}
	while (gap > 1)
	{
		gap = (gap - 1) / 3;
		for (i = gap; i < (int)size; i++)
		{
			temp = array[i];
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = temp;
		}
		print_array(array, size);
	}
}
