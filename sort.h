#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

#define UP 1
#define DOWN 0

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void swaper(listint_t *previous, listint_t *current);
void swap(int *x, int *y, int *array, size_t size);
int partition(int *array, int low, int high, size_t size);
void quicksort_recursive(int *array, int low, int high, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
listint_t *node_swaper(listint_t *node, listint_t **list);
void counting_sort(int *array, size_t size);
void *_calloc(unsigned int nmemb, unsigned int size);
void merge_sort(int *array, size_t size);
void top_down(int *array, size_t start, size_t stop, int *n);
void compare(int *array, size_t start, size_t stop, int *n);
void simple_swap(int *x, int *y);
void maxHeapify(int *array, size_t size, int idx, size_t n);
void heap_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
int getMax(int *arr, int n);
void countSort(int *arr, size_t n, int exp, int *output);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow);
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);
#endif
