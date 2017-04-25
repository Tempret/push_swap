/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 17:49:36 by dkhlopov          #+#    #+#             */
/*   Updated: 2017/04/21 18:46:53 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			do_instr(t_param *par)
{
	t_inst	*iter;

	iter = par->oper;
	while (iter)
	{
		if (!make_instruction(iter->inst, par, 1))
			return (0);
		iter = iter->next;
	}
	return (1);
}

static int	read_instruction(t_param *par)
{
	char	*st;
	int		check;

	check = 1;
	while (get_next_line(0, &st))
	{
		push_instruction(&par->oper, ft_strdup(st));
		free(st);
	}
	par->next_oper = par->oper;
	if (par->flag_vis)
	{
		if (!visual_init(par))
			check = 0;
	}
	else
		check = do_instr(par);
	return (check);
}

static int	algorithm(t_param *par)
{
	if (!read_instruction(par))
	{
		free_param(&par);
		return (0);
	}
	return (1);
}

int			main(int ac, char **av)
{
	t_param	*par;

	if (ac == 1)
		return (1);
	par = (t_param *)malloc(sizeof(t_param));
	init_param(par, ac - 1);
	if (!fill_stack(&par->a, av, par))
	{
		del_stack(&par->a);
		return (1);
	}
	if (sort_check(par->a))
	{
		ft_putstr(SAYOK);
		return (0);
	}
	if (!algorithm(par))
		return (1);
	(sort_check(par->a) && !par->b) ? ft_putstr(SAYOK) : ft_putstr(SAYKO);
	free_param(&par);
	return (0);
}
