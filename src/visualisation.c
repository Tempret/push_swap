/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualisation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 19:48:44 by dkhlopov          #+#    #+#             */
/*   Updated: 2017/04/21 18:47:54 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	put_line_width(t_param *par, t_point begin, t_point end, int width)
{
	int	i;

	i = 0;
	begin.x -= width / 2;
	end.x -= width / 2;
	while (i < width)
	{
		put_line(par->mlx, par->win, begin, end);
		begin.x++;
		end.x++;
		i++;
	}
}

static void	init_point(t_param *par, t_point *point, char name, int i)
{
	if (i == 1)
	{
		point[0].color = init_color(255, 128, 0);
		point[1].color = init_color(255, 191, 0);
	}
	point[0].x = i * par->step;
	point[1].x = i * par->step;
	if (name == 'a')
		point[0].y = par->win_y / 4;
	else
		point[0].y = par->win_y / 4 * 3;
}

static void	paint_stack_a(t_param *par)
{
	t_stack		*target;
	t_point		point[2];
	int			i;
	char		*value;

	i = 1;
	if (!par->a)
		return ;
	target = par->a;
	while (target)
	{
		value = ft_itoa(target->val);
		init_point(par, point, 'a', i);
		point[1].y = point[0].y - target->val * par->koef;
		if (par->item_width > 10)
			(target->val > 0) ?
			mlx_string_put(par->mlx, par->win, point[1].x - 10,
					point[1].y - 30, 0xffcc5c, value) :
			mlx_string_put(par->mlx, par->win, point[1].x - 20,
					point[1].y + 10, 0xffcc5c, value);
		put_line_width(par, point[0], point[1], par->item_width);
		free(value);
		target = target->next;
		i++;
	}
}

static void	paint_stack_b(t_param *par)
{
	t_stack		*target;
	t_point		ps[2];
	int			i;
	char		*value;

	i = 1;
	if (!par->b)
		return ;
	target = par->b;
	while (target)
	{
		value = ft_itoa(target->val);
		init_point(par, ps, 'b', i);
		ps[1].y = ps[0].y - target->val * par->koef;
		if (par->item_width > 10)
			(target->val > 0) ?
			mlx_string_put(par->mlx, par->win, ps[1].x - 10,
					ps[1].y - 30, 0xffcc5c, value) :
			mlx_string_put(par->mlx, par->win, ps[1].x - 20,
					ps[1].y + 10, 0xffcc5c, value);
		free(value);
		put_line_width(par, ps[0], ps[1], par->item_width);
		target = target->next;
		i++;
	}
}

int			visualisation(t_param *par)
{
	mlx_clear_window(par->mlx, par->win);
	mlx_string_put(par->mlx, par->win, par->win_x / 40,
			par->win_y / 40, 0xcc0066, "Stack A");
	mlx_string_put(par->mlx, par->win, par->win_x / 40,
			par->win_y / 40 * 21, 0xcc0066, "Stack B");
	paint_delim_line(par);
	paint_stack_a(par);
	paint_stack_b(par);
	return (1);
}
