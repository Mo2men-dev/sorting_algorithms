#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	unsigned long int i = 0, j, curr_min_i;
	int curr_min = 0, temp;

	while (i < size)
	{
		j = i + 1;
		curr_min = array[i];
		curr_min_i = i;
		while (j < size)
		{
			if (curr_min > array[j])
			{
				curr_min = array[j];
				curr_min_i = j;
			}
			j++;
		}
		if (curr_min_i != i)
		{
			temp = array[curr_min_i];
			array[curr_min_i] = array[i];
			array[i] = temp;
			print_array(array, size);
		}
		i++;
	}
}
