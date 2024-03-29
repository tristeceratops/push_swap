/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewoillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:07:17 by ewoillar          #+#    #+#             */
/*   Updated: 2024/03/29 10:32:20 by ewoillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

typedef struct s_stack
{
	t_list	*top;
}	t_stack;

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
#endif
