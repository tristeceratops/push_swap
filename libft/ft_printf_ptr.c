/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewoillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:11:07 by ewoillar          #+#    #+#             */
/*   Updated: 2024/03/21 12:48:38 by ewoillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_ptr(va_list arg)
{
	int					size;
	unsigned long long	u;

	u = va_arg(arg, unsigned long long);
	if (u == 0)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	size = 2;
	ft_putstr_fd("0x", 1);
	size += print_hex("0123456789abcdef", u);
	return (size);
}
