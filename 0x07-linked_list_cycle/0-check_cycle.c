#include "lists.h"

/**
 * check_cycle - check if there is a cycle in a linked list
 * @list: pointer to list to chekc
 * Return: 1 if found a cycle, 0 otherwise
 */
int check_cycle(listint_t *list)
{
	listint_t *current = list, *nextOne = list;

	if (!list)
		return (0);

	while (current && nextOne && nextOne->next)
	{
		current = current->next;
		nextOne = nextOne->next->next;
		if (current == nextOne)
			return (1);
	}

	return (0);
}
