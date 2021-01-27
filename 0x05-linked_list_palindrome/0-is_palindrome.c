#include "lists.h"

/**
 * is_palindrome - Check if a linked list is a palindrome
 * @head: Head of the linked list
 * Return: If is  a linked list returns 1 otherwise 0
 */
int is_palindrome(listint_t **head)
{
	if (!head || !*head)
		return (1);

	return (!recursion(*head, *head) ? 0 : 1);
}

/**
 * recursion - Check if a linked list is a palindrome
 * @head: Head of the linked list
 * @tail: tail of the linked list
 * Return: If head and tail are equal return the next head
 * otherwise NULL
 */
listint_t *recursion(listint_t *head, listint_t *tail)
{
	listint_t *node = NULL;

	if (!tail)
		return (head);

	node = recursion(head, tail->next);
	if (!node)
		return (NULL);

	if (node->n == tail->n)
	{
		if (!node->next)
			return (head);
		else
			return (node->next);
	}

	return (NULL);
}
