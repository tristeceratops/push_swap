/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators_next.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewoillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:37:02 by ewoillar          #+#    #+#             */
/*   Updated: 2024/03/21 17:32:43 by ewoillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_r(t_stack *sta_a)
{
	t_list	*head;
	t_list	*current;

	if (sta_a->top == NULL || sta_a->top->next == NULL)
		return ;
	head = sta_a->top;
	current = head;
	while (current->next != NULL)
		current = current->next;
	current->next = head;
	head = head->next;
	current->next->next = NULL;
	sta_a->top = head;
}

void	op_rr(t_stack *sta_a, t_stack *sta_b)
{
	op_r(sta_a);
	op_r(sta_b);
}

void	op_rrs(t_stack *sta_a)
{
	t_list	*head;
	t_list	*current;
	t_list	*prev;

	if (sta_a->top == NULL || sta_a->top->next == NULL)
		return ;
	head = sta_a->top;
	current = head;
	prev = NULL;
	while (current->next != NULL)
	{
		prev = current;
		current = current->next;
	}
	prev->next = NULL;
	current->next = head;
	head = current;
	sta_a->top = head;
}

void	op_rrr(t_stack *sta_a, t_stack *sta_b)
{
	op_rrs(sta_a);
	op_rrs(sta_b);
}
