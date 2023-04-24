#include "sort.h"

void swap_ints(int *x, int *y);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

/**
 * swap_ints - swaps two integers in an array
 * @x: first integer to swap
 * @y: second integer to swap
 */

void swap_ints(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * hoare_partition - orders a subset of an array of integers according to
 * the hoare partition scheme.
 * @array: array of integers
 * @size: size of array
 * @left: the starting index of the subset to order
 * @right: the ending index of the subset to order
 * Description: uses the last element of the partition as the pivot
 * prints the array after each swap of two elements
 *
 * Return: the final partition index
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot, above, below;

	pivot = array[right];
	for (above = left - 1, below = right + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pivot);
		do {
			below--;
		} while (array[below] > pivot);

		if (above < below)
		{
			swap_ints(array + above, array + below);
			print_array(array, size);
		}
	}

	return (above);
}

/**
 * hoare_sort - implements the Quick sort algorithm through recursion
 * @array: array of integers
 * @size: size of array
 * @left: the starting index of the array partition to order
 * @right: the ending index of the array partition to order
 * Description: implements the Hoare partition scheme
 *
 */

void hoare_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, part - 1);
		hoare_sort(array, size, part, right);
	}
}

/**
 * quick_sort_hoare -sorts an array of integers in ascending order
 * using the Quick sort algorithm.
 * @array: array of integers
 * @size: size of array
 * Description: uses the Hoare partition scheme
 * prints the array after each swap of two elements
 *
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
