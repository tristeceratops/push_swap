/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewoillar <ewoillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:26:47 by ewoillar          #+#    #+#             */
/*   Updated: 2024/04/12 16:06:18 by ewoillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mov_a_loop()
{
	int		j;
}

int	*get_mov_a(t_stack *stack_a, t_stack *stack_b, int size_b)
{
	int		i;
	int		j;
	int		*mov_a;
	int		max;
	int		z;
	t_list	*temp_a;
	t_list	*temp_b;
	t_list	*temp;

	mov_a = (int *)malloc(size_b * sizeof(int));
    if (!mov_a)
        return (NULL);
	temp_a = stack_a->top;
	temp_b = stack_b->top;
	if (!mov_a)
		return (NULL);
	i = 0;
	while (temp_b != NULL)
	{
		j = 1;
		temp_a = stack_a -> top;
		max = get_min_lst(stack_a -> top) - 1;
		while (temp_a != NULL)
		{
			if (*(int *)temp_a->content < *(int *)temp_b->content \
					&& *(int *)temp_a->content > max)
			{
				max = *(int *)temp_a->content;
				mov_a[i] = calc_mov_a(j, ft_lstsize(stack_a -> top));
			}
			j++;
			temp_a = temp_a->next;
		}
		if (max == get_min_lst(stack_a -> top) - 1)
		{
			z = 0;
			temp = stack_a->top;
			while (temp != NULL)
			{
				if (*(int *)temp->content == get_min_lst(stack_a->top))
					mov_a[i] = calc_mov_a(z, ft_lstsize(stack_a -> top));
				z++;
				temp = temp->next;
			}
		}
		i++;
		temp_b = temp_b->next;
	}
	return (mov_a);
}