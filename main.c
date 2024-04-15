/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewoillar <ewoillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:31:24 by ewoillar          #+#    #+#             */
/*   Updated: 2024/04/15 18:20:39 by ewoillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	is_array_is_lst(int *arr, t_list *head, int length)
{
	t_list	*current;
	int		i;

	current = head;
	i = 0;
	while (current != NULL && i < length)
	{
		if (arr[i] != *(int *)current->content)
			return (0);
		current = current->next;
		i++;
	}
	if (current != NULL || i < length)
		return (0);
	return (1);
}

int	ft_isint(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	value_check(char *value, t_list *head)
{
	t_list	*current;
	int		i;

	current = head;
	if (!ft_isint(value))
		return (0);
	i = ft_atoi(value);
	while (current != NULL)
	{
		if (i == *(int *)current->content)
			return (0);
		current = current->next;
	}
	return (1);
}

void	error(void)
{
	ft_printf("Error\n");
	exit(0);
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		*lis;
	int		lis_size;
	int		i;

	if (argc < 2)
		return (0);
	stack_a.top = NULL;
	stack_b.top = NULL;
	i = 1;
	while (i < argc)
	{
		if (!value_check(argv[i], stack_a.top))
			error();
		ft_lstadd_back(&stack_a.top, ft_lstnew_int(ft_atoi(argv[i++])));
	}
	lis_size = ft_lstsize(stack_a.top);
	lis = lis_seq(stack_a.top, &lis_size);
	if (is_array_is_lst(lis, stack_a.top, lis_size))
		exit(0);
	sort(&stack_a, &stack_b, lis, lis_size);
	free(lis);
	free_list(stack_a.top);
	return (0);
}