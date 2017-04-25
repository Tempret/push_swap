/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis_addition.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 15:03:06 by dkhlopov          #+#    #+#             */
/*   Updated: 2017/04/21 18:19:45 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_rgb	rgb_init(int color, int r, int g, int b)
{
	t_rgb	clr;

	clr.r = (color) ? ((color & 0xFF0000) >> 16) : r;
	clr.g = (color) ? ((color & 0xFF00) >> 8) : g;
	clr.b = (color) ? (color & 0xFF) : b;
	return (clr);
}

void	swap_color(t_rgb *a, t_rgb *b)
{
	int		tmp;

	tmp = a->r;
	a->r = b->r;
	b->r = tmp;
	tmp = a->g;
	a->g = b->g;
	b->g = tmp;
	tmp = a->b;
	a->b = b->b;
	b->b = tmp;
}

void	swap_coord(t_point *a, t_point *b)
{
	int		tmp;

	tmp = a->x;
	a->x = b->x;
	b->x = tmp;
	tmp = a->y;
	a->y = b->y;
	b->y = tmp;
	swap_color(&a->color, &b->color);
}

t_rgb	init_color(int r, int g, int b)
{
	t_rgb	color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

int		rgbtoi(t_rgb src)
{
	int		res;

	res = 0;
	res += src.b;
	res += src.g << 8;
	res += src.r << 16;
	return (res);
}
