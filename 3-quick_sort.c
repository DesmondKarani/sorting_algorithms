#include "sort.h"

/**
 * lomuto_partition - Lomuto partition scheme for quicksort
 * @array: The array to sort
 * @low: The starting index
 * @high: The ending index
 * @size_full: The full size of the original array
 *
 * Return: The partition index
 */
int lomuto_partition(int *array, ssize_t low, ssize_t high, size_t size_full)
{
	int pivot = array[high];
	ssize_t i = low - 1, j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap_int(&array[i], &array[j]);
				print_array(array, size_full);
			}
		}
	}
	if (array[high] < array[i + 1])
	{
		swap_int(&array[i + 1], &array[high]);
		print_array(array, size_full);
	}
	return (i + 1);
}

/**
 * quicksort - Implementation of quicksort algorithm
 * @array: The array to sort
 * @low: The starting index
 * @high: The ending index
 * @size: The full size of the array
 */
void quicksort(int *array, ssize_t low, ssize_t high, size_t size)
{
	if (low < high)
	{
		int pi = lomuto_partition(array, low, high, size);

		quicksort(array, low, pi - 1, size);
		quicksort(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using the
 *	quick sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort(array, 0, size - 1, size);
}

/**
 * swap_int - Swap two integers in an array
 * @a: First integer
 * @b: Second integer
 */
void swap_int(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
