/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewoillar <ewoillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:04:12 by ewoillar          #+#    #+#             */
/*   Updated: 2024/04/15 11:08:12 by ewoillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	positiv_sort(t_sort_wrap *s_w)
{
	while (s_w->m_a[s_w->index] > 0 && s_w->m_b[s_w->index] >= 0)
	{
		op_rr(s_w->stack_a, s_w->stack_b);
		ft_printf("rr\n");
		s_w->m_a[s_w->index]--;
		s_w->m_b[s_w->index]--;
	}
	while (s_w->m_a[s_w->index] > 0)
	{
		op_r(s_w->stack_a);
		ft_printf("ra\n");
		s_w->m_a[s_w->index]--;
	}
	while (s_w->m_b[s_w->index] > 0)
	{
		op_r(s_w->stack_b);
		ft_printf("rb\n");
		s_w->m_b[s_w->index];
	}
}

void	negativ_sort(t_sort_wrap *s_w)
{
	while (s_w->m_a[s_w->index] < 0 && s_w->m_b[s_w->index] < 0)
	{
		op_rrr(s_w->stack_a, s_w->stack_b);
		ft_printf("rrr\n");
		s_w->m_a[s_w->index]++;
		s_w->m_b[s_w->index]++;
	}
	while (s_w->m_a[s_w->index] < 0)
	{
		op_rrs(s_w->stack_a);
		ft_printf("rra\n");
		s_w->m_a[s_w->index]++;
	}
	while (s_w->m_b[s_w->index] < 0)
	{
		op_rrs(s_w->stack_b);
		ft_printf("rrb\n");
		s_w->m_b[s_w->index]++;
	}
}

void	mix_sort(t_sort_wrap *s_w)
{
	while (s_w->m_a[s_w->index] > 0)
	{
		op_r(s_w->stack_a);
		ft_printf("ra\n");
		s_w->m_a[s_w->index]--;
	}
	while (s_w->m_a[s_w->index] < 0)
	{
		op_rrs(s_w->stack_a);
		ft_printf("rra\n");
		s_w->m_a[s_w->index]++;
	}
	while (s_w->m_b[s_w->index] > 0)
	{
		op_r(s_w->stack_b);
		ft_printf("rb\n");
		s_w->m_b[s_w->index]--;
	}
	while (s_w->m_b[s_w->index] < 0)
	{
		op_rrs(s_w->stack_b);
		ft_printf("rrb\n");
		s_w->m_b[s_w->index]++;
	}
}

void	min_loop(t_sort_wrap *s_w)
{
	int		min;

	min = get_min_lst(s_w->stack_a->top);
	if (s_w->mindex > ft_lstsize(s_w->stack_a->top) / 2)
	{
		while (*(int *)s_w->stack_a->top->content != min)
		{
			op_rrs(s_w->stack_a);
			ft_printf("rra\n");
		}
	}
	else
	{
		while (*(int *)s_w->stack_a->top->content != min)
		{
			op_r(s_w->stack_a);
			ft_printf("ra\n");
		}
	}
}

void	sort(t_stack *stack_a, t_stack *stack_b, int *lis, int lis_size)
{
	t_sort_wrap	*s_w;

	s_w->stack_a = stack_a;
	s_w->stack_b = stack_b;
	push_lis(stack_a, stack_b, lis, lis_size);
	while (stack_b->top != NULL)
	{
		s_w->m_a = get_mov_a(stack_a, stack_b, ft_lstsize(stack_b->top));
		s_w->m_b = get_mov_b(stack_b);
		s_w->m_c = get_mov_c(s_w->m_a, s_w->m_b, ft_lstsize(stack_b->top));
		s_w->index = get_mindex_arr(s_w->m_c, ft_lstsize(stack_b->top));
		if (s_w->m_a[s_w->index] >= 0 && s_w->m_b[s_w->index] >= 0)
			positiv_sort(s_w);
		else if (s_w->m_a[s_w->index] < 0 && s_w->m_b[s_w->index] < 0)
			negativ_sort(s_w);
		else
			mix_sort(s_w);
		op_p(stack_b, stack_a);
		ft_printf("pa\n");
	}
	s_w->mindex = get_mindex_lst(stack_a->top);
	min_loop(s_w);
}
