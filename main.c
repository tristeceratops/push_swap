/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewoillar <ewoillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:31:24 by ewoillar          #+#    #+#             */
/*   Updated: 2024/04/10 15:19:48 by ewoillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// main that create two t_stack a and b, check that values in argv are int and put it in stack a and then call sort() to sort a

#include "push_swap.h"
#include <stdio.h>

//is string is int
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

int value_check(char *value, t_list *head)
{
    t_list *current = head;
    int i;

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
    int i = 1;
    while (i < argc)
    {
        if (!value_check(argv[i], stack_a.top))
        {
            ft_printf("Error\n");
            return (0);
        }
        ft_lstadd_back(&stack_a.top, ft_lstnew_int(ft_atoi(argv[i++])));
    }
    lis_size = ft_lstsize(stack_a.top);
    lis = LIS(stack_a.top, &lis_size);
    sort(&stack_a, &stack_b, lis, lis_size);
    free(lis);
    free_list(stack_a.top);
    return (0);
}