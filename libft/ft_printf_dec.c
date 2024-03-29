/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewoillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:48:19 by ewoillar          #+#    #+#             */
/*   Updated: 2024/03/21 12:48:15 by ewoillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_dec(va_list arg)
{
	int	dec;
	int	count;
	int	temp;

	dec = va_arg(arg, int);
	count = 0;
	if (dec <= 0)
		count++;
	temp = dec;
	while (temp != 0)
	{
		count++;
		temp /= 10;
	}
	ft_putnbr_fd(dec, 1);
	return (count);
}
