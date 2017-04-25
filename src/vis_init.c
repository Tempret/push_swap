/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 15:22:38 by dkhlopov          #+#    #+#             */
/*   Updated: 2017/04/21 18:47:39 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		free_param(t_param **par)
{
	if ((*par)->a)
		del_stack(&(*par)->a);
	if ((*par)->b)
		del_stack(&(*par)->b);
	if ((*par)->oper)
	{
		while ((*par)->oper)
		{
			free((*par)->oper->inst);
			free((*par)->oper);
			(*par)->oper = (*par)->oper->next;
		}
	}
	if ((*par)->mlx)
		mlx_destroy_window((*par)->mlx, (*par)->win);
}

static int	get_max_val(t_stack *a)
{
	int		max_val;

	if (!a)
		return (0);
	max_val = abs(a->val);
	while (a)
	{
		if (abs(a->val) > max_val)
			max_val = abs(a->val);
		a = a->next;
	}
	return (max_val);
}

int			visual_init(t_param *par)
{
	if (!(MLX = mlx_init()))
		return (0);
	if (!(par->win = mlx_new_window(MLX, WINSIZE,
					WINSIZE / 3 * 2, "Push swaP")))
		return (0);
	par->max_val = get_max_val(par->a);
	par->koef = par->win_y / par->max_val / 5;
	par->step = par->win_x / (par->base_len + 1);
	par->item_width = par->step / 4;
	visualisation(par);
	if (!mlx_hook(WIN, 2, 0, push_key_hook, par))
		return (0);
	mlx_loop(MLX);
	return (1);
}

void		init_param(t_param *par, int base_len)
{
	par->a = NULL;
	par->b = NULL;
	par->base_len = base_len;
	par->oper = NULL;
	par->b_begin = 0;
	par->flag_vis = 0;
	par->win_y = WINSIZE / 3 * 2;
	par->win_x = WINSIZE;
}
