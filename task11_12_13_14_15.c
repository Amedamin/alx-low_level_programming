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
 * _rotl - rotates the list left 
 * @stack: pointer to the top of the stack 
 * @line_number: the index of the current line 
 * 
 */ 
void _rotl(stack_t **stack, __attribute__ ((unused))unsigned int line_number) 
{ 
	stack_t *runner; 
	int temp1, temp2; 

	if (*stack == NULL) 
		return; 
	runner = *stack; 
	while (runner->next) 
		runner = runner->next; 
	while (runner) 
	{ 
		if (!runner->next) 
		{ 
			temp1 = runner->n; 
			runner->n = (*stack)->n; 
		} 
		else 
		{ 
			temp2 = runner->n; 
			runner->n = temp1; 
			temp1 = temp2; 
		} 
		runner = runner->prev; 
	} 
} 
/** 
 * _rotr - rotates the list right 
 * @stack: pointer to the top of the stack 
 * @line_number: the index of the current line 
 * 
 */ 
void _rotr(stack_t **stack, __attribute__ ((unused))unsigned int line_number) 
{ 
	stack_t *runner1, *runner2; 
	int temp1, temp2; 

	if (*stack == NULL) 
		return; 

	runner1 = *stack; 
	runner2 = *stack; 
	while (runner1->next) 
		runner1 = runner1->next; 
	while (runner2) 
	{ 
		if (runner2->prev == NULL) 
		{ 
			temp1 = runner2->n; 
			runner2->n = runner1->n; 
		} 
		else 
		{ 
			temp2 = runner2->n; 
			runner2->n = temp1; 
			temp1 = temp2; 
		} 
		runner2 = runner2->next; 

	} 
}
