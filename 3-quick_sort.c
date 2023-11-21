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
 * ord_sub_arr_lomuto_parti - A function used to order
 *  (according to lomuto partition)a subset of an array
 *  of integers.
 * @array: represents an array.
 * @size: reprsents the size of the array.
 * @initial: represents the starting index of the subset.
 * @final: represents the ending index of the subset.
 *
 * Return: returns the final partition index.
 */

int ord_sub_arr_lomuto_parti(int *array, size_t size, int initial, int final)
{
int *pivot, up, down;

pivot = array + final;

for (up = down = initial; down < final; down++)
{

	if (array[down] < *pivot)
	{
		if (up < down)
		{
			swap_two_elem(array + down, array + up);
			print_array(array, size);
		}
		up++;
	}
}

if (array[up] > *pivot)
{
	swap_two_elem(array + up, pivot);
	print_array(array, size);
}

return (up);
}

/**
 * lomuto_sort_algo_recursion - A function that implements
 *  the quicksort algorithm by the use of recursion
 * and uses lomuto partition scheme.
 * @array: represents an array.
 * @size: reprsents the size of the array.
 * @initial: represents the starting index of the subset.
 * @final: represents the ending index of the subset.
 * Return: It returns Nothing.
 */

void lomuto_sort_algo_recursion(int *array, size_t size,
int initial, int final)
{
int sub;

if (final - initial > 0)
{

sub = ord_sub_arr_lomuto_parti(array, size, initial, final);
lomuto_sort_algo_recursion(array, size, initial, sub - 1);
lomuto_sort_algo_recursion(array, size, sub + 1, final);
}
}

/**
 * quick_sort - A function that is used to sort
 *  (by using the quick sort algo) an array of
 *  integers in ascending order.
 * @array: represents an array.
 * @size: reprsents the size of the array.
 *
 * Return: It returns Nothing.
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort_algo_recursion(array, size, 0, size - 1);
}
