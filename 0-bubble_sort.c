#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order
 * using the Bubble sort algorithm
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void bubble_sort(int *array, size_t size)
{
	unsigned long int i = 0;
	int temp, flag;

	if (size <= 1)
		return;

	flag = 0;
	while (i < size - 1)
	{
		if (array[i] > array[i + 1])
		{
			temp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = temp;
			print_array(array, size);
			flag = 1;
		}

		i++;
	}

	if (flag == 0)
		return;

	bubble_sort(array, size - 1);
}
