/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned_dec.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewoillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 10:47:14 by ewoillar          #+#    #+#             */
/*   Updated: 2024/03/21 12:49:00 by ewoillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printundint(unsigned int u)
{
	char	c;

	if (u > 9)
	{
		ft_printundint(u / 10);
		ft_printundint(u % 10);
	}
	else
	{
		c = u + '0';
		ft_putchar_fd(c, 1);
	}	
}

int	ft_printf_unsigned_dec(va_list arg)
{
	int				count;
	unsigned int	temp;
	unsigned int	u;

	u = va_arg(arg, unsigned int);
	temp = u;
	count = 0;
	if (u == 0)
		count++;
	while (temp != 0)
	{
		count++;
		temp /= 10;
	}
	ft_printundint(u);
	return (count);
}
