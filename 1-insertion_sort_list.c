#include <stdio.h>
#include "sort.h"

void insertion_sort_list(listint_t **list)
{
    listint_t *current, *next, *prev;

    /* Handle empty list or list with only one node */
    if (*list == NULL || (*list)->next == NULL)
        return;

    current = (*list)->next;

    while (current)
    {
        next = current->next;

        /* Find the insertion position for the current node */
        prev = *list;
        while (prev && prev->n < current->n)
            prev = prev->next;

        /* If the current node is not at the beginning, swap it */
        if (prev != current->prev)
        {
            /* Update pointers for the nodes before and after current */
            if (current->prev)
                current->prev->next = current->next;
            if (current->next)
                current->next->prev = current->prev;

            /* Update pointers for the nodes before and after the insertion point */
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
