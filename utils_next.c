/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_next.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewoillar <ewoillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 11:08:50 by ewoillar          #+#    #+#             */
/*   Updated: 2024/04/18 15:43:53 by ewoillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//get minimal value in list
int	get_min_lst(t_list *list)
{
	int	min_value;

	min_value = INT_MAX;
	while (list != NULL)
	{
		if (*(int *)list->content < min_value)
			min_value = *(int *)list->content;
		list = list->next;
	}
	return (min_value);
}

//get maximal value in list
int	get_max_lst(t_list *list)
{
	int	max_value;

	max_value = INT_MIN;
	while (list != NULL)
	{
		if (*(int *)list->content > max_value)
			max_value = *(int *)list->content;
		list = list->next;
	}
	return (max_value);
}

t_list	*ft_lstnew_int(int content)
{
	t_list	*new;
	int		*content_ptr;

	content_ptr = (int *)malloc(sizeof(int));
	if (!content_ptr)
		return (0);
	*content_ptr = content;
	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->content = content_ptr;
	new->next = NULL;
	return (new);
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
