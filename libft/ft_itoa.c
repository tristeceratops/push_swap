/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewoillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:34:27 by ewoillar          #+#    #+#             */
/*   Updated: 2024/02/23 11:44:32 by ewoillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	calc_lenth(int n)
{
	int		length;
	long	temp;

	length = 0;
	temp = n;
	if (n < 0)
		length++;
	while (temp != 0)
	{
		length++;
		temp /= 10;
	}
	return (length);
}

static char	*int_to_str(long n, char *str, int length)
{
	int	i;

	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	str[length] = '\0';
	i = length;
	while (--i >= 0)
	{
		if (str[i] != '-')
		{
			str[i] = (n % 10) + '0';
			n /= 10;
		}
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		length;
	long	temp;
	char	*str;

	if (n == 0)
	{
		str = (char *)ft_calloc(2, sizeof(char));
		str[0] = '0';
		return (str);
	}
	length = calc_lenth(n);
	str = (char *)ft_calloc((length + 1), sizeof(char));
	temp = n;
	if (!str)
		return (0);
	str = int_to_str(temp, str, length);
	return (str);
}
