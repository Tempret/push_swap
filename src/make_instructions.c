/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 15:22:17 by dkhlopov          #+#    #+#             */
/*   Updated: 2017/04/21 19:05:20 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_simple_instructions(t_stack **a, t_stack **b, char *ln, int rev)
{
	if (!ft_strcmp("sa", ln))
		swap(*a, NULL, NULL);
	else if (!ft_strcmp("sb", ln))
		swap(*b, NULL, NULL);
	else if (!ft_strcmp("pa", ln))
		rev ? push(a, b, NULL, NULL) : push(b, a, NULL, NULL);
	else if (!ft_strcmp("pb", ln))
		rev ? push(b, a, NULL, NULL) : push(a, b, NULL, NULL);
}

static void	do_other_instructions(t_stack **a, t_stack **b, char *ln, int rev)
{
	if (!ft_strcmp("ss", ln))
	{
		swap(*a, NULL, NULL);
		swap(*b, NULL, NULL);
	}
	else if (!ft_strcmp("rr", ln))
	{
		rev ? rotate(a, NULL, NULL) : rev_rotate(a, NULL, NULL);
		rev ? rotate(b, NULL, NULL) : rev_rotate(b, NULL, NULL);
	}
	else if (!ft_strcmp("rrr", ln))
	{
		rev ? rev_rotate(a, NULL, NULL) : rotate(a, NULL, NULL);
		rev ? rev_rotate(b, NULL, NULL) : rotate(b, NULL, NULL);
	}
	else if (!ft_strcmp("ra", ln))
		rev ? rotate(a, NULL, NULL) : rev_rotate(a, NULL, NULL);
	else if (!ft_strcmp("rb", ln))
		rev ? rotate(b, NULL, NULL) : rev_rotate(b, NULL, NULL);
	else if (!ft_strcmp("rra", ln))
		rev ? rev_rotate(a, NULL, NULL) : rotate(a, NULL, NULL);
	else if (!ft_strcmp("rrb", ln))
		rev ? rev_rotate(b, NULL, NULL) : rotate(b, NULL, NULL);
}

int			make_instruction(char *line, t_param *par, int rev)
{
	if (!ft_strcmp("sa", line) || !ft_strcmp("sb", line) ||
				!ft_strcmp("pa", line) || !ft_strcmp("pb", line))
		do_simple_instructions(&par->a, &par->b, line, rev);
	else if (!ft_strcmp("ss", line) || !ft_strcmp("rr", line) ||
				!ft_strcmp("rrr", line) || !ft_strcmp("ra", line) ||
				!ft_strcmp("rb", line) || !ft_strcmp("rra", line) ||
				!ft_strcmp("rrb", line))
		do_other_instructions(&par->a, &par->b, line, rev);
	else
	{
		del_instr(&par->oper);
		ft_putstr_fd("Error: invalid instruction\n", 2);
		return (0);
	}
	return (1);
}

int			do_next_visual_instr(t_param *par, int visual)
{
	if (par->next_oper)
	{
		if (!make_instruction(par->next_oper->inst, par, 1))
		{
			free_param(&par);
			exit(1);
		}
		if (visual)
			visualisation(par);
		par->next_oper = par->next_oper->next;
	}
	else
	{
		if (sort_check(par->a) && !par->b)
			mlx_string_put(MLX, WIN, par->win_x * 0.4, par->win_y * 0.62,
			0x00cc00, "Stack is sorted. Press [esc] to exit");
		else
			mlx_string_put(MLX, WIN, par->win_x * 0.4, par->win_y * 0.62,
			0xcc0000, "Stack isn't sorted. Press [esc] to exit");
	}
	return (1);
}

int			do_prev_visual_instr(t_param *par)
{
	if (par->next_oper && par->next_oper->prev)
	{
		par->next_oper = par->next_oper->prev;
		if (!make_instruction(par->next_oper->inst, par, 0))
			return (0);
		visualisation(par);
	}
	return (1);
}
