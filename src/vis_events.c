/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 18:28:13 by dkhlopov          #+#    #+#             */
/*   Updated: 2017/04/21 18:47:11 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_all_instr_vis(t_param *p)
{
	while (p->next_oper)
		do_next_visual_instr(p, DICEBLE_VISUAL);
	visualisation(p);
	if (sort_check(p->a))
	{
		mlx_string_put(p->mlx, p->win, p->win_x * 0.46, p->win_y * 0.62,
				0x00cc00, "Stack is sorted");
		mlx_string_put(p->mlx, p->win, p->win_x * 0.45, p->win_y * 0.65,
				0x00cc00, "Press [esc] to exit");
	}
	else
	{
		mlx_string_put(p->mlx, p->win, p->win_x * 0.46, p->win_y * 0.62,
				0xcc0000, "Stack isn't sorted");
		mlx_string_put(p->mlx, p->win, p->win_x * 0.45, p->win_y * 0.65,
				0xcc0000, "Press [esc] to exit");
	}
}

int			push_key_hook(int keycode, void *param)
{
	t_param	*p;

	p = (t_param *)param;
	if (keycode == 53)
	{
		free_param(&p);
		exit(0);
	}
	if (keycode == 124)
		do_next_visual_instr(p, ENEBLE_VISUAL);
	if (keycode == 123)
		do_prev_visual_instr(p);
	if (keycode == 36)
		do_all_instr_vis(p);
	return (1);
}
