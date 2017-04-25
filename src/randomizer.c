/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 16:15:39 by dkhlopov          #+#    #+#             */
/*   Updated: 2017/04/21 16:23:28 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include "push_swap.h"

int		is_alredy_have(int target, int *array, int end)
{
	int		i;

	i = 0;
	while (i < end)
	{
		if (array[i] == target)
			return (1);
		i++;
	}
	return (0);
}

void	try_to_terminate(int *i, int *terminate, int max_size)
{
	(*i)--;
	(*terminate)++;
	if ((*terminate) > (max_size * 10) * max_size)
	{
		ft_putstr("\nProgramm is terminated and exit: to small [max_size]\n");
		exit(1);
	}
}

void	generate_array(int *array, int max_number, int max_size)
{
	int		i;
	int		number;
	int		negative;
	int		terminate;

	i = 0;
	terminate = 0;
	while (i < max_number)
	{
		number = rand() % (max_size + 1);
		negative = rand() % 100;
		number = (negative <= 50) ? -number : number;
		if (is_alredy_have(number, array, i))
			try_to_terminate(&i, &terminate, max_size);
		else
		{
			ft_putnbr(number);
			ft_putchar(' ');
			array[i] = number;
		}
		i++;
	}
}

int		main(int ac, char **av)
{
	int		max_number;
	int		max_size;
	int		*array;

	srand(time(NULL));
	if (ac < 3)
	{
		ft_putstr("usage: ./random [max_number] [max_size]\n");
		return (1);
	}
	max_number = ft_atoi(av[1]);
	max_size = ft_atoi(av[2]);
	array = malloc(sizeof(int) * max_number);
	generate_array(array, max_number, max_size);
	ft_putchar('\n');
	free(array);
	return (0);
}
