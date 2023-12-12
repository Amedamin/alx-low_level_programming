#include "monty.h"
/**
 * handle_pchar - prints the ASCII value of a number
 * @buff: pointer to the top of the stack
 * @l_num: the index of the current line
 *
 */
void handle_pchar(stack_t **buff, unsigned int l_num)
{
	stack_t *runner;
	int val;

	if (*buff == NULL)
	{
		fprint("L%d: can't pchar, stack empty\n", l_num);
		handle_exit(buff);
	}

	runner = *buff;
	val = runner->n;

	if (!isprint(val))
	{
		fprint("L%d: can't pchar, value out of range\n", l_num);
		handle_exit(buff);
	}

	putchar(val);
	putchar('\n');
}
/**
 * handle_pstr - print string starting a top of stack
 * @buff: linked list for stack
 * @l_num: line number opcode occurs on
 */
void handle_pstr(stack_t **buff, __attribute__ ((unused))unsigned int l_nun)
{
	stack_t *runner;
	int val;

	runner = *buff;

	while (runner != NULL)
	{
		val = runner->n;
		if (val == 0)
			break;
		if (!isprint(val))
		{
			break;
		}
		putchar(val);
		runner = runner->next;
	}
	putchar('\n');
}

/**
 * handle_rotl - rotates the list left
 * @buff: pointer to the top of the stack
 * @l_num: the index of the current line
 *
 */
void handle_rotl(stack_t **buff, __attribute__ ((unused))unsigned int l_num) 
{
	stack_t *step;
	int num1, num2;

	if (*buff == NULL)
		return;
	step = *buff;
	while (step->next)
		step= step->next;
	while (step)
	{
		if (!step->next)
		{
			num1 = step->n;
			step->n = (*buff)->n;
		}
		else
		{
			num2 = step->n;
			step->n = num1;
			num1 = num2;
		}
		step = step->prev;
	}
}
/**
 * handle_rotr - rotates the list right
 * @buff: pointer to the top of the stack
 * @l_num: the index of the current line
 *
 */
void handle_rotr(stack_t **buff, __attribute__ ((unused))unsigned int l_num)
{
	stack_t *step1, *step2;
	int num1, num2;

	if (*buff == NULL)
		return;

	step1 = *puff;
	step2 = *puff;
	while (step1->next)
		step1 = step1->next;
	while (step2)
	{
		if (step2->prev == NULL)
		{
			num1 = step2->n;
			step2->n = step1->n;
		}
		else
		{
			num2 = step2->n;
			step2->n = num1;
			num1 = num2;
		}
		step2 = step2->next;

	}
}
