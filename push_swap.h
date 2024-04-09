/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewoillar <ewoillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:07:17 by ewoillar          #+#    #+#             */
/*   Updated: 2024/04/09 15:48:04 by ewoillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <limits.h>

typedef struct s_stack
{
	t_list	*top;
}	t_stack;

typedef struct s_lis_wrap
{
	int	maxlen;
	int	maxindex;
	int	*arr;
	int	*lis;
	int	*prev;
}	t_lis_wrap;

void	delete_node(t_list **head, void *value);
void	op_s(t_stack *sta_a);
void	op_ss(t_stack *sta_a, t_stack *sta_b);
void	op_p(t_stack *origin, t_stack *target);
void	op_r(t_stack *sta_a);
void	op_rr(t_stack *sta_a, t_stack *sta_b);
void	op_rrs(t_stack *sta_a);
void	op_rrr(t_stack *sta_a, t_stack *sta_b);
void	free_list(t_list *head);
void	convert_list_to_array(t_list *head, int *arr, int lengh);
int		ft_max(int a, int b);
int		ft_min(int a, int b);
int		ft_abs(int a);
int	*LIS(t_list *head, int *length);
void sort(t_stack *stack_a, t_stack *stack_b, int *lis, int lis_size);
int get_min(t_list* list);

#endif
