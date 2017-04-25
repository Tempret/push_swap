/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_elem_sort_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 20:27:11 by dkhlopov          #+#    #+#             */
/*   Updated: 2017/04/18 16:17:09 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	case1(t_stack **a, t_inst **list)
{
	if (FIRST(a) < THIRD(a))
	{
		rotate(a, list, "ra");
		swap(*a, list, "sa");
		rev_rotate(a, list, "rra");
	}
	else
	{
		rotate(a, list, "ra");
		swap(*a, list, "sa");
		rev_rotate(a, list, "rra");
		swap(*a, list, "sa");
	}
}

static void	case2(t_stack **a, t_inst **list)
{
	if (FIRST(a) < THIRD(a))
		swap(*a, list, "sa");
	else
	{
		swap(*a, list, "sa");
		rotate(a, list, "ra");
		swap(*a, list, "sa");
		rev_rotate(a, list, "rra");
	}
}

static void	case3(t_stack **a, t_inst **list)
{
	swap(*a, list, "sa");
	rotate(a, list, "ra");
	swap(*a, list, "sa");
	rev_rotate(a, list, "rra");
	swap(*a, list, "sa");
}

void		do_three_elem_sort_a(t_stack **a, t_inst **list)
{
	if (SECOND(a) > FIRST(a) && SECOND(a) > THIRD(a))
		case1(a, list);
	else if (SECOND(a) < FIRST(a) && SECOND(a) < THIRD(a))
		case2(a, list);
	else if (FIRST(a) > SECOND(a) && SECOND(a) > THIRD(a))
		case3(a, list);
}
