/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manipulations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 18:49:47 by dkhlopov          #+#    #+#             */
/*   Updated: 2017/04/21 16:25:32 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		push_instruction(t_inst **list, char *str)
{
	t_inst *new;
	t_inst *iter;

	new = (t_inst *)malloc(sizeof(t_inst));
	new->inst = str;
	new->next = NULL;
	if (!*list)
	{
		*list = new;
		new->prev = NULL;
		return ;
	}
	else
	{
		iter = *list;
		while (iter->next)
			iter = iter->next;
		iter->next = new;
		new->prev = iter;
	}
}

void		swap(t_stack *stack, t_inst **list, char *str)
{
	int		tmp;

	if (!stack || !stack->next)
		return ;
	tmp = stack->val;
	stack->val = stack->next->val;
	stack->next->val = tmp;
	if (str)
		push_instruction(list, str);
}

void		push(t_stack **dest, t_stack **src, t_inst **list, char *str)
{
	t_stack	*tmp;

	if (!*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dest;
	*dest = tmp;
	if (str)
		push_instruction(list, str);
}

void		rotate(t_stack **stack, t_inst **list, char *str)
{
	t_stack	*tmp;
	t_stack	*iter;

	if (!*stack || !((*stack)->next))
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	iter = *stack;
	while (iter->next)
		iter = iter->next;
	iter->next = tmp;
	tmp->next = NULL;
	if (str)
		push_instruction(list, str);
}

void		rev_rotate(t_stack **stack, t_inst **list, char *str)
{
	t_stack	*first;
	t_stack	*last;

	if (!*stack || !((*stack)->next))
		return ;
	last = *stack;
	first = last->next;
	while (first->next)
	{
		last = last->next;
		first = last->next;
	}
	last->next = NULL;
	first->next = *stack;
	*stack = first;
	if (str)
		push_instruction(list, str);
}
