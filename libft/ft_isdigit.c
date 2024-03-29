/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewoillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 12:41:39 by ewoillar          #+#    #+#             */
/*   Updated: 2024/02/20 18:15:04 by ewoillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	int	ret_value;

	ret_value = 0;
	if (c >= 48 && c <= 57)
		ret_value = 1;
	return (ret_value);
}