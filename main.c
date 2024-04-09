/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewoillar <ewoillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:31:24 by ewoillar          #+#    #+#             */
/*   Updated: 2024/04/09 16:29:25 by ewoillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// main that create two t_stack a and b, check that values in argv are int and put it in stack a and then call sort() to sort a

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
    t_stack	stack_a;
    t_stack	stack_b;
    int		*lis;
    int		lis_size;

    if (argc < 2)
        return (0);
    stack_a.top = NULL;
    stack_b.top = NULL;
    //check if value is int
    int i = 1;
    while (i < argc)
    {
        ft_lstadd_back(&stack_a.top, ft_lstnew((void *)(intptr_t)(argv[i++])));
    }
    printf("stack A :");
    //while loop print value in a
    t_list *tmp = stack_a.top;
    while (tmp != NULL)
    {
        printf("%d ", (int)(intptr_t)tmp->content);
        tmp = tmp->next;
    }
    printf("\n");
    lis_size = ft_lstsize(stack_a.top);
    lis = LIS(stack_a.top, &lis_size);
    printf("LIS: ");
    for (int i = 0; i < lis_size; i++)
    {
        printf("%d ", lis[i]);
    }
    printf("\n");
    sort(&stack_a, &stack_b, lis, lis_size);
    free(lis);
    free_list(stack_a.top);
    return (0);
}