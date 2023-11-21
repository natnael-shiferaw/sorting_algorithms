#include "sort.h"

/**
 * Sort_sub_array - A function that is used for sorting
 *  a subarray of an array of integers.
 * @sub_arr: represents a subarray of an array.
 * @buffer: represents a buffer that is used to store
 *  the sorted subarray.
 * @front_idx: represents the front index of the array.
 * @mid_idx: represents the intermediate/middle index of the array.
 * @back_idx: represents the back index of the array.
 * Return: It returns Nothing.
 */

void Sort_sub_array(int *sub_arr, int *buffer, size_t front_idx, size_t mid_idx,
		size_t back_idx)
{
	size_t h1, h2, p = 0;

	printf("Merging...\n[left]: ");
	print_array(sub_arr + front_idx, mid_idx - front_idx);

	printf("[right]: ");
	print_array(sub_arr + mid_idx, back_idx - mid_idx);

	for (h1 = front_idx, h2 = mid_idx; h1 < mid_idx && h2 < back_idx; p++)
		buffer[p] = (sub_arr[h1] < sub_arr[h2]) ? sub_arr[h1++] : sub_arr[h2++];
	for (; h1 < mid_idx; h1++)
		buffer[p++] = sub_arr[h1];

    for (; h2 < back_idx; h2++)
		buffer[p++] = sub_arr[h2];
	for (h1 = front_idx, p = 0; h1 < back_idx; h1++)
		sub_arr[h1] = buffer[p++];

	printf("[Done]: ");
	print_array(sub_arr + front_idx, back_idx - front_idx);
}

/**
 * MergeSort_recursion_algo - A function that is used to implement
 *  the merge sort algorithm by the use of recursion.
 * @sub_arr: represents a subarray of an array.
 * @buffer: represents a buffer that is used to store
 *  the sorted subarray.
 * @front_idx: represents the front index of the array.
 * @back_idx: represents the back index of the array.
 * Return: It returns Nothing.
 */

void MergeSort_recursion_algo(int *sub_arr, int *buffer, size_t front_idx, size_t back_idx)
{
	size_t mid_idx;

	if (back_idx - front_idx > 1)
	{

        mid_idx = front_idx + (back_idx - front_idx) / 2;
		MergeSort_recursion_algo(sub_arr, buffer, front_idx, mid_idx);
		MergeSort_recursion_algo(sub_arr, buffer, mid_idx, back_idx);
		Sort_sub_array(sub_arr, buffer, front_idx, mid_idx, back_idx);
	}
}

/**
 * merge_sort - A function that is used for sorting
 * (by using the merge sort algo) an array of integers
 *  in ascending order.
 *
 * @array: represents an array containing integers.
 * @size: represents the size of the array.
 *
 * Return: It returns Nothing.
 */

void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);

    if (buffer == NULL)
		return;

	MergeSort_recursion_algo(array, buffer, 0, size);

	free(buffer);
}
