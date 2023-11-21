#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>

/*Data Structure used for Doubly Linked lists*/

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */

typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/**
 * enum bool - This is an enumeration used to set
 *  values for boolean.
 * @false: represents the value 0.
 * @true: represents the value 1.
 */

typedef enum bool
{
	false = 0,
	true
} bool;

/*Function Prototypes for the project*/
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);

/*Functions used to Print array and list of integers */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);



/*Function used to swap two elements or integers. */
void swap_two_elem(int *x, int *y);

/*Functions used for swapping nodes ahead and behind*/
void Node_Swap_Ahead(listint_t **list, listint_t **last, listint_t **curr);
void Node_Swap_Before(listint_t **list, listint_t **last, listint_t **curr);

/*A function used for sorting sub array of an array*/
void Sort_sub_array(int *sub_arr, int *buffer,
size_t front_idx, size_t mid_idx, size_t back_idx);

/*A function used for merge sorting through recursion*/
void MergeSort_recursion_algo(int *sub_arr, int *buffer,
size_t front_idx, size_t back_idx);

/*A function that changes binary tree to binary heap*/
void bin_tree_to_bin_heap(int *array, size_t size, size_t base_idx, size_t rt);

/*A function that uses the counting sort algorithm */
unsigned int Counting_Sort_Algo(int *array, size_t size, unsigned int elem);

/*A function that calculates the power of 10*/
unsigned int power_of_10(unsigned int pow);

/*Functions used in bitonic sort*/
void Sort_bitonic_seq(int *array, size_t size,
size_t initial, size_t size_seq, char dir);
void arr_to_bitonic_seq(int *array, size_t size, size_t initial,
size_t size_seq, char dir);

/*Functions used in quick sort hoare algo*/
int ord_subset_arr_hoare_parti(int *array, size_t size,
int initial, int final);
void quick_sort_algo_recursion(int *array, size_t size,
int initial, int final);

/*functions used in quick sort algo*/
int ord_sub_arr_lomuto_parti(int *array, size_t size,
int initial, int final);
void lomuto_sort_algo_recursion(int *array, size_t size,
int initial, int final);

#endif
