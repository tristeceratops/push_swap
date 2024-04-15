/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewoillar <ewoillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:26:47 by ewoillar          #+#    #+#             */
/*   Updated: 2024/04/15 11:17:12 by ewoillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mov_a_calc(t_mov_wrap *m_w, t_stack *stack_a)
{
	if (*(int *)m_w->temp_a->content < *(int *)m_w->temp_b->content \
			&& *(int *)m_w->temp_a->content > m_w->max)
	{
		m_w->max = *(int *)m_w->temp_a->content;
		m_w->mov_a[m_w->i] = calc_mov_a(m_w->j, ft_lstsize(stack_a -> top));
	}
	m_w->j++;
	m_w->temp_a = m_w->temp_a->next;
}

void	mov_a_loop(t_mov_wrap *m_w, t_stack *stack_a)
{
	int		size;

	while (m_w->temp_b != NULL)
	{
		m_w->j = 1;
		m_w->temp_a = stack_a -> top;
		m_w->max = get_min_lst(stack_a -> top) - 1;
		size = ft_lstsize(stack_a -> top);
		while (m_w->temp_a != NULL)
			mov_a_calc(m_w, stack_a);
		if (m_w->max == get_min_lst(stack_a -> top) - 1)
		{
			m_w->z = 0;
			m_w->temp = stack_a->top;
			while (m_w->temp != NULL)
			{
				if (*(int *)m_w->temp->content == get_min_lst(stack_a->top))
					m_w->mov_a[m_w->i] = calc_mov_a(m_w->z, size);
				m_w->z++;
				m_w->temp = m_w->temp->next;
			}
		}
		m_w->i++;
		m_w->temp_b = m_w->temp_b->next;
	}
}

int	*get_mov_a(t_stack *stack_a, t_stack *stack_b, int size_b)
{
	t_mov_wrap	*m_w;

	m_w->mov_a = (int *)malloc(size_b * sizeof(int));
	if (!m_w->mov_a)
		return (NULL);
	m_w->temp_a = stack_a->top;
	m_w->temp_b = stack_b->top;
	if (!m_w->mov_a)
		return (NULL);
	m_w->i = 0;
	mov_a_loop(m_w, stack_a);
	return (m_w->mov_a);
}
