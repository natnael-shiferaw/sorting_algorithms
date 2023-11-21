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
 * shell_sort - A function that is used for sorting
 *  (by using the shell sort algorithm) an array
 *  of integers in ascending order.
 * @array: represents an array that consists integers.
 * @size: represents the size of the array.
 *
 * Description: This particular Fucntion sorts using
 * shell sort algorithm and it uses the Knuth
 *  Interval Sequence.
 *
 * Return: Nothing is returned.
 */

void shell_sort(int *array, size_t size)
{
	size_t space, k, h;

	if (array == NULL || size < 2)
		return;

	for (space = 1; space < (size / 3);)
		space = space * 3 + 1;

	for (; space >= 1; space /= 3)
	{

        for (k = space; k < size; k++)
		{
			h = k;

            while (h >= space && array[h - space] > array[h])
			{
				swap_two_elem(array + h, array + (h - space));
				h -= space;
			}
		}
		print_array(array, size);
	}
}
