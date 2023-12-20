#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * getMax - Finds the maximum value in an array.
 * @arr: The array to find the maximum value from.
 * @n: The size of the array.
 * Return: The maximum value in the array.
 */
int getMax(int *arr, int n)
{
	int i, max_value = arr[0];

	for (i = 1; i < n; i++)
		if (arr[i] > max_value)
			max_value = arr[i];
	return (max_value);
}

/**
 * countSort - Performs counting sort on an array based on a specific digit.
 * @arr: The array to be sorted.
 * @n: The size of the array.
 * @exp: The current digit position (10^i).
 * @output: Temporary array to store sorted values.
 */
void countSort(int *arr, size_t n, int exp, int *output)
{
	int i;
	int count[10] = {0};

	for (i = 0; i < (int)n; i++)
		count[(arr[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = n - 1; i >= 0; i--)
	{
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	for (i = 0; i < (int)n; i++)
		arr[i] = output[i];
}

/**
 * radix_sort - Sorts an array using the Radix Sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void radix_sort(int *array, size_t size)
{
	int exp, max_value = 0;
	int *sorted_array = NULL;

	if (array == NULL || size < 2)
		return;

	max_value = getMax(array, size);
	sorted_array = malloc(size * sizeof(int));
	if (sorted_array == NULL)
		return;

	for (exp = 1; max_value / exp > 0; exp *= 10)
	{
		countSort(array, size, exp, sorted_array);
		print_array(array, size);
	}

	free(sorted_array);
}
