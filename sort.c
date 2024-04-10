/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewoillar <ewoillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:00:12 by ewoillar          #+#    #+#             */
/*   Updated: 2024/04/10 11:37:21 by ewoillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_lis(int *lis, int value, int lis_size)
{
	int	i;

	i = 0;
	while (lis[i] != value && i < lis_size)
		i++;
	if (lis[i] == value)
		return (1);
	return (0);
}

//function that push the value of a in b if the head content is not in lis
void	push_lis(t_stack *stack_a, t_stack *stack_b, int *lis, int lst_size, int lis_size)
{
	int	i;

	i = 0;
	
	while (i < lst_size)
	{
		if (!check_lis(lis, (int)(intptr_t)stack_a->top->content, lis_size))
		{
			op_p(stack_a, stack_b);
			ft_printf("pb\n");
		}
		else
		{
			op_r(stack_a);
			ft_printf("ra\n");
		}
		i++;
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
    while (temp_b != NULL)
    {
        j = 1;
        temp_a = stack_a -> top;
        int max = get_min_lst(stack_a -> top) - 1;
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
        if (max == get_min_lst(stack_a -> top) - 1)
        {
            int z = 0;
            t_list *temp = stack_a->top;
            while (temp != NULL)
            {
                if ((int)(intptr_t)temp->content == get_min_lst(stack_a->top))
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

int *get_mov_c(int *mov_a, int *mov_b, int size)
{
	int	*mov_c;
	int	i;

	i = 0;
	mov_c = malloc(sizeof(int) * size);
	if (!mov_c)
		return (NULL);
	while (i < size)
	{
		if (mov_a[i] >= 0 && mov_b[i] >= 0)
			mov_c[i] = ft_max(mov_a[i], mov_b[i]);
		else if (mov_a[i] < 0 && mov_b[i] < 0)
			mov_c[i] = ft_abs(ft_min(mov_a[i], mov_b[i]));
		else
			mov_c[i] = ft_abs(mov_a[i]) + ft_abs(mov_b[i]);
		i++;
	}
	return (mov_c);
}
//get index of minimal value in array
int	get_mindex_arr(int *arr, int size)
{
	int	index;
	int	min;
	int	i;

	i = 0;
	index = 0;
	min = arr[0];
	while (i < size)
	{
		if (arr[i] < min)
		{
			index = i;
			min = arr[i];
		}
		i++;
	}
	return (index);
}

int get_mindex_lst(t_list* list) {
	int index = 0;
	int min = INT_MAX;
	int i = 0;
	while (list != NULL) {
		if ((int)(intptr_t)list->content < min) {
			min = (int)(intptr_t)list->content;
			index = i;
		}
		list = list->next;
		i++;
	}
	return index;
}

void sort(t_stack *stack_a, t_stack *stack_b, int *lis, int lis_size)
{
	int	*mov_a;
	int	*mov_b;
	int	*mov_c;
	int	index;	
	
	push_lis(stack_a, stack_b, lis, ft_lstsize(stack_a->top), lis_size);
	ft_printf("end of push_lis\n");
	while (stack_b->top != NULL)
	{
		if (ft_lstsize(stack_b->top) == 1)
		{
			op_p(stack_b, stack_a);
			ft_printf("pa\n");
		}
		else
		{
			mov_a = get_mov_a(stack_a, stack_b);
			mov_b = get_mov_b(stack_b);
			mov_c = get_mov_c(mov_a, mov_b, ft_lstsize(stack_b->top));
			index = get_mindex_arr(mov_c, ft_lstsize(stack_b->top));
			if (mov_a[index] >= 0 && mov_b[index] >= 0)
			{
				while (mov_a[index] > 0 && mov_b[index] > 0)
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
					mov_b[index]--;
				}
			}
			else if (mov_a[index] < 0 && mov_b[index] < 0)
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
			else
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
			op_p(stack_b, stack_a);
			ft_printf("pa\n");
		}
	}
	int mindex = get_mindex_lst(stack_a->top);
	if (mindex > ft_lstsize(stack_a->top) / 2)
	{
		while ((int)(intptr_t)stack_a->top->content != get_min_lst(stack_a->top))
		{
			op_rrs(stack_a);
			ft_printf("rra\n");
		}
	}
	else
	{
		while ((int)(intptr_t)stack_a->top->content != get_min_lst(stack_a->top))
		{
			op_r(stack_a);
			ft_printf("ra\n");
		}
	}
}
