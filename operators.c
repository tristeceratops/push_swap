/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewoillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:59:30 by ewoillar          #+#    #+#             */
/*   Updated: 2024/03/22 14:49:52 by ewoillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	delete_node(t_list **head, void *value)
{
	t_list	*current;
	t_list	*prev;

	current = *head;
	prev = NULL;

	while (current != NULL && current->content != value)
	{
		prev = current;
		current = current->next;
	}

	if (current != NULL)
	{
		if (prev == NULL)
			*head = current->next;
		else
			prev->next = current->next;
		free(current);
	}
}

void	op_s(t_stack *sta_a)
{
	int		temp;
	t_list	*lst;

	if (ft_lstsize(sta_a->top) <= 1)
		return ;
	lst = sta_a->top;
	temp = (int)(intptr_t)lst->content;
	lst->content = lst->next->content;
	lst->next->content = (void *)(intptr_t)temp;
}

void	op_ss(t_stack *sta_a, t_stack *sta_b)
{
	op_s(sta_a);
	op_s(sta_b);
}

void	op_p(t_stack *origin, t_stack *target)
{
	if (ft_lstsize(origin->top) == 0)
		return ;
	ft_lstadd_front(&target->top, ft_lstnew(origin->top->content));
	delete_node(&(origin->top), origin->top->content);
}
