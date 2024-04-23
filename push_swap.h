/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewoillar <ewoillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:07:17 by ewoillar          #+#    #+#             */
/*   Updated: 2024/04/23 14:21:43 by ewoillar         ###   ########.fr       */
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

typedef struct s_sort_wrap
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*m_a;
	int		*m_b;
	int		*m_c;
	int		index;
	int		mindex;
}	t_sort_wrap;

typedef struct s_mov_wrap
{
	int		i;
	int		j;
	int		*mov_a;
	int		max;
	int		z;
	t_list	*temp_a;
	t_list	*temp_b;
	t_list	*temp;
}	t_mov_wrap;

typedef struct s_main_wrap
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		*lis;
	int		lis_size;
	char	**table;
}	t_main_wrap;

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
int		*lis_seq(t_list *head, int *length);
void	sort(t_stack *stack_a, t_stack *stack_b, int *lis, int lis_size);
int		get_min_lst(t_list *list);
t_list	*ft_lstnew_int(int content);
void	positiv_sort(t_sort_wrap *s_w);
void	negativ_sort(t_sort_wrap *s_w);
void	mix_sort(t_sort_wrap *s_w);
void	min_loop(t_sort_wrap *s_w);
void	mov_a_calc(t_mov_wrap *m_w, t_stack *stack_a);
void	mov_a_loop(t_mov_wrap *m_w, t_stack *stack_a);
int		get_mindex_arr(int *arr, int size);
int		get_mindex_lst(t_list *list);
void	push_lis(t_stack *stack_a, t_stack *stack_b, int *lis, int lis_size);
t_list	*create_sorted_list(t_list *head);
void	error(int *lis, t_stack *stack_a, int argc, char **table);
int		value_check(char *value, t_list *head);
int		ft_isint(char *str);
int		is_array_is_lst(int *arr, t_list *head, int length);
void	free_table(char **table);
void	free_sort(t_sort_wrap	*s_w);
void	sort_3(t_stack *stack_a);
void	sort_loop(t_sort_wrap *s_w);
int		*get_mov_a(t_stack *stack_a, t_stack *stack_b, int size_b);
int		*get_mov_b(t_stack *stack_b);
int		*get_mov_c(int *mov_a, int *mov_b, int size);
int		get_second_min_lst(t_list *list);
void	sort_5(t_stack *stack_a, t_stack *stack_b);

#endif
