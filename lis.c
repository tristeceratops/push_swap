/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewoillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:17:13 by ewoillar          #+#    #+#             */
/*   Updated: 2024/03/29 15:13:36 by ewoillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
 * example:
 * arr =	4 6 7 16 2
 * lis =	1 2 3 4 1
 * prev =	-1 0 1 2 -1
 * result =	4 6 7 16
*/

typedef struct s_lis_wrap
{
	int	maxlen;
	int	maxindex;
	int	*arr;
	int	*lis;
	int	*prev;
}	t_lis_wrap;

void	construct_lis(t_lis_wrap *lis_wrap, int length)
{
	int	i;
	int	j;

	i = 0;
	while (i < length)
	{
		lis_wrap->lis[i] = 1;
		lis_wrap->prev[i] = -1;
		j = 0;
		while (j < i)
		{
			if (lis_wrap->arr[j] < lis_wrap->arr[i] && lis_wrap->lis[j] + 1 > lis_wrap->lis[i])
			{
				lis_wrap->lis[i] = lis_wrap->lis[j] + 1;
				lis_wrap->prev[i] = j;
			}
			j++;
		}
		if (lis_wrap->lis[i] > lis_wrap->maxlen)
		{
			lis_wrap->maxlen = lis_wrap->lis[i];
			lis_wrap->maxindex = i;
		}
		i++;
	}
}

int	*construct_result(t_lis_wrap *lis_wrap)
{
	int	*result;
	int	index;

	result = (int *)malloc(lis_wrap->maxlen *sizeof(int));
	if (!result)
		return (NULL);
	index = lis_wrap->maxlen - 1;
	while (lis_wrap->maxindex >= 0)
	{
		result[index] = lis_wrap->arr[lis_wrap->maxindex];
		index--;
		lis_wrap->maxindex = lis_wrap->prev[lis_wrap->maxindex];
	}
	return (result);
}

int	*LIS(t_list *head, int *length)
{
	t_lis_wrap	lis_wrap;
	int		*result;

	lis_wrap.arr = (int *)malloc(*length * sizeof(int)); //original list convert in array
	lis_wrap.lis = (int *)malloc(*length * sizeof(int)); //size of LIS
	lis_wrap.prev = (int *)malloc(*length * sizeof(int)); //previous index
	lis_wrap.maxlen = 1;
	lis_wrap.maxindex = 0;
	if (lis_wrap.arr == NULL || lis_wrap.lis == NULL || lis_wrap.prev == NULL)
		exit(EXIT_FAILURE);
	convert_list_to_array(head, lis_wrap.arr, length);
	construct_lis(&lis_wrap, length);
	*length = lis_wrap.maxlen;
	result = construct_result(&lis_wrap);
	if(!result)
		return (NULL);
	return (result);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main() {
    t_list* head = NULL;
    ft_lstadd_back(&head, ft_lstnew(((void *)(intptr_t)8)));
    ft_lstadd_back(&head, ft_lstnew((void *)(intptr_t)4));
    ft_lstadd_back(&head, ft_lstnew((void *)(intptr_t)7));
    ft_lstadd_back(&head, ft_lstnew((void *)(intptr_t)9));
    ft_lstadd_back(&head, ft_lstnew((void *)(intptr_t)17));
    ft_lstadd_back(&head, ft_lstnew((void *)(intptr_t)15));
    ft_lstadd_back(&head, ft_lstnew((void *)(intptr_t)16));

    int length = ft_lstsize(head);
    int* lis = LIS(head, &length);

    printf("Longest Increasing Subsequence: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", lis[i]);
    }
    printf("\n");

    // Free allocated memory
    free(lis);

    return 0;
}*/