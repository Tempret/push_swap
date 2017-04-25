/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_elem_sort_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 20:12:21 by dkhlopov          #+#    #+#             */
/*   Updated: 2017/03/29 14:03:47 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	case1(t_stack **a, t_stack **b, t_inst **list)
{
	if (FIRST(b) < THIRD(b))
	{
		swap(*b, list, "sb");
		push(a, b, list, "pa");
		swap(*b, list, "sb");
		push(a, b, list, "pa");
		push(a, b, list, "pa");
	}
	else
	{
		swap(*b, list, "sb");
		push(a, b, list, "pa");
		push(a, b, list, "pa");
		push(a, b, list, "pa");
	}
}

static void	case2(t_stack **a, t_stack **b, t_inst **list)
{
	if (FIRST(b) < THIRD(b))
	{
		rotate(b, list, "rb");
		swap(*b, list, "sb");
		push(a, b, list, "pa");
		rev_rotate(b, list, "rrb");
		push(a, b, list, "pa");
		push(a, b, list, "pa");
	}
	else
	{
		push(a, b, list, "pa");
		swap(*b, list, "sb");
		push(a, b, list, "pa");
		push(a, b, list, "pa");
	}
}

static void	case3(t_stack **a, t_stack **b, t_inst **list)
{
	rotate(b, list, "rb");
	swap(*b, list, "sb");
	push(a, b, list, "pa");
	push(a, b, list, "pa");
	rev_rotate(b, list, "rrb");
	push(a, b, list, "pa");
}

static void	case4(t_stack **a, t_stack **b, t_inst **list)
{
	push(a, b, list, "pa");
	push(a, b, list, "pa");
	push(a, b, list, "pa");
}

void		do_three_elem_sort_b(t_stack **a, t_stack **b, t_inst **list)
{
	if (SECOND(b) > FIRST(b) && SECOND(b) > THIRD(b))
		case1(a, b, list);
	else if (SECOND(b) < FIRST(b) && SECOND(b) < THIRD(b))
		case2(a, b, list);
	else if (FIRST(b) < SECOND(b) && SECOND(b) < THIRD(b))
		case3(a, b, list);
	else
		case4(a, b, list);
}
