#include "monty.h"
/**
 * f_add - adds the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void f_add(stack_t **head, unsigned int counter)
{
	stack_t *hs;
	int len = 0, aux;

	hs = *head;
	while (hs)
	{
		hs = hs->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	hs = *head;
	aux = hs->n + hs->next->n;
	hs->next->n = aux;
	*head = hs->next;
	free(hs);
}
