/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewoillar <ewoillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:17:13 by ewoillar          #+#    #+#             */
/*   Updated: 2024/04/15 16:57:54 by ewoillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
 * example:
 * arr =	4 6 7 16 2
 * lis =	1 2 3 4 1
 * prev =	-1 0 1 2 -1
 * result =	4 6 7 16
*/

int	check_lis(int *lis, int value, int lis_size)
{
	int	i;

	i = 0;
	while (i < lis_size && lis[i] != value)
		i++;
	if (i == lis_size)
		return (0);
	if (lis[i] == value)
		return (1);
	return (0);
}

void	push_lis(t_stack *stack_a, t_stack *stack_b, int *lis, int lis_size)
{
	int	i;
	int	lst_size;

	i = 0;
	lst_size = ft_lstsize(stack_a->top);
	while (i < lst_size)
	{
		if (!check_lis(lis, *(int *)stack_a->top->content, lis_size))
		{
			op_p(stack_a, stack_b);
			ft_printf("pb\n");
		}
		else
		{
			op_r(stack_a);
			ft_printf("ra\n");
		}
		i++;
	}
}

void	construct_lis(t_lis_wrap *lis_wrap, int length)
{
	int	i;
	int	j;

	i = 0;
	while (i < length)
	{
		lis_wrap->lis[i] = 1;
		lis_wrap->prev[i] = -1;
		j = -1;
		while (++j < i)
		{
			if (lis_wrap->arr[j] < lis_wrap->arr[i] && \
					lis_wrap->lis[j] + 1 > lis_wrap->lis[i])
			{
				lis_wrap->lis[i] = lis_wrap->lis[j] + 1;
				lis_wrap->prev[i] = j;
			}
		}
		if (lis_wrap->lis[i] > lis_wrap->maxlen)
		{
			lis_wrap->maxlen = lis_wrap->lis[i];
			lis_wrap->maxindex = i;
		}
		i++;
	}
}

int	*construct_result(t_lis_wrap *lis_wrap)
{
	int	*result;
	int	index;

	result = (int *)malloc(lis_wrap->maxlen * sizeof(int));
	if (!result)
		return (NULL);
	index = lis_wrap->maxlen - 1;
	while (lis_wrap->maxindex >= 0)
	{
		result[index] = lis_wrap->arr[lis_wrap->maxindex];
		index--;
		lis_wrap->maxindex = lis_wrap->prev[lis_wrap->maxindex];
	}
	return (result);
}

int	*lis_seq(t_list *head, int *length)
{
	t_lis_wrap	lis_wrap;
	int			*result;

	lis_wrap.arr = (int *)malloc(*length * sizeof(int));
	lis_wrap.lis = (int *)malloc(*length * sizeof(int));
	lis_wrap.prev = (int *)malloc(*length * sizeof(int));
	lis_wrap.maxlen = 1;
	lis_wrap.maxindex = 0;
	if (lis_wrap.arr == NULL || lis_wrap.lis == NULL || lis_wrap.prev == NULL)
		exit(EXIT_FAILURE);
	convert_list_to_array(head, lis_wrap.arr, *length);
	construct_lis(&lis_wrap, *length);
	*length = lis_wrap.maxlen;
	result = construct_result(&lis_wrap);
	if (!result)
		return (NULL);
	free(lis_wrap.arr);
	free(lis_wrap.lis);
	free(lis_wrap.prev);
	return (result);
}
