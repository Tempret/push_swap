/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 16:39:57 by dkhlopov          #+#    #+#             */
/*   Updated: 2017/04/21 16:22:36 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	abbrev_operations(t_inst **begin)
{
	t_inst	*iter;

	iter = *begin;
	while (iter->next)
	{
		if ((!ft_strcmp(CURR_OP, "sa") && !ft_strcmp(NEXT_OP, "sb"))
				|| (!ft_strcmp(CURR_OP, "sb") && !ft_strcmp(NEXT_OP, "sa")))
		{
			CURR_OP = "ss";
			dell_elem(begin, &iter->next);
			return (1);
		}
		else if ((!ft_strcmp(CURR_OP, "ra") && !ft_strcmp(NEXT_OP, "rb"))
				|| (!ft_strcmp(CURR_OP, "rb") && !ft_strcmp(NEXT_OP, "ra")))
		{
			CURR_OP = "rr";
			dell_elem(begin, &iter->next);
			return (1);
		}
		iter = iter->next;
	}
	return (0);
}

static int	check_rra_pb_ra(t_inst **begin)
{
	t_inst	*iter;

	iter = *begin;
	while (iter->next && iter->next->next)
	{
		if ((!ft_strcmp(CURR_OP, "ra") && !ft_strcmp(NEXT_OP, "pb")
					&& !ft_strcmp(iter->next->next->inst, "rra"))
				|| (!ft_strcmp(CURR_OP, "rb") && !ft_strcmp(NEXT_OP, "pa")
					&& !ft_strcmp(iter->next->next->inst, "rrb")))
		{
			CURR_OP = (!ft_strcmp(CURR_OP, "ra")) ? "sa" : "sb";
			dell_elem(begin, &iter->next->next);
			return (1);
		}
		iter = iter->next;
	}
	return (0);
}

static int	delete_operations(t_inst **begin)
{
	t_inst	*iter;

	iter = *begin;
	while (iter->next)
	{
		if ((!ft_strcmp(CURR_OP, "pa") && !ft_strcmp(NEXT_OP, "pb"))
				|| (!ft_strcmp(CURR_OP, "pb") && !ft_strcmp(NEXT_OP, "pa"))
				|| (!ft_strcmp(CURR_OP, "ra") && !ft_strcmp(NEXT_OP, "rra"))
				|| (!ft_strcmp(CURR_OP, "rra") && !ft_strcmp(NEXT_OP, "ra"))
				|| (!ft_strcmp(CURR_OP, "rb") && !ft_strcmp(NEXT_OP, "rrb"))
				|| (!ft_strcmp(CURR_OP, "rrb") && !ft_strcmp(NEXT_OP, "rb"))
				|| (!ft_strcmp(CURR_OP, "sa") && !ft_strcmp(NEXT_OP, "sa"))
				|| (!ft_strcmp(CURR_OP, "sb") && !ft_strcmp(NEXT_OP, "sb")))
		{
			dell_elem(begin, &iter);
			dell_elem(begin, &iter->next);
			return (1);
		}
		iter = iter->next;
	}
	return (0);
}

void		oper_optimization(t_inst **begin)
{
	while (check_rra_pb_ra(begin))
		;
	while (delete_operations(begin))
		;
	while (abbrev_operations(begin))
		;
}
