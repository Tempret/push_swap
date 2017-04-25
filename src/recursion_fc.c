/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion_fc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 17:45:04 by dkhlopov          #+#    #+#             */
/*   Updated: 2017/04/21 16:24:39 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		half_a_to_b(t_param *par, int len, int pivot)
{
	int		push_cnt;
	int		max_push;
	int		rra_cnt;

	rra_cnt = 0;
	push_cnt = 0;
	max_push = (len % 2) ? len / 2 + 1 : len / 2;
	while (push_cnt < max_push)
	{
		if (par->a->val <= pivot)
		{
			push(&par->b, &par->a, &par->oper, "pb");
			push_cnt++;
		}
		else
		{
			rotate(&par->a, &par->oper, "ra");
			rra_cnt++;
		}
	}
	while (par->b_begin && rra_cnt--)
		rev_rotate(&par->a, &par->oper, "rra");
	return (push_cnt);
}

static int		half_b_to_a(t_param *par, int len, int pivot)
{
	int		push_cnt;
	int		max_push;
	int		rrb_cnt;

	push_cnt = 0;
	rrb_cnt = 0;
	max_push = len / 2 + 1;
	while (push_cnt < max_push)
	{
		if (par->b->val >= pivot)
		{
			push(&par->a, &par->b, &par->oper, "pa");
			push_cnt++;
		}
		else
		{
			rotate(&par->b, &par->oper, "rb");
			rrb_cnt++;
		}
	}
	while (rrb_cnt-- && len != par->base_len / 2)
		rev_rotate(&par->b, &par->oper, "rrb");
	return (push_cnt);
}

void			sorting_b(t_param *par, int len)
{
	int		after_len;

	after_len = 0;
	par->b_begin = 1;
	if (len == 3)
	{
		do_three_elem_sort_b(&par->a, &par->b, &par->oper);
		return ;
	}
	else if (len == 2)
	{
		do_simple_sort_2b(&par->a, &par->b, &par->oper);
		return ;
	}
	else if (len == 1)
	{
		push(&par->a, &par->b, &par->oper, "pa");
		return ;
	}
	after_len = half_b_to_a(par, len, get_pivot(par->b, len));
	sorting_a(par, after_len);
	sorting_b(par, len - after_len);
}

void			sorting_a(t_param *par, int len)
{
	int		after_len;

	after_len = 0;
	if (len == 3)
	{
		do_three_elem_sort_a(&par->a, &par->oper);
		return ;
	}
	else if (len == 2)
	{
		do_simple_sort_2a(&par->a, &par->oper);
		return ;
	}
	after_len = half_a_to_b(par, len, get_pivot(par->a, len));
	sorting_a(par, len - after_len);
	sorting_b(par, after_len);
}
