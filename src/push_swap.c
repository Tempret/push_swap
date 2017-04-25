/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 16:04:08 by dkhlopov          #+#    #+#             */
/*   Updated: 2017/04/21 19:05:54 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_algorithm(t_param *par)
{
	if (par->base_len == 3)
		do_simple_sort_3(&par->a, &par->oper, 'a');
	else if (par->base_len == 2)
		do_simple_sort_2a(&par->a, &par->oper);
	sorting_a(par, par->base_len);
	oper_optimization(&par->oper);
}

static void	print_instruction(t_inst *oper)
{
	while (oper)
	{
		ft_putendl(oper->inst);
		oper = oper->next;
	}
}

int			main(int ac, char **av)
{
	t_param	par;

	if (ac == 1)
		return (1);
	init_param(&par, ac - 1);
	if (!fill_stack(&par.a, av, &par))
	{
		del_stack(&par.a);
		return (1);
	}
	if (sort_check(par.a))
	{
		ft_putstr(SAYOK);
		return (0);
	}
	do_algorithm(&par);
	print_instruction(par.oper);
	del_stack(&par.a);
	del_stack(&par.b);
	del_instr(&par.oper);
	return (0);
}
