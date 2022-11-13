#include "sort.h"

/**
 * swap_values - swaps values
 * @a: int
 * @b: int
 */
void swap_values(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - Order a subset array as per lomuto scheme
 * @array: The array of ints.
 * @size: Size of array.
 * @left: The starting idx of the subset to order.
 * @right: The ending idx of the subset to order.
 * Return: The final partition idx.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, upper, lower;

	pivot = array + right;
	for (upper = lower = left; lower < right; lower++)
	{
		if (array[lower] < *pivot)
		{
			if (upper < lower)
			{
				swap_values(array + lower, array + upper);
				print_array(array, size);
			}
			upper++;
		}
	}

	if (array[upper] > *pivot)
	{
		swap_values(array + upper, pivot);
		print_array(array, size);
	}

	return (upper);
}

/**
 * lomuto_sort - Implement the quicksort algorithm through recursion.
 * @array: Array of integers to sort.
 * @size: Size of array.
 * @left: Starting index of the array partition
 * @right: Ending index of the array partition
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - Sort array
 * @array: An array of ints.
 * @size: The size ofarray.
 * Description: Uses the Lomuto partition scheme.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}

