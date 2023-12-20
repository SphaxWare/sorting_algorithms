#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * _calloc - Allocates memory for an array using malloc and initializes
 *           the memory to zero.
 * @nmemb: Number of elements.
 * @size: Size of each element.
 * Return: Pointer to the allocated memory, or NULL if allocation fails.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i;
	char *p;

	if (nmemb == 0 || size == 0)
		return (NULL);

	p = malloc(nmemb * size);

	if (p == NULL)
		return (NULL);

	for (i = 0; i < (nmemb * size); i++)
		p[i] = 0;

	return (p);
}

/**
 * counting_sort - Sorts an array of integers in ascending order using
 *                 the Counting sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
	int index, maximum = 0, *counter = NULL, *tmp = NULL;
	size_t i;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; i++)
		if (array[i] > maximum)
			maximum = array[i];

	counter = _calloc(maximum + 1, sizeof(int));
	tmp = _calloc(size + 1, sizeof(int));

	for (i = 0; i < size; i++)
		counter[array[i]]++;

	for (index = 1; index <= maximum; index++)
		counter[index] += counter[index - 1];

	print_array(counter, maximum + 1);

	for (i = 0; i < size; ++i)
	{
		tmp[counter[array[i]] - 1] = array[i];
		counter[array[i]]--;
	}

	for (i = 0; i < size; i++)
		array[i] = tmp[i];

	free(tmp);
	free(counter);
}
