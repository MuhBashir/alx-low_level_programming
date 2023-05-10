#include "search_algos.h"

/**
 * binary_search - It searches for a value in an integer array using a binary
 * search algorithm, not guaranteed to return lowest index if `value` appears
 * twice in `array`
 * @array: pointer to first element of array to search in the array
 * @size: number of elements in array
 * @value: search value
 *
 * Return: index containing `value`, or -1 if `value` not found or
 * `array` is NULL
 */

int binary_search(int *array, size_t size, int value)
{
	int low_value, mid_value, high_value;
	int x;

	if (array == NULL)
	{
		return (-1);
	}

	low_value = 0;
	high_value = size - 1;

	while (low_value <= high_value)
	{
		mid_value = (low_value + high_value) / 2;

		printf("Searching in array: ");
		for (x = low_value; x <= high_value; x++)
			printf("%i%s", array[x], x == high_value ? "\n" : ", ");

		if (array[mid_value] < value)
			low_value = mid_value + 1;
		else if (array[mid_value] > value)
			high_value = mid_value - 1;
		else
			return (mid_value);
	}

	return (-1);
}

