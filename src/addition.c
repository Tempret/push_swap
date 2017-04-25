/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addition.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 18:27:51 by dkhlopov          #+#    #+#             */
/*   Updated: 2017/04/21 16:01:53 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_dell(t_inst **target, t_inst **prev_el)
{
	if (!(*target)->next)
	{
		(*prev_el)->next = NULL;
		free(*target);
		*target = NULL;
	}
	else
	{
		(*prev_el)->next = (*target)->next;
		free(*target);
		*target = NULL;
	}
}

void		dell_elem(t_inst **begin, t_inst **target)
{
	t_inst	*prev_el;
	t_inst	*next_el;

	if (*begin == *target)
	{
		*begin = (*begin)->next;
		free(*target);
		*target = NULL;
		return ;
	}
	prev_el = *begin;
	next_el = prev_el->next;
	while (next_el != *target)
	{
		next_el = next_el->next;
		prev_el = prev_el->next;
	}
	do_dell(&next_el, &prev_el);
}

void		del_stack(t_stack **target)
{
	t_stack	*iter;

	if (!*target)
		return ;
	iter = *target;
	while (iter)
	{
		free(iter);
		iter = iter->next;
	}
	*target = NULL;
}

int			push_back(t_stack **begin, int val)
{
	t_stack *new;
	t_stack *iter;
	int		len;

	len = 0;
	new = (t_stack *)malloc(sizeof(t_stack));
	new->val = val;
	new->next = NULL;
	if (!*begin)
	{
		*begin = new;
		return (1);
	}
	else
	{
		iter = *begin;
		while (iter->next)
		{
			iter = iter->next;
			len++;
		}
		iter->next = new;
	}
	return (len + 2);
}

int			sort_check(t_stack *stack)
{
	int		value;

	if (!stack)
		return (0);
	value = stack->val;
	while (stack->next)
	{
		stack = stack->next;
		if (stack && stack->val < value)
			return (0);
		value = stack->val;
	}
	return (1);
}
