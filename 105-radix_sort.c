#include "sort.h"

int get_max(int *array, int size);
void radix_counting_sort(int *array, size_t size, int sig, int *buf);
void radix_sort(int *array, size_t size);

/**
 * get_max - gets the maximum value in an array of integers
 * @array: array of integers
 * @size: size of the array
 *
 * Return: maximum integer in the array
 */

int get_max(int *array, int size)
{
	int max, n;

	for (max = array[0], n = 1; n < size; n++)
	{
		if (array[n] > max)
			max = array[n];
	}
	return (max);
}

/**
 * radix_counting_sort - sorts the significant digits of an array of integers
 * in ascending order using the counting sort algorithm
 * @array: array of integers
 * @size: size of the array
 * @sig: significant digit to sort from
 * @buf: buffer to store the sorted array
 *
 */

void radix_counting_sort(int *array, size_t size, int sig, int *buf)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t n;

	for (n = 0; n < size; n++)
		count[(array[n] / sig) % 10] += 1;

	for (n = 0; n < 10; n++)
		count[n] += count[n - 1];

	for (n = size - 1; (int)n >= 0; n--)
	{
		buf[count[(array[n] / sig) % 10] - 1] = array[n];
		count[(array[n] / sig) % 10] -= 1;
	}
	for (n = 0; n < size; n++)
		array[n] = buf[n];
}

/**
 * radix_sort - sorts an array of integers in ascending order
 * using the Radix sort algorithm
 * @array: array of integers
 * @size: size of array
 * Description: implements the LSD radix sort algorithm.
 * Prints the array after each significant digit is increased.
 *
 */

void radix_sort(int *array, size_t size)
{
	int max, sig, *buf;

	if (array == NULL || size < 2)
		return;

	buf = malloc(sizeof(int) * size);
	if (buf == NULL)
		return;

	max = get_max(array, size);
	for (sig = 1; max / sig > 0; sig *= 10)
	{
		radix_counting_sort(array, size, sig, buf);
		print_array(array, size);
	}
	free(buf);
}
