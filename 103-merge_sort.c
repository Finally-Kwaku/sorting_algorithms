#include "sort.h"

void merge_subarr(int *subarr, int *buff, size_t front, size_t mid,
	size_t back);
void merge_sort_recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * merge_subarr - sorts a subarray of integers
 * @subarr: subarray of an array of integers to sort
 * @buf: buffer to store the sorted subarray
 * @front: front index of the array
 * @mid: middle index of the array
 * @back: back index of the array
 *
 */
void merge_subarr(int *subarr, int *buf, size_t front, size_t mid,
		size_t back)
{
	size_t m, n, o = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	for (m = front, n = mid; m < mid && n < back; o++)
		buf[o] = (subarr[m] < subarr[n]) ? subarr[m++] : subarr[n++];
	for (; m < mid; m++)
		buf[o++] = subarr[m];
	for (; n < back; n++)
		buf[o++] = subarr[n];
	for (m = front, o = 0; m < back; m++)
		subarr[m] = buf[o++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 * merge_sort_recursive - implements the Merge sort algorithm through recursion
 * @subarr: subarray of an array of integers to sort
 * @buf: buffer to store the sorted result
 * @front: front index of the subarray
 * @back: back index of the subarray
 *
 */
void merge_sort_recursive(int *subarr, int *buf,
	size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		merge_sort_recursive(subarr, buf, front, mid);
		merge_sort_recursive(subarr, buf, mid, back);
		merge_subarr(subarr, buf, front, mid, back);
	}
}

/**
 * merge_sort - sorts an array of integers in ascending order
 * using the Merge sort algorithm
 * @array: array of integers
 * @size: size of array
 * Description: implements the top-down merge sort algorithm
 *
 */

void merge_sort(int *array, size_t size)
{
	int *buf;

	if (array == NULL || size < 2)
		return;

	buf = malloc(sizeof(int) * size);
	if (buf == NULL)
		return;

	merge_sort_recursive(array, buf, 0, size);

	free(buf);
}
