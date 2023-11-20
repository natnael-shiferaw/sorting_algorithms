#include "sort.h"

/**
* swap_two_elem - A Function that is used for
*  swapping two elements.
* @x: represents the first element to be swapped.
* @y: represents the second element to be swapped.
*/

void swap_two_elem(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * ord_subset_arr_hoare_parti - A function used to order
 *  (according to hoare partition)a subset of an array
 *  of integers.
 * @array: represents an array.
 * @size: reprsents the size of the array.
 * @initial: represents the starting index of the subset.
 * @final: represents the ending index of the subset.
 *
 * Return: returns the final partition index.
 */

int ord_subset_arr_hoare_parti(int *array, size_t size, int initial, int final)
{
	int pivot, up, down;

	pivot = array[final];

    for (up = initial - 1, down = final + 1; up < down;)
	{
		do {
			up++;
		} while (array[up] < pivot);

        do {
			down--;
		} while (array[down] > pivot);

		if (up < down)
		{
			swap_two_elem(array + up, array + down);
			print_array(array, size);
		}
	}

	return (up);
}

/**
 * quick_sort_algo_recursion - A function that implements
 *  the quicksort algorithm by the use of recursion.
 * @array: represents an array.
 * @size: reprsents the size of the array.
 * @initial: represents the starting index of the subset.
 * @final: represents the ending index of the subset.
 * Return: It returns Nothing.
 */

void quick_sort_algo_recursion(int *array, size_t size, int initial, int final)
{
	int sub;

	if (final - initial > 0)
	{
		sub = ord_subset_arr_hoare_parti(array, size, initial, final);
		quick_sort_algo_recursion(array, size, initial, sub - 1);
		quick_sort_algo_recursion(array, size, sub, final);
	}
}

/**
 * quick_sort_hoare -A function that is used to sort
 *  (by using the quick sort algo) an array of
 *  integers in ascending order.
 * @array: represents an array.
 * @size: reprsents the size of the array.
 *
 * Return: It returns Nothing.
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_algo_recursion(array, size, 0, size - 1);
}
