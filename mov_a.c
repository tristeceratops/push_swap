/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewoillar <ewoillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:26:47 by ewoillar          #+#    #+#             */
/*   Updated: 2024/04/18 11:02:25 by ewoillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calc_mov_a(int i, int size)
{
	if (i == size)
		return (0);
	else if (i > size / 2)
		return (i - size);
	else
		return (i);
}

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
