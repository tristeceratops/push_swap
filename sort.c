/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewoillar <ewoillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:00:12 by ewoillar          #+#    #+#             */
/*   Updated: 2024/04/16 16:10:41 by ewoillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	mov_a = m_w->mov_a;
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

void	free_sort(t_sort_wrap	*s_w)
{
	free(s_w->m_a);
	free(s_w->m_b);
	free(s_w->m_c);
	free(s_w);
}

void	sort_3(t_stack *stack_a)
{
	if (*(int *)stack_a->top->content > *(int *)stack_a->top->next->content)
	{
		op_s(stack_a);
		ft_printf("sa\n");
	}
	if (*(int *)stack_a->top->next->content > *(int *)stack_a->top->next->next->content)
	{
		op_rrs(stack_a);
		ft_printf("rra\n");
	}
	if (*(int *)stack_a->top->content > *(int *)stack_a->top->next->next->content)
	{
		op_rrs(stack_a);
		ft_printf("rra\n");
	}
	if (*(int *)stack_a->top->content > *(int *)stack_a->top->next->content)
	{
		op_s(stack_a);
		ft_printf("sa\n");
	}
	
}


void	sort(t_stack *stack_a, t_stack *stack_b, int *lis, int lis_size)
{
	t_sort_wrap	*s_w;

	if (ft_lstsize(stack_a->top) <= 3)
	{
		sort_3(stack_a);
		return ;
	}
	s_w = (t_sort_wrap *)malloc(sizeof(t_sort_wrap));
	s_w->stack_a = stack_a;
	s_w->stack_b = stack_b;
	push_lis(stack_a, stack_b, lis, lis_size);
	while (stack_b->top != NULL)
	{
		s_w->m_a = get_mov_a(stack_a, stack_b, ft_lstsize(stack_b->top));
		s_w->m_b = get_mov_b(stack_b);
		s_w->m_c = get_mov_c(s_w->m_a, s_w->m_b, ft_lstsize(stack_b->top));
		s_w->index = get_mindex_arr(s_w->m_c, ft_lstsize(stack_b->top));
		positiv_sort(s_w);
		negativ_sort(s_w);
		mix_sort(s_w);
		op_p(stack_b, stack_a);
		ft_printf("pa\n");
	}
	s_w->mindex = get_mindex_lst(stack_a->top);
	min_loop(s_w);
	free_sort(s_w);
}