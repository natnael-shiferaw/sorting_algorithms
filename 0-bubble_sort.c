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
 * bubble_sort - A function that is used for sorting
 *  integers in an array in ascending order.
 * @array: represents the array to be sorted.
 * @size: represents the size of the array.
 *
 * Description: This function Prints the array after
 *  every swap and it's time complexity is Big O of
 *  n square and it's notation is O(n^2).
 * Return: Nothing.
 */

void bubble_sort(int *array, size_t size)
{
	bool bub = false;
	size_t k, Len = size;

	if (array == NULL || size < 2)
		return;

	while (bub == false)
	{
		bub = true;
		for (k = 0; k < Len - 1; k++)
		{
			if (array[k] > array[k + 1])
			{
				swap_two_elem(array + k, array + k + 1);
				print_array(array, size);
				bub = false;
			}
		}
		Len--;
	}
}
