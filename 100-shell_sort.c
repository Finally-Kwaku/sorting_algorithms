#include "sort.h"

/**
 * swap_ints - swaps two integers in an array of integers
 * @n1: The first integer to swap.
 * @n2: The second integer to swap.
 *
 */

void swap_ints(int *n1, int *n2)
{
	int tmp;

	tmp = *n1;
	*n1 = *n2;
	*n2 = tmp;
}

/**
 * shell_sort - sorts an array of integers in ascending order
 * using the Shell sort algorithm
 * @array: array of integers
 * @size: size of array
 * Description: Uses the Knuth sequence.
 *
 */

void shell_sort(int *array, size_t size)
{
	size_t gap, m, n;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (m = gap; m < size; m++)
		{
			n = m;
			while (n >= gap && array[n - gap] > array[n])
			{
				swap_ints(array + n, array + (n - gap));
				n -= gap;
			}
		}
		print_array(array, size);
	}
}
