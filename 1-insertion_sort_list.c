#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending order using Insertion Sort
 * @list: The doubly linked list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current, *temp, *swap;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    current = (*list)->next;
    while (current != NULL)
    {
        temp = current;
        while (temp->prev != NULL && temp->n < temp->prev->n)
        {
            swap = temp->prev;
            // Swap the nodes
            if (swap->prev != NULL)
                swap->prev->next = temp;
            if (temp->next != NULL)
                temp->next->prev = swap;
            
            swap->next = temp->next;
            temp->prev = swap->prev;
            swap->prev = temp;
            temp->next = swap;

            // Update the head of the list if necessary
            if (temp->prev == NULL)
                *list = temp;

            print_list(*list);
        }
        current = current->next;
    }
}
