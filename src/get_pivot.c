/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pivot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhlopov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 14:14:47 by dkhlopov          #+#    #+#             */
/*   Updated: 2017/04/21 16:04:36 by dkhlopov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_q(int *a, int *b)
{
	int		temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static void	quicksort(int *arr, int start, int end)
{
	int		sup;
	int		old_end;
	int		old_start;

	old_end = end;
	old_start = start;
	sup = arr[(start + end) / 2];
	while (start < end)
	{
		while (arr[start] < sup)
			start++;
		while (arr[end] > sup)
			end--;
		if (start <= end)
		{
			swap_q(&arr[start], &arr[end]);
			start++;
			end--;
		}
	}
	if (old_start < end)
		quicksort(arr, old_start, end);
	if (start < old_end)
		quicksort(arr, start, old_end);
}

int			get_pivot(t_stack *begin, int len)
{
	int		*array;
	int		i;
	int		pivot;

	i = 0;
	array = (int *)malloc(sizeof(int) * len);
	while (i < len)
	{
		array[i++] = begin->val;
		begin = begin->next;
	}
	quicksort(array, 0, len - 1);
	pivot = array[(len - 1) / 2];
	free(array);
	return (pivot);
}
