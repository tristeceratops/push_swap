/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewoillar <ewoillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:00:12 by ewoillar          #+#    #+#             */
/*   Updated: 2024/04/23 13:57:21 by ewoillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*arrdup(int *array, int size)
{
	int	*res;
	int	i;

	res = malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
	{
		res[i] = array[i];
		i++;
	}
	return (res);
}

int	*get_mov_b(t_stack *stack_b)
{
	int		*mov_b;
	int		i;
	t_list	*tmp;

	mov_b = (int *)malloc(sizeof(int) * ft_lstsize(stack_b->top));
	if (!mov_b)
		return (NULL);
	i = 0;
	tmp = stack_b->top;
	while (tmp != NULL && i <= ft_lstsize(stack_b->top) / 2)
	{
		mov_b[i] = i;
		if (i >= 1)
			mov_b[ft_lstsize(stack_b->top) - i] = -i;
		tmp = tmp->next;
		i++;
	}
	return (mov_b);
}

int	*get_mov_a(t_stack *stack_a, t_stack *stack_b, int size_b)
{
	t_mov_wrap	*m_w;
	int			*mov_a;

	m_w = (t_mov_wrap *)malloc(sizeof(t_mov_wrap));
	m_w->mov_a = (int *)malloc(size_b * sizeof(int));
	if (!m_w->mov_a)
		return (NULL);
	m_w->temp_a = stack_a->top;
	m_w->temp_b = stack_b->top;
	if (!m_w->mov_a)
		return (NULL);
	m_w->i = 0;
	mov_a_loop(m_w, stack_a);
	mov_a = arrdup(m_w->mov_a, size_b);
	free(m_w->mov_a);
	free(m_w);
	return (mov_a);
}

int	*get_mov_c(int *mov_a, int *mov_b, int size)
{
	int	*mov_c;
	int	i;

	i = 0;
	mov_c = malloc(sizeof(int) * size);
	if (!mov_c)
		return (NULL);
	while (i < size)
	{
		if (mov_a[i] >= 0 && mov_b[i] >= 0)
			mov_c[i] = ft_max(mov_a[i], mov_b[i]);
		else if (mov_a[i] < 0 && mov_b[i] < 0)
			mov_c[i] = ft_abs(ft_min(mov_a[i], mov_b[i]));
		else
			mov_c[i] = ft_abs(mov_a[i]) + ft_abs(mov_b[i]);
		i++;
	}
	return (mov_c);
}

void	sort(t_stack *stack_a, t_stack *stack_b, int *lis, int lis_size)
{
	t_sort_wrap	*s_w;

	if (ft_lstsize(stack_a->top) <= 3)
	{
		sort_3(stack_a);
		return ;
	}
	if (ft_lstsize(stack_a->top) > 3 && ft_lstsize(stack_a->top) <= 5)
	{
		sort_5(stack_a, stack_b);
		return ;
	}
	s_w = (t_sort_wrap *)malloc(sizeof(t_sort_wrap));
	s_w->stack_a = stack_a;
	s_w->stack_b = stack_b;
	push_lis(stack_a, stack_b, lis, lis_size);
	sort_loop(s_w);
	s_w->mindex = get_mindex_lst(stack_a->top);
	min_loop(s_w);
	free(s_w);
}
