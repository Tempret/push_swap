/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 14:20:39 by dkhlopov          #+#    #+#             */
/*   Updated: 2017/04/21 18:18:23 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				del_instr(t_inst **list)
{
	while (*list)
	{
		free(*list);
		*list = (*list)->next;
	}
}

static long long	ft_atoll(const char *str)
{
	int			i;
	long long	negativ;
	long long	number;

	i = 0;
	negativ = 0;
	number = 0;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n')
			|| (str[i] == '\v') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == 45)
		negativ = 1;
	if ((str[i] == 45) || (str[i] == 43))
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		number = number * 10 + (str[i] - 48);
		i++;
		if (i > 18)
			return ((long long)MAX_INT + 1);
	}
	if (negativ == 1)
		return (-number);
	else
		return (number);
}

static int			check_argument(char *arg)
{
	long long	val;

	val = ft_atoll(arg);
	if (val > MAX_INT || val < MIN_INT)
	{
		ft_putstr_fd("Error: argument bigger than integer\n", 2);
		return (0);
	}
	if (*arg == '-')
		arg++;
	while (*arg)
	{
		if (!ft_isdigit(*arg))
		{
			ft_putstr_fd("Error: one of arguments isn't an integer\n", 2);
			return (0);
		}
		arg++;
	}
	return (1);
}

static int			check_duplicate(t_stack *stack, int value)
{
	if (!stack)
		return (1);
	while (stack)
	{
		if (stack->val == value)
		{
			ft_putstr_fd("Error: was found duplicate\n", 2);
			return (0);
		}
		stack = stack->next;
	}
	return (1);
}

int					fill_stack(t_stack **a, char **av, t_param *par)
{
	int		index;
	int		value;

	index = 1;
	if (!ft_strcmp(av[par->base_len], "-v"))
	{
		if (par->base_len == 1)
			return (0);
		av[par->base_len] = NULL;
		par->base_len--;
		par->flag_vis = 1;
	}
	while (av[index])
	{
		value = ft_atoi(av[index]);
		if (!check_argument(av[index]) || !check_duplicate(*a, value))
			return (0);
		index++;
		push_back(a, value);
	}
	return (1);
}
