#include "sort.h"

/**
 * radix_counting_sort - Implement counting sort  for main digit setting for radix
 * @array: An array of ints.
 * @size: Array size
 * @sig: Main/significant int to sort on
 * @buff: A buffer store for sorted arr
 */
void counting_sort_rad(int *array, size_t size, int sig, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / sig) % 10] += 1;

	for (i = 0; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		buff[count[(array[i] / sig) % 10] - 1] = array[i];
		count[(array[i] / sig) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = buff[i];
}

/**
 * radix_sort - Implements radix sort algo
 * @array: An array of ints
 * @size: Array size
 */
void radix_sort(int *array, size_t size)
{
	int max, sig, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	max = max_g(array, size);
	for (sig = 1; max / sig > 0; sig *= 10)
	{
		counting_sort_rad(array, size, sig, buff);
		print_array(array, size);
	}

	free(buff);
}
