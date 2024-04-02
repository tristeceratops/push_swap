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

//function to check if the int value is the same than the head of the stack
int	check_head_lis(t_stack *stack, int value)
{
	if (stack->top->content == value)
		return (1);
	return (0);
}

//function that push the value of a in b if the head content is not in lis
void	push_lis(t_stack *stack_a, t_stack *stack_b, int *lis, int lis_size)
{
	int	i;

	i = 0;
	while (i < lis_size)
	{
		if (!check_head_lis(stack_a, lis[i]))
		{
			op_p(stack_a, stack_b);
			ft_printf("pb\n");
		}
		else
		{
			op_r(stack_a);
			ft_printf("ra\n");
			i++;
		}
	}
}

//function that return mov_b, an array of int that contains the number of rotation that is used to put each value of stack_b at the top
int	*get_mov_b(t_stack *stack_b)
{
	int	*mov_b;
	int	i;
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

//function that return mov_a, an array of int that contains the number of rotation of stack_a that is used to put each value of stack_b in stack_a in increasing order
//example : stack_a = 1 4 7; stack_b = -2 2 3 5 8 10; mov_a = 0 1 1 2 2 2;
int	*get_mov_a(t_stack *stack_a, t_stack *stack_b)
{
	int	*mov_a;
	int	i;
	t_list	*tmp;
	t_list	*tmp2;

	mov_a = (int *)malloc(sizeof(int) * ft_lstsize(stack_b->top));
	if (!mov_a)
		return (NULL);
	i = 0;
	tmp = stack_b->top;
	while (tmp != NULL)
	{
		tmp2 = stack_a->top;
		while (tmp2 != NULL && (int)(intptr_t)tmp2->content < (int)(intptr_t)tmp->content)
		{
			tmp2 = tmp2->next;
			i++;
		}
		mov_a[i] = i;
		tmp = tmp->next;
	}
	return (mov_a);
}

t_list	*sort(t_stack *stack_a, t_stack *stack_b, int *lis, int lis_size)
{
	int * mov_a;
	int * mov_b;
	int * mov_c;

	mov_a = (int *)malloc(sizeof(int) * ft_lstsize(stack_b->top));
	mov_b = (int *)malloc(sizeof(int) * ft_lstsize(stack_b->top));
	mov_c = (int *)malloc(sizeof(int) * ft_lstsize(stack_b->top));	
	push_lis(stack_a, stack_b, lis, lis_size);
	while (stack_b->top != NULL)
	{
		if (ft_lstsize(stack_b->top) == 1)
		{
			op_p(stack_b, stack_a);
			ft_printf("pa\n");
		}
		else
		{
			//mov_a = get_mov_a(stack_a, stack_b);
			//mov_b = get_mov_b(stack_a, stack_b);
			//if (mov_a[0] < mov_b[0])
			//{
			//	op_r(stack_a);
			//	ft_printf("ra\n");
			//}
			//else
			//{
			//	op_r(stack_b);
			//	ft_printf("rb\n");
			//}
		}
	}
}
