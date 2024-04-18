/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_next.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewoillar <ewoillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:40:22 by ewoillar          #+#    #+#             */
/*   Updated: 2024/04/18 15:44:40 by ewoillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_sort(t_sort_wrap	*s_w)
{
	free(s_w->m_a);
	free(s_w->m_b);
	free(s_w->m_c);
}

void	sort_3(t_stack *stack_a)
{
	if (*(int *)stack_a->top->content > *(int *)stack_a->top->next->content)
	{
		op_s(stack_a);
		ft_printf("sa\n");
	}
	if (stack_a->top->next->next != NULL)
	{
		if (*(int *)stack_a->top->next->content > \
		*(int *)stack_a->top->next->next->content)
		{
			op_rrs(stack_a);
			ft_printf("rra\n");
		}
		if (*(int *)stack_a->top->content > \
		*(int *)stack_a->top->next->next->content)
		{
			op_rrs(stack_a);
			ft_printf("rra\n");
		}
	}
	if (*(int *)stack_a->top->content > *(int *)stack_a->top->next->content)
	{
		op_s(stack_a);
		ft_printf("sa\n");
	}
}
