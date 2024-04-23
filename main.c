/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewoillar <ewoillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:25:29 by ewoillar          #+#    #+#             */
/*   Updated: 2024/04/23 12:33:49 by ewoillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*loop_sorted_list(t_list *list, int min_value, t_list *sorted_list)
{
	t_list	*new_node;

	while (*(int *)list->content != min_value)
	{
		new_node = ft_lstnew_int(*(int *)list->content);
		if (!new_node)
			return (NULL);
		ft_lstadd_back(&sorted_list, new_node);
		list = list->next;
	}
	return (sorted_list);
}

t_list	*create_sorted_list(t_list *head)
{
	t_list	*sorted_list;
	t_list	*list;
	t_list	*new_node;
	int		min_value;

	sorted_list = NULL;
	list = head;
	min_value = get_min_lst(list);
	while (*(int *)list->content != min_value)
		list = list->next;
	while (list != NULL)
	{
		new_node = ft_lstnew_int(*(int *)list->content);
		if (!new_node)
			return (NULL);
		ft_lstadd_back(&sorted_list, new_node);
		list = list->next;
	}
	list = head;
	sorted_list = loop_sorted_list(list, min_value, sorted_list);
	return (sorted_list);
}

void	next_main(int argc, t_main_wrap s_w)
{
	s_w.lis_size = ft_lstsize(s_w.stack_a.top);
	s_w.lis = lis_seq(s_w.stack_a.top, &s_w.lis_size);
	if (is_array_is_lst(s_w.lis, s_w.stack_a.top, s_w.lis_size))
		error(s_w.lis, &s_w.stack_a, argc, s_w.table);
	sort(&s_w.stack_a, &s_w.stack_b, s_w.lis, s_w.lis_size);
	if (argc == 2)
		free_table(s_w.table);
	free(s_w.lis);
	free_list(s_w.stack_a.top);
}

int	main(int argc, char **argv)
{
	t_main_wrap	s_w;
	int			i;

	if (argc < 2)
		return (0);
	s_w.table = argv;
	if (argc == 2)
		s_w.table = ft_split(argv[1], ' ');
	s_w.stack_a.top = NULL;
	s_w.stack_b.top = NULL;
	if (*s_w.table == NULL)
		error(NULL, &s_w.stack_a, argc, s_w.table);
	i = 1;
	if (argc == 2)
		i = 0;
	while (s_w.table[i] != NULL)
	{
		if (!value_check(s_w.table[i], s_w.stack_a.top))
			error(NULL, &s_w.stack_a, argc, s_w.table);
		ft_lstadd_back(&s_w.stack_a.top, \
			ft_lstnew_int(ft_atoi(s_w.table[i++])));
	}
	next_main(argc, s_w);
	return (0);
}
