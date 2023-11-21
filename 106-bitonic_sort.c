#include "sort.h"

#define UP 0
#define DOWN 1

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
 * Sort_bitonic_seq - A function used for sorting
 *  a bitonic sequence in an array of integers.
 * @array: represents an array.
 * @size: reprsents the size of the array.
 * @initial: represents the starting index of the
 *  sequence in the array.
 * @size_seq: represents the size of the sequence.
 * @dir: represents the direction to sort in.
 * Return: It returns Nothing.
 */

void Sort_bitonic_seq(int *array, size_t size, size_t initial, size_t size_seq,
		char dir)
{
	size_t j, half = size_seq / 2;

	if (size_seq > 1)
	{

        for (j = initial; j < initial + half; j++)
		{
			if ((dir == UP && array[j] > array[j + half]) ||
			    (dir == DOWN && array[j] < array[j + half]))
				swap_two_elem(array + j, array + j + half);
		}

        Sort_bitonic_seq(array, size, initial, half, dir);
		Sort_bitonic_seq(array, size, initial + half, half, dir);
	}
}

/**
 * arr_to_bitonic_seq - A function that is used to convert
 *  an array into a bitonic sequence.
 * @array: represents an array.
 * @size: reprsents the size of the array.
 * @initial: represents the starting index of the
 *  sequence in the array.
 * @size_seq: represents the size of the sequence.
 * @dir: represents the direction to sort in.
 * Return: It returns Nothing.
 */

void arr_to_bitonic_seq(int *array, size_t size, size_t initial, size_t size_seq, char dir)
{
	char *str = (dir == UP) ? "UP" : "DOWN";
	size_t half = size_seq / 2;

	if (size_seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", size_seq, size, str);
		print_array(array + initial, size_seq);

		arr_to_bitonic_seq(array, size, initial, half, UP);
		arr_to_bitonic_seq(array, size, initial + half, half, DOWN);
		Sort_bitonic_seq(array, size, initial, size_seq, dir);

		printf("Result [%lu/%lu] (%s):\n", size_seq, size, str);
		print_array(array + initial, size_seq);
	}
}

/**
 * bitonic_sort - A function that is used to sort
 *  (by using the bitonic sort algo) an array of
 *  integers in ascending order.
 * @array: represents an array.
 * @size: reprsents the size of the array.
 * Return: It returns Nothing.
 */

void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	arr_to_bitonic_seq(array, size, 0, size, UP);
}
