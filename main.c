/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewoillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:04:19 by ewoillar          #+#    #+#             */
/*   Updated: 2024/03/26 12:20:31 by ewoillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *stack, int value)
{
	t_list *new_node = ft_lstnew((void *)(intptr_t)value);
	ft_lstadd_back(&stack->top, new_node);
}

int	pop(t_stack *stack)
{
	if (stack->top == NULL)
		return (-1);
	t_list	*temp = stack->top;
	stack->top = stack->top->next;
	int	value = (int)(intptr_t)temp->content;
	free(temp);
	return (value);
}

int	get_min_index(t_stack *stack, int *minsave)
{
	int	index;
	int	min;
	t_list	*list;
	int	index_tmp;

	list = stack->top;
	index_tmp = 0;
	index = 0;
	min = (int)(intptr_t)list->content;
	while (list != NULL)
	{
		if ((int)(intptr_t)list->content < min)
		{
			min = (int)(intptr_t)list->content;
			index = index_tmp;
		}
		index_tmp++;
		list = list->next;
	}
	*minsave = min;
	return (index);

}

int	is_sorted_descending(t_list *head)
{
	t_list	*current;
	if (head == NULL || head->next == NULL)
		return (1);
	current = head;
	while (current->next != NULL)
	{
		if (*(int *)current->content < *(int *)current->next->content)
			return (0);
		current = current->next;
	}
	return (1);

}

int	is_sorted_ascending(t_list *head)
{
	t_list	*current;
	if (head == NULL || head->next == NULL)
		return (1);
	current = head;
	while (current->next != NULL)
	{
		if (*(int *)current->content > *(int *)current->next->content)
			return (0);
		current = current->next;
	}
	return (1);

}
/*
//sorted but too much operations, >700 for only 30 numbers
//send the first in b, then compare it with top of a. If top_a is greater, push top of a else push top of b
void	stack_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	temp_top = 0;
	op_p(stack_a, stack_b);
	ft_printf("pb\n");
	while (stack_a->top != NULL)
	{
		if ((int)(intptr_t)stack_a->top->content > (int)(intptr_t)stack_b->top->content)
		{
			op_p(stack_a, stack_b);
			ft_printf("pb\n");
		}
		else
		{
			temp_top = (int)(intptr_t)stack_a->top->content;
			while ((int)(intptr_t)stack_b->top->content > temp_top && stack_b->top != NULL)
			{
				op_p(stack_b, stack_a);
				ft_printf("pa\n");
				if (stack_b->top == NULL)
					break ;
			}
			while ((int)(intptr_t)stack_a->top->content != temp_top && stack_a->top != NULL)
			{
				op_r(stack_a);
				ft_printf("ra\n");
			}
			op_p(stack_a, stack_b);
			ft_printf("pb\n");
		}
	}
	while (stack_b->top != NULL)
	{
		op_p(stack_b, stack_a);
		ft_printf("pa\n");
	}
}*/
/// 1530 environ pour 100 données
//rotate until find minimal value and push it to b
/*
void	stack_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	min;
	int	min_index;
	int	size;

	while (stack_a->top != NULL)
	{
		size = ft_lstsize(stack_a->top);
		min_index = get_min_index(stack_a, &min);
		if (min_index >= size/2)
		{
			while ((int)(intptr_t)stack_a->top->content != min)
			{
				op_rrs(stack_a);
				ft_printf("rra\n");
			}
		}
		else
		{
			while ((int)(intptr_t)stack_a->top->content != min)
			{
				op_r(stack_a);
				ft_printf("ra\n");
			}
		}
		if ((int)(intptr_t)stack_a->top->content == min)
		{
			op_p(stack_a, stack_b);
			ft_printf("pb\n");
		}
	}
	while (stack_b->top != NULL)
	{
		op_p(stack_b, stack_a);
		ft_printf("pa\n");
	}
}*/

void	stack_sort(t_stack *stack_a, t_stack *stack_b)
{

}


int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 2)
	{
		ft_printf("Error\n");
		exit(0);
	}
	t_stack	*stack_a = malloc(sizeof(t_stack));
	stack_a->top = NULL;
	while (i < argc)
	{
		push(stack_a, ft_atoi(argv[i]));
		i++;
	}
/*	stack_a->top = NULL;
	push(stack_a, 4);
	push(stack_a, 42);
	push(stack_a, -1);
	push(stack_a, 7);
	push(stack_a, 9);
	push(stack_a, 154);
	push(stack_a, 524);
	push(stack_a, 543);
	push(stack_a, 544);
	push(stack_a, 554);	
	push(stack_a, 41);
	push(stack_a, 422);
	push(stack_a, -31);
	push(stack_a, 47);
	push(stack_a, 95);
	push(stack_a, 1564);
	push(stack_a, 5274);
	push(stack_a, 5943);
	push(stack_a, 5844);
	push(stack_a, -554);
	push(stack_a, 94);
	push(stack_a, 842);
	push(stack_a, -71);
	push(stack_a, 76);
	push(stack_a, 59);
	push(stack_a, 1454);
	push(stack_a, 5234);
	push(stack_a, 5423);
	push(stack_a, 5414);
	push(stack_a, 5054);*/



	t_stack *stack_b = malloc(sizeof(t_stack));
	stack_b->top = NULL;
	/*ft_printf("Original stack: ");
	t_list	*current = stack_a->top;
	while (current != NULL)
	{
		ft_printf("%d ", (intptr_t)current->content);
		current = current->next;
	}
	ft_printf("\n");*/
	stack_sort(stack_a, stack_b);
	/*current = stack_a->top;
	ft_printf("after sort : ");
        while (current != NULL)
        {
                ft_printf("%d ", (intptr_t)current->content);
                current = current->next;
        }
        ft_printf("\n");*/
}
