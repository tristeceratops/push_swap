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

int calc_mov_a(int i, int size)
{
    if (i == size)
            return (0);
    else if (i > size /2)
        return (i - size);
    else
        return (i);
}

int* get_mov_a(t_stack* stack_a, t_stack* stack_b) {
    int size_b = ft_lstsize(stack_b->top);
    int* mov_a = (int*)malloc(size_b * sizeof(int));
    t_list *temp_a = stack_a -> top;
    t_list *temp_b = stack_b -> top;
    if (!mov_a)
        return NULL;
    int i = 0;
    int j = 0;
    int min;
    while (temp_b != NULL)
    {
        j = 1;
        temp_a = stack_a -> top;
        int max = get_min(stack_a -> top) - 1;
        while (temp_a != NULL)
        {
            if ((int)(intptr_t)temp_a->content < (int)(intptr_t)temp_b->content && (int)(intptr_t)temp_a->content > max)
            {
                max = (int)(intptr_t)temp_a->content;
                mov_a[i] = calc_mov_a(j, ft_lstsize(stack_a -> top));
            }
            j++;
            temp_a = temp_a->next;
        }
        if (max == get_min(stack_a -> top) - 1)
        {
            int z = 0;
            t_list *temp = stack_a->top;
            while (temp != NULL)
            {
                if ((int)(intptr_t)temp->content == get_min(stack_a->top))
                {
                    mov_a[i] = calc_mov_a(z, ft_lstsize(stack_a -> top));;
                }
                z++;
                temp = temp->next;
            }
        }
        i++;
        temp_b = temp_b->next;
    }
    return mov_a;
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
