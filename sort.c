/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewoillar <ewoillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 16:00:12 by ewoillar          #+#    #+#             */
/*   Updated: 2024/04/11 14:48:44 by ewoillar         ###   ########.fr       */
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

void	push_lis(t_stack *stack_a, t_stack *stack_b, int *lis, int lis_size)
{
	int	i;
	int	lst_size;

	i = 0;
	lst_size = ft_lstsize(stack_a->top);
	while (i < lst_size)
	{
		if (!check_lis(lis, *(int *)stack_a->top->content, lis_size))
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

int	*get_mov_b(t_stack *stack_b)
{
	int		*mov_b;
	int		i;
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

int	calc_mov_a(int i, int size)
{
	if (i == size)
		return (0);
	else if (i > size / 2)
		return (i - size);
	else
		return (i);
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

int	*get_mov_c(int *mov_a, int *mov_b, int size)
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

int	get_mindex_lst(t_list *list)
{
	int	index;
	int	min;
	int	i;

	index = 0;
	min = INT_MAX;
	i = 0;
	while (list != NULL)
	{
		if (*(int *)list->content < min)
		{
			min = *(int *)list->content;
			index = i;
		}
		list = list->next;
		i++;
	}
	return (index);
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
	mindex = get_mindex_lst(stack_a->top);
	if (mindex > ft_lstsize(stack_a->top) / 2)
	{
		while (*(int *)stack_a->top->content != get_min_lst(stack_a->top))
		{
			op_rrs(stack_a);
			ft_printf("rra\n");
		}
	}
	else
	{
		while (*(int *)stack_a->top->content != get_min_lst(stack_a->top))
		{
			op_r(stack_a);
			ft_printf("ra\n");
		}
	}
}
