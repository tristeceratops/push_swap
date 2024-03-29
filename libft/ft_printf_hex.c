/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewoillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:46:07 by ewoillar          #+#    #+#             */
/*   Updated: 2024/03/21 12:48:26 by ewoillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_hex(char *base, unsigned long long u)
{
	int	size;

	size = 0;
	if (u >= 16)
	{
		size += print_hex(base, u / 16);
		size += print_hex(base, u % 16);
	}
	else
	{
		ft_putchar_fd(base[u], 1);
		return (1);
	}
	return (size);
}

int	ft_printf_hex(va_list arg, char *base)
{
	int				size;
	unsigned int	u;

	u = va_arg(arg, unsigned int);
	size = print_hex(base, u);
	return (size);
}
