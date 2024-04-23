/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewoillar <ewoillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:56:15 by ewoillar          #+#    #+#             */
/*   Updated: 2024/04/23 14:17:31 by ewoillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_5_next(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_b->top != NULL)
	{
		op_p(stack_b, stack_a);
		ft_printf("pa\n");
	}
	if (*(int *)stack_a->top->content > *(int *)stack_a->top->next->content)
	{
		op_s(stack_a);
		ft_printf("sa\n");
	}
}

void	sort_5(t_stack *stack_a, t_stack *stack_b)
{
	int		min;
	int		s_min;
	int		i;

	i = -1;
	min = get_min_lst(stack_a->top);
	s_min = get_second_min_lst(stack_a->top);
	while (++i < 5)
	{
		if (*(int *)stack_a->top->content == min || \
			*(int *)stack_a->top->content == s_min)
		{
			op_p(stack_a, stack_b);
			ft_printf("pb\n");
		}
		else
		{
			op_r(stack_a);
			ft_printf("ra\n");
		}
	}
	sort_3(stack_a);
	sort_5_next(stack_a, stack_b);
}
