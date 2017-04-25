/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis_delim_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 15:16:36 by dkhlopov          #+#    #+#             */
/*   Updated: 2017/04/21 18:21:01 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_rgb		calc_delta(t_rgb a, t_rgb b)
{
	t_rgb	delt;

	delt.r = abs(a.r - b.r) * 100;
	delt.g = abs(a.g - b.g) * 100;
	delt.b = abs(a.b - b.b) * 100;
	return (delt);
}

static void	delim_line(t_param *par, double where)
{
	t_point	begin;
	t_point	end;
	int		i;
	int		width;

	width = (where == 2) ? 6 : 2;
	i = 0;
	begin.x = 0;
	begin.y = par->win_y / where - 3;
	begin.color = (where == 2) ? init_color(DELIMCOLOR1) :
		init_color(DELIMCOLOR2);
	end.x = par->win_x;
	end.y = par->win_y / where - 3;
	end.color = (where == 2) ? init_color(DELIMCOLOR2) :
		init_color(DELIMCOLOR1);
	while (i < width)
	{
		begin.y++;
		end.y++;
		put_line(par->mlx, par->win, begin, end);
		i++;
	}
}

void		paint_delim_line(t_param *par)
{
	delim_line(par, 2);
	delim_line(par, 4);
	delim_line(par, 1.33);
}
