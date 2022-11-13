#include "sort.h"

/**
 * swap_values - swaps values
 * @a: int
 * @b: int
 */
void swap_values(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bubble_sort - bubble sort function
 * @array: array to be sorted
 * @size: int size of the array
 * Description: sorts data
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	bool bubbles = false;

	if (array == NULL || size < 2)
		return;

	while (bubbles == false)
	{
		bubbles = true;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_values(array + i, array + i + 1);
				print_array(array, size);
				bubbles = false;
			}
		}
		len--;
	}
}
