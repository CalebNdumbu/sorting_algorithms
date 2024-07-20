#include <stdio.h>
#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending order using Insertion Sort
 * @list: 
 * The doubly linked list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current, *next, *prev;


    if (*list == NULL || (*list)->next == NULL)
        return;

    current = (*list)->next;

    while (current)
    {
        next = current->next;


        prev = *list;
        while (prev && prev->n < current->n)
            prev = prev->next;

        if (prev != current->prev)
        {

            if (current->prev)
                current->prev->next = current->next;
            if (current->next)
                current->next->prev = current->prev;


            if (prev)
            {
                current->next = prev;
                current->prev = prev->prev;
                if (prev->prev)
                    prev->prev->next = current;
                else
                    *list = current;
                prev->prev = current;
            }
            else
            {
                current->next = *list;
                (*list)->prev = current;
                *list = current;
                current->prev = NULL;
            }
        }

        current = next;
    }
}
