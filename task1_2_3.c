#include "monty.h"

/**
 * _rint - print int a top of stack
 * @buff: pointer to linked list stack
 * @l_num: number of line opcode occurs on
 *
 */
void _rint(stack_t **buff, unsigned int l_num)
{
	stack_t *runner;

	runner = *buff;
	if (runner == NULL)
	{
		printf("L%d: can't pint, stack empty\n", l_num);
		handle_exit(buff);
	}
	printf("%d\n", runner->n);
}
/**
 * handle_swap - swap top of stack and second top of stack
 * @buff: pointer to linked list stack
 * @l_num: number of line opcode occurs on
 *
 */
void handle_swap(stack_t **buff, unsigned int l_num)
{
	stack_t *runner;
	int tmp;

	runner = *buff;
	if (runner == NULL || runner->next == NULL)
	{
		printf("L%d: can't swap, stack too short\n", l_num);
		handle_exit(buff);
	}
	tmp = runner->n;
	runner->n = runner->next->n;
	runner->next->n = tmp;
}
/**
 * handle_pop - delete item at top of stack
 * @buff: pointer to linked list stack
 * @l_num: number of line opcode occurs on
 */
void handle_pop(stack_t **buff, unsigned int l_num)
{
	if (*buff == NULL)
	{
		printf("L%d: can't pop an empty stack\n", l_num);
		handle_exit(buff);
	}
	delete_dnodeint(buff, 0);
}
