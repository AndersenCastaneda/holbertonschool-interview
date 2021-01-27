#include "lists.h"

/**
 * insert_node - Inserts a number in a listint_t linked list
 * @head: Linked list
 * @number: Value to insert
 * Return: Address of node inserted or NULL if can't insert the node
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *node = *head, *temp = NULL, *new_node = NULL;

	if (!head || !node)
		return (add_nodeint_end(head, number));

	new_node = malloc(sizeof(listint_t));
	if (!new_node)
		return (NULL);

	new_node->n = number;
	while (node)
	{
		if (node->n > number)
			break;

		temp = node;
		node = node->next;
	}

	new_node->next = node;
	if (!temp)
		*head = new_node;
	else
		temp->next = new_node;

	return (new_node);
}
