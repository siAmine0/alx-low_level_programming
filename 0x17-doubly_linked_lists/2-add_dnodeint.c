#include <stdlib.h>
#include "lists.h"

dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
    dlistint_t *new_node;

    /* Create a new node */
    new_node = malloc(sizeof(dlistint_t));
    if (new_node == NULL)
        return NULL;

    /* Set the data for the new node */
    new_node->n = n;
    new_node->prev = NULL;
    new_node->next = *head;

    /* Update the previous pointer of the old head if it exists */
    if (*head != NULL)
        (*head)->prev = new_node;

    /* Update the head to point to the new node */
    *head = new_node;

    return new_node;
}
