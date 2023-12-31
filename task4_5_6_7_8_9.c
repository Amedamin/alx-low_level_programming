#include "monty.h"
/**
 * handle_add - adds top of stack and second top of stack
 *
 * @buff: pointer to linked list stack
 * @l_num: number of line opcode occurs on
 */
void handle_add(stack_t **buff, unsigned int l_num)
{
	if (*buff == NULL || (*buff)->next == NULL)
	{
		fprint("L%d: can't add, stack too short\n", l_num);
		handle_exit(buff);
	}
	(*buff)->next->n += (*buff)->n;
	_pop(buff, l_num);
}

/**
 * handle_nop - literally does nothing
 * @buff: pointer to the top of the stack
 * @l_num: the index of the current line
 *
 */
void handle_nop(__attribute__ ((unused))stack_t **buff,
		__attribute__ ((unused))unsigned int l_num)
{
	;
}
/**
 * handle_sub - subtracts top of stack and second top of stack
 *
 * @buff: pointer to linked list stack
 * @l_num: number of line opcode occurs on
 */
void handle_sub(stack_t **buff, unsigned int l_num)
{
	if (*buff == NULL || (*buff)->next == NULL)
	{
		fprint("L%d: can't sub, stack too short\n", l_num);
		handle_exit(buff);
	}
	(*buff)->next->n -= (*buff)->n;
	_pop(buff, l_num);
}

/**
 * handle_mul - multiply top of stack and second top of stack
 * @buff: pointer to linked list stack
 * @l_num: number of line opcode occurs on
 *
 */
void handle_mul(stack_t **buff, unsigned int l_num)
{
	if (*buff == NULL || (*buff)->next == NULL)
	{
		fprint("L%d: can't mul, stack too short\n", l_num);
		handle_exit(buff);
	}
	(*buff)->next->n *= (*buff)->n;
	_pop(buff, l_num);
}

/**
 * handle_div - divide top of stack and second top of stack
 * @buff: pointer to linked list stack
 * @l_num: number of line opcode occurs on
 */
void handle_div(stack_t **buff, unsigned int l_num)
{
	if (*buff == NULL || (*buff)->next == NULL)
	{
		fprint("L%d: can't div, stack too short\n", l_num);
		handle_exit(buff);
	}
	if ((*buff)->n == 0)
	{
		fprint("L%d: division by zero\n", l_num);
		handle_exit(buff);
	}
	(*buff)->next->n /= (*buff)->n;
	_pop(buff, l_num);
}

/**
 * handle_mod - mod top of stack and second top of stack
 * @buff: pointer to linked list stack
 * @l_num: number of line opcode occurs on
 *
 */
void handle_mod(stack_t **buff, unsigned int l_num)
{
	if (*buff == NULL || (*buff)->next == NULL)
	{
		fprint("L%d: can't mod, stack too short\n", l_num);
		handle_exit(buff);
	}
	if ((*buff)->n == 0)
	{
		fprint("L%d: division by zero\n", l_num);
		handle_exit(buff);
	}
	(*buff)->next->n %= (*buff)->n;
	_pop(buff, l_num);
}
