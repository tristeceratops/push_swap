/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewoillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:06:25 by ewoillar          #+#    #+#             */
/*   Updated: 2024/03/21 12:48:48 by ewoillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_str(va_list arg)
{
	char	*str;
	int		ret;

	str = va_arg(arg, char *);
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		ret = 6;
	}
	else
	{
		ft_putstr_fd(str, 1);
		ret = ft_strlen(str);
	}
	return (ret);
}
