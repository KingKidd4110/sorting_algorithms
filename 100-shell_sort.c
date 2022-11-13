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
 * shell_sort - shell sort
 * @array: array
 * @size: array size
 */
void shell_sort(int *array, size_t size)
{
	size_t spc, i, j;

	if (array == NULL || size < 2)
		return;

	for (spc = 1; spc < (size / 3);)
		spc = spc * 3 + 1;

	for (; spc >= 1; spc /= 3)
	{
		for (i = spc; i < size; i++)
		{
			j = i;
			while (j >= spc && array[j - spc] > array[j])
			{
				swap_values(array + j, array + (j - spc));
				j -= spc;
			}
		}
		print_array(array, size);
	}
}
