/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewoillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:00:12 by ewoillar          #+#    #+#             */
/*   Updated: 2024/03/29 16:37:01 by ewoillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_int_in(int *lis, int lis_size, int i)
{
	int	j;

	j = 0;
	while (j < lis_size)
	{
		if (lis_size[j] == i)
			return (1);
		j++;
	}
	return (0);
}

void	lis_rotation(t_stack *stack_a, t_stack *stack_b, int *lis, int lis_size)
{
	int	i;

	i = 0;
	while (i < lis_size)
	{
		if (is_int_in(lis, lis_size, (int)(intptr_t)stack_a->top->content))
		{
			//push
		}
		//rotate and i++
	}
}

t_list	*sort(t_stack *stack_a, t_stack *stack_b, int *lis, int lis_size)
{

}
