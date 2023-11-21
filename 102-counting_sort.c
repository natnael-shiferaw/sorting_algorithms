#include "sort.h"

int Get_Max(int *array, int size);

/**
 * Get_Max - A function that is used for getting
 *  the maximum value of a given array of integers.
 * @array: represents the array containing integers.
 * @size: represents the size of the array.
 *
 * Return: returns the Max value.
 */

int Get_Max(int *array, int size)
{
	int Max, k;

	for (Max = array[0], k = 1; k < size; k++)
	{
		if (array[k] > Max)
			Max = array[k];
	}

	return (Max);
}

/**
 * counting_sort - A function that is used for sorting
 *  an array of integers(by using the counting sort algo)
 *  in ascending order.
 * @array: represents an array containing integers.
 * @size: represents the size of the array.
 *
 * Return: It returns Nothing.
 */

void counting_sort(int *array, size_t size)
{
	int *c, *ordered, Max, j;

	if (array == NULL || size < 2)
		return;

	ordered = malloc(sizeof(int) * size);

    if (ordered == NULL)
		return;

    Max = Get_Max(array, size);
	c = malloc(sizeof(int) * (Max + 1));

    if (c == NULL)
	{
		free(ordered);
		return;
	}

	for (j = 0; j < (Max + 1); j++)
		c[j] = 0;

    for (j = 0; j < (int)size; j++)
		c[array[j]] += 1;
	for (j = 0; j < (Max + 1); j++)
		c[j] += c[j - 1];
	print_array(c, Max + 1);

	for (j = 0; j < (int)size; j++)
	{
		ordered[c[array[j]] - 1] = array[j];
		c[array[j]] -= 1;
	}

	for (j = 0; j < (int)size; j++)
		array[j] = ordered[j];

	free(ordered);
	free(c);
}
