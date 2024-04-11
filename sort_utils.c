/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewoillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:04:12 by ewoillar          #+#    #+#             */
/*   Updated: 2024/04/11 17:10:24 by ewoillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	positiv_sort(t_stack *stack_a, t_stack *stack_b, int index)
{
	while (mov_a[index] > 0 && mov_b[index] >= 0)
	{
		op_rr(stack_a, stack_b);
		ft_printf("rr\n");
		mov_a[index]--;
		mov_b[index]--;
	}
	while (mov_a[index] > 0)
	{
		op_r(stack_a);
		ft_printf("ra\n");
		mov_a[index]--;
	}
	while (mov_b[index] > 0)
	{
		op_r(stack_b);
		ft_printf("rb\n");
		mov_b[index];
	}
}

void	negativ_sort(t_stack *stack_a, t_stack *stack_b, int index)
{
	while (mov_a[index] < 0 && mov_b[index] < 0)
	{
		op_rrr(stack_a, stack_b);
		ft_printf("rrr\n");
		mov_a[index]++;
		mov_b[index]++;
	}
	while (mov_a[index] < 0)
	{
		op_rrs(stack_a);
		ft_printf("rra\n");
		mov_a[index]++;
	}
	while (mov_b[index] < 0)
	{
		op_rrs(stack_b);
		ft_printf("rrb\n");
		mov_b[index]++;
	}
}

void	mix_sort(t_stack *stack_a, t_stack *stack_b, int index)
{
	while (mov_a[index] != 0)
	{
		if (mov_a[index] > 0)
		{
			op_r(stack_a);
			ft_printf("ra\n");
			mov_a[index]--;
		}
		else
		{
			op_rrs(stack_a);
			ft_printf("rra\n");
			mov_a[index]++;
		}
	}
	while (mov_b[index] != 0)
	{
		if (mov_b[index] > 0)
		{
			op_r(stack_b);
			ft_printf("rb\n");
			mov_b[index]--;
		}
		else
		{
			op_rrs(stack_b);
			ft_printf("rrb\n");
			mov_b[index]++;
		}
	}
}

void	sort(t_stack *stack_a, t_stack *stack_b, int *lis, int lis_size)
{
	int	*mov_a;
	int	*mov_b;
	int	*mov_c;
	int	index;
	int	mindex;

	push_lis(stack_a, stack_b, lis, lis_size);
	while (stack_b->top != NULL)
	{
		mov_a = get_mov_a(stack_a, stack_b, ft_lstsize(stack_b->top));
		mov_b = get_mov_b(stack_b);
		mov_c = get_mov_c(mov_a, mov_b, ft_lstsize(stack_b->top));
		index = get_mindex_arr(mov_c, ft_lstsize(stack_b->top));
		if (mov_a[index] >= 0 && mov_b[index] >= 0)
			positiv_sort(stack_a, stack_b, index);
		else if (mov_a[index] < 0 && mov_b[index] < 0)
			negativ_sort(stack_a, stack_b, index);
		else
			mix_sort(stack_a, stack_b, index);
	}
}
