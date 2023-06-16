#include "lists.h"
#include <stdlib.h>
#include <stddef.h>
/**
 * insert_dnodeint_at_index - Inserts a new node at a given position in a dlistint_t linked list.
 * @h: Double pointer to the head of the list.
 * @idx: Index of the list where the new node should be added. Index starts at 0.
 * @n: Value to be assigned to the new node.
 *
 * Return: The address of the new node. If it fails to add the new node at the given index, returns NULL.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
    dlistint_t *new_node, *current;
    unsigned int i;

    if (h == NULL)
        return NULL;

    /* Special case: Insert at the beginning */
    if (idx == 0)
        return add_dnodeint(h, n);

    /* Create a new node */
    new_node = malloc(sizeof(dlistint_t));
    if (new_node == NULL)
        return NULL;

    new_node->n = n;

    /* Traverse the list to the node before the desired index */
    current = *h;
    for (i = 0; i < idx - 1 && current != NULL; i++)
        current = current->next;

    /* If the desired index is out of bounds */
    if (current == NULL)
    {
        free(new_node);
        return NULL;
    }

    /* Connect the new node to the list */
    new_node->next = current->next;
    new_node->prev = current;
    if (current->next != NULL)
        current->next->prev = new_node;
    current->next = new_node;

    return new_node;
}
