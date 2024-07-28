#include <stdio.h>
#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 *                  using the Selection sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */

void selection_sort(int *array, size_t size)
{
    size_t i, j, min_idx;
    int temp; //temp is used for swapping elements
 
    //loop through the entire array except the last element
    for (i = 0; i < size - 1; i++)
    {
        //assume the current element is the minimum
        min_idx = i;

        //find min element in unsorted part of array
        for(j = i + 1; j < size; j++)
        {
            if (array[j] < array[min_idx]) //if a smaller element is found
                min_idx = j;//update idx of min element
        }

        //if the min element is not the current element, swap them

        if (min_idx != 1)
        {
            temp = array[min_idx];
            array[min_idx] = array[i];
            array[i] = temp;

            print_array(array, size);
        }
    }

}