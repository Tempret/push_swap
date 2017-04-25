/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_case_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 17:18:17 by dkhlopov          #+#    #+#             */
/*   Updated: 2017/04/21 16:25:03 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_simple_sort_3(t_stack **a, t_inst **list, char name)
{
	if (SECOND(a) > FIRST(a) && SECOND(a) > THIRD(a))
	{
		if (FIRST(a) < THIRD(a))
		{
			(name == 'a') ? rotate(a, list, "ra") : rotate(a, list, "rb");
			(name == 'a') ? swap(*a, list, "sa") : swap(*a, list, "sb");
		}
		(name == 'a') ? rev_rotate(a, list, "rra") : rev_rotate(a, list, "rrb");
	}
	else if (SECOND(a) < FIRST(a) && SECOND(a) < THIRD(a))
	{
		(name == 'a') ? swap(*a, list, "sa") : swap(*a, list, "sb");
		if (FIRST(a) > THIRD(a))
		{
			(name == 'a') ? rev_rotate(a, list, "rra") :
				rev_rotate(a, list, "rrb");
			(name == 'a') ? swap(*a, list, "sa") : swap(*a, list, "sb");
		}
	}
	else if (FIRST(a) > SECOND(a) && SECOND(a) > THIRD(a))
	{
		(name == 'a') ? swap(*a, list, "sa") : swap(*a, list, "sb");
		(name == 'a') ? rev_rotate(a, list, "rra") : rev_rotate(a, list, "rrb");
	}
}

void	do_simple_sort_2a(t_stack **a, t_inst **list)
{
	if (FIRST(a) > SECOND(a))
		swap(*a, list, "sa");
}

void	do_simple_sort_2b(t_stack **a, t_stack **b, t_inst **list)
{
	if (FIRST(b) > SECOND(b))
	{
		push(a, b, list, "pa");
		push(a, b, list, "pa");
	}
	else
	{
		swap(*b, list, "sb");
		push(a, b, list, "pa");
		push(a, b, list, "pa");
	}
}
