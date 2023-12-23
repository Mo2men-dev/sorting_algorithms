#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending order
 * @array: array to sort
 * @size: size of the array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_rec(array, 0, size - 1, size);
}

/**
 * quick_sort_rec - recursive function for quick sort
 * @array: array to sort
 * @start: start of the array
 * @end: end of the array
 * @size: size of the array
 * Return: void
 */
void quick_sort_rec(int *array, int start, int end, size_t size)
{
	int pivot;

	if (start >= end)
		return;

	pivot = partition(array, start, end, size);
	quick_sort_rec(array, start, pivot - 1, size);
	quick_sort_rec(array, pivot + 1, end, size);
}

/**
 * partition - partitions the array
 * @array: array to partition
 * @start: start of the array
 * @end: end of the array
 * @size: size of the array
 * Return: index of the pivot
 */
int partition(int *array, int start, int end, size_t size)
{
	int pivot = array[end];
	int i = start - 1, j = start, temp;

	while (j <= end - 1)
	{
		if (array[j] < pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			if (i != j)
				print_array(array, size);
		}
		j++;
	}
	i++;

	temp = array[i];
	array[i] = array[end];
	array[end] = temp;
	print_array(array, size);

	return (i);
}
