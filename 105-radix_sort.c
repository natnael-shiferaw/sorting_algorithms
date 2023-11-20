#include "sort.h"
#include <stdlib.h>


/**
 * power_of_10 - A function that is used to calculate
 *  the power of 10 of a positive number.
 * @pow: it represents the power of 10 to be
 *  calculated.
 *
 * Return: it returns power of 10 for a given value.
 */

unsigned int power_of_10(unsigned int pow)
{
	unsigned int k, res;

	res = 1;

    for (k = 0; k < pow; k++)
		res *= 10;
	return (res);
}

/**
 * Counting_Sort_Algo - A function used for sorting
 *  (by using the counting sort algo) an array of integers
 *  in ascending order at a particular digit location.
 * @array: represents the array to be sorted.
 * @size: represents the size of the array.
 * @elem: represents the digit/element.
 *
 * Return: 1 - if it needs to keep sorting,
 *         0 - Otherwise.
 */

unsigned int Counting_Sort_Algo(int *array, size_t size, unsigned int elem)
{
	unsigned int pow1, pow2, order = 0;
	int *cpy = NULL;
	size_t k, Tmp, final = 0;
	int h, count[10] = {0};

	pow2 = power_of_10(elem - 1);
	pow1 = pow2 * 10;
	cpy = malloc(sizeof(int) * size);

    if (cpy == NULL)
		exit(1);
	for (k = 0; k < size; k++)
	{
		cpy[k] = array[k];
		if (array[k] / pow1 != 0)
			order = 1;
	}

    for (h = 0; h < 10 ; h++)
		count[h] = 0;
	for (k = 0; k < size; k++)
		count[(array[k] % pow1) / pow2] += 1;
	for (h = 0; h < 10; h++)
	{
		Tmp = count[h];
		count[h] = final;
		final += Tmp;
	}

    for (k = 0; k < size; k++)
	{
		array[count[(cpy[k] % pow1) / pow2]] = cpy[k];
		count[(cpy[k] % pow1) / pow2] += 1;
	}

    free(cpy);
	return (order);
}

/**
 * radix_sort - A function that is used for sorting
 *  (using radix sort algo) an array of integers in
 *  ascending order.
 * @array: represents the array to be sorted.
 * @size: represents the size of the array.
 *
 * Description: This Function works by first iterating
 * - through the first for loop to determine number of
 * - passes required for sorting the array and then iterates
 * -through the second loop to perform the sorting and finally
 * -iterates through the third loop to print the sorted array.
 * 
 * Return: It returns Nothing.
 */

void radix_sort(int *array, size_t size)
{
	unsigned int k, order = 1;

	if (array == NULL || size < 2)
		return;

    for (k = 1; order == 1; k++)
	{
		order = Counting_Sort_Algo(array, size, k);
		print_array(array, size);
	}
}
