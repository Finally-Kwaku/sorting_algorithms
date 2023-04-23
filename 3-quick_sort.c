#include "sort.h"

/**
 *change_position - function that changes the position of the numbers
 *@array: array of integers
 *@n1: first number
 *@n2: second number
 *@size: size of array
 */

void change_position(int *array, int *n1, int *n2, size_t size)
{
	int exchange_position = *n1;

	*n1 = *n2;
	*n2 = exchange_position;
	print_array(array, size);
}

/**
 *partition - is the partition function for the array
 *@array: array of integers
 *@low: low
 *@high: high
 *@size: size of array
 *Return: number of changes made
 *
 */

int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int Index = low;
	int i = 0;

	for (i = low; i < high; i++)
	{
		if (array[i] <= pivot)
		{
			if (Index != i)
				change_position(array, &array[i], &array[Index], size);
			Index++;
		}
	}
	if (Index != high)
		change_position(array, &array[high], &array[Index], size);
	return (Index);
}

/**
 *quickSort - function to quicksort
 *@array: array of integers
 *@low: low
 *@high: high
 *@size: size of array
 */

void quickSort(int *array, int low, int high, size_t size)
{
	int changes = 0;

	if (low < high)
	{
		changes = partition(array, low, high, size);
		quickSort(array, low, changes - 1, size);
		quickSort(array, changes + 1, high, size);
	}
}

/**
 *quick_sort - sorts sorts an array of integers in ascending order
 using the quick sort algorithm
 *@array: array of integers
 *@size: size of array
 *
 */

void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quickSort(array, 0, size - 1, size);
}
