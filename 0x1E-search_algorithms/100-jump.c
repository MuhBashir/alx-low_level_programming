#include "search_algos.h"
#include <math.h>

/* remember compiling math.h with gcc requires `-lm` */

size_t min(size_t a, size_t b);

/**
 * min - returns the minimum of two size_t values
 * @a: first value
 * @b: second value
 *
 * Return: `a` if lower or equal to `b`, `b` otherwise
 */
size_t min(size_t a, size_t b)
{
	return (a <= b ? a : b);
}

/**
 * jump_search - searches for a value in a sorted array of integers using
 * jump search algorithm
 * @array: pointer to first element of array to search for
 * @size: number of elements in array
 * @value: search value
 *
 * Return: first index containing `value`, or -1 if `value` not found or
 * `array` is NULL
 */

int jump_search(int *array, size_t size, int value)
{
	size_t low_value, high_value, jump_value;

	if (!array || size == 0)
		return (-1);

	jump_value = sqrt(size);

	for (high_value = 0; high_value < size && array[high_value] < value;
	     low_value = high_value, high_value += jump_value)
	{
		printf("Value checked array[%lu] = [%d]\n",
		       high_value, array[high_value]);
	}

	
	printf("Value found between indexes [%lu] and [%lu]\n", low_value, high_value);

	for (; low_value <= min(high_value, size - 1); low_value++)
	{
		printf("Value checked array[%lu] = [%d]\n", low_value, array[low_value]);
		if (array[low_value] == value)
			return (low_value);
	}

	return (-1);
}

