/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 15:22:38 by dkhlopov          #+#    #+#             */
/*   Updated: 2017/04/21 16:06:11 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
