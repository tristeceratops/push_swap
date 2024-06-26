/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewoillar <ewoillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:31:24 by ewoillar          #+#    #+#             */
/*   Updated: 2024/04/23 12:23:19 by ewoillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

//free a char** table
void	free_table(char **table)
{
	int	i;

	i = 0;
	while (table[i] != NULL)
	{
		free(table[i]);
		i++;
	}
	free(table);
}

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
	long	i;
	int		j;

	current = head;
	if (!ft_isint(value))
		return (0);
	i = ft_atol(value);
	if (i > INT_MAX || i < INT_MIN)
		return (0);
	j = ft_atoi(value);
	while (current != NULL)
	{
		if (j == *(int *)current->content)
			return (0);
		current = current->next;
	}
	return (1);
}

void	error(int *lis, t_stack *stack_a, int argc, char **table)
{
	if (lis == NULL)
		ft_printf("Error\n");
	else
	{
		if (lis != NULL)
			free(lis);
	}
	if (argc == 2)
		free_table(table);
	free_list(stack_a->top);
	exit(0);
}
