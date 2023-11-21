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
 * bin_tree_to_bin_heap - A function that is used for turning
 *  a binary tree into a binary heap completely.
 * @array: represents an array containing integers
 *  that represents a binary tree.
 * @size: represents the size of the array.
 * @base_idx: represents the base row's index of the tree.
 * @rt: represents the root node of the binary tree.
 * Return: It returns Nothing.
 */

void bin_tree_to_bin_heap(int *array, size_t size, size_t base_idx, size_t rt)
{
	size_t west, east, root;

	root = rt;
	west = 2 * rt + 1;
	east = 2 * rt + 2;

	if (west < base_idx && array[west] > array[root])
		root = west;

    if (east < base_idx && array[east] > array[root])
		root = east;

	if (root != rt)
	{
		swap_two_elem(array + rt, array + root);
		print_array(array, size);
		bin_tree_to_bin_heap(array, size, base_idx, root);
	}
}

/**
 * heap_sort - A function that is used for sorting
 * (by using the heap sort algo) an array of integers
 *  in ascending order.
 * @array: represents an array containing integers.
 * @size: represents the size of the array.
 *
 * Return: It returns Nothing.
 */

void heap_sort(int *array, size_t size)
{
	int k;

	if (array == NULL || size < 2)
		return;

	for (k = (size / 2) - 1; k >= 0; k--)
		bin_tree_to_bin_heap(array, size, size, k);


    for (k = size - 1; k > 0; k--)
	{
		swap_two_elem(array, array + k);
		print_array(array, size);
		bin_tree_to_bin_heap(array, size, k, 0);
	}
}
