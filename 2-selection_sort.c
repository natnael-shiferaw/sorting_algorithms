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
 * selection_sort -A function that is used for sorting
 *  (by using selection sort algo) integers in an
 *  array in ascending order.
 * @array: represents the array to be sorted.
 * @size: represents the size of the array.
 *
 * Description: This function uses selection sorting and
 * it's time complexity is Big O of n square , it's
 * noatation is O(n^2).
 * Return: it returns Nothing.
 */

void selection_sort(int *array, size_t size)
{
size_t m, n;
int *Min;

if (array == NULL || size < 2)
	return;

for (m = 0; m < size - 1; m++)
{
Min = array + m;

	for (n = m + 1; n < size; n++)
		Min = (array[n] < *Min) ? (array + n) : Min;

	if ((array + m) != Min)
	{
		swap_two_elem(array + m, Min);
		print_array(array, size);
	}
	}
}
