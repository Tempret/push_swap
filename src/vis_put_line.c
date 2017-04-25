/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis_put_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 15:09:30 by dkhlopov          #+#    #+#             */
/*   Updated: 2017/04/21 18:36:29 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_color_x(t_point a, t_point b, int curr)
{
	t_rgb	delt;
	int		koef;
	t_rgb	res;

	koef = 0;
	delt = calc_delta(a.color, b.color);
	koef = (curr - a.x) * 100 / (b.x - a.x);
	if (a.color.r >= b.color.r)
		res.r = ((a.color.r * 100) - ((delt.r * koef) / 100)) / 100;
	else
		res.r = ((a.color.r * 100) + ((delt.r * koef) / 100)) / 100;
	if (a.color.g >= b.color.g)
		res.g = ((a.color.g * 100) - ((delt.g * koef) / 100)) / 100;
	else
		res.g = ((a.color.g * 100) + ((delt.g * koef) / 100)) / 100;
	if (a.color.b >= b.color.b)
		res.b = ((a.color.b * 100) - ((delt.b * koef) / 100)) / 100;
	else
		res.b = ((a.color.b * 100) + ((delt.b * koef) / 100)) / 100;
	return (rgbtoi(res));
}

static int	get_color_y(t_point a, t_point b, int curr)
{
	t_rgb	delt;
	int		koef;
	t_rgb	res;

	koef = 0;
	delt = calc_delta(a.color, b.color);
	koef = (curr - a.y) * 100 / (b.y - a.y);
	if (a.color.r >= b.color.r)
		res.r = ((a.color.r * 100) - ((delt.r * koef) / 100)) / 100;
	else
		res.r = ((a.color.r * 100) + ((delt.r * koef) / 100)) / 100;
	if (a.color.g >= b.color.g)
		res.g = ((a.color.g * 100) - ((delt.g * koef) / 100)) / 100;
	else
		res.g = ((a.color.g * 100) + ((delt.g * koef) / 100)) / 100;
	if (a.color.b >= b.color.b)
		res.b = ((a.color.b * 100) - ((delt.b * koef) / 100)) / 100;
	else
		res.b = ((a.color.b * 100) + ((delt.b * koef) / 100)) / 100;
	return (rgbtoi(res));
}

static void	put_line_x(void *mlx, void *win, t_point a, t_point b)
{
	int		y;
	int		x;
	int		color;

	if (a.x > b.x)
		swap_coord(&a, &b);
	x = a.x;
	y = a.y;
	while (x <= b.x)
	{
		color = get_color_x(a, b, x);
		mlx_pixel_put(mlx, win, x, y, color);
		x++;
		y = fabs((x - a.x) * (b.y - a.y) / (b.x - a.x));
		y = (a.y < b.y) ? (y + a.y) : (a.y - y);
	}
}

static void	put_line_y(void *mlx, void *win, t_point a, t_point b)
{
	double	y;
	double	x;
	int		swapped;
	int		color;

	swapped = 0;
	if (a.y > b.y)
	{
		swapped = 1;
		swap_coord(&a, &b);
	}
	x = a.x;
	y = a.y;
	while (y <= b.y)
	{
		color = get_color_y(a, b, y);
		mlx_pixel_put(mlx, win, x, y, color);
		y++;
		x = fabs((y - a.y) * (b.x - a.x) / (a.y - b.y));
		x = (a.x < b.x) ? (x + a.x) : (a.x - x);
	}
}

void		put_line(void *mlx, void *win, t_point a, t_point b)
{
	if (fabs(a.x - b.x) >= fabs(a.y - b.y))
		put_line_x(mlx, win, a, b);
	else
		put_line_y(mlx, win, a, b);
}
