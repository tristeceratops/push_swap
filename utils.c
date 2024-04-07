/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewoillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:25:10 by ewoillar          #+#    #+#             */
/*   Updated: 2024/03/29 15:23:15 by ewoillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_list *head)
{
	t_list	*temp;
	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

void	convert_list_to_array(t_list *head, int *arr, int length)
{
	t_list	*current;
	int	i;

	current = head;
	i = 0;
	while (current != NULL && i < length)
	{
		arr[i++] = (int)(intptr_t)current->content;
		current = current->next;
	}
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int	ft_abs(int a)
{
	if (a < 0)
		return (-a);
	else
		return (a);
}

int get_min(t_list* list) {
    int min_value = INT_MAX;

    while (list != NULL) {
        if ((int)(intptr_t)list->content < min_value) {
            min_value = (int)(intptr_t)list->content;
        }
        list = list->next;
    }

    return min_value;
}

int get_max(t_list* list) {
    int max_value = INT_MIN;

    while (list != NULL) {
        if ((int)(intptr_t)list->content > max_value) {
            max_value = (int)(intptr_t)list->content;
        }
        list = list->next;
    }

    return max_value;
}