/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewoillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:37:00 by ewoillar          #+#    #+#             */
/*   Updated: 2024/02/21 11:32:52 by ewoillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;

	if (*little == '\0')
		return ((char *) big);
	little_len = ft_strlen(little);
	while (*big != '\0' && len >= little_len)
	{
		if (*big == *little && ft_memcmp(big, little, little_len) == 0)
			return ((char *) big);
		big++;
		len--;
	}
	return (0);
}
/*
#include <stdio.h>
#include <bsd/string.h>

int	main(void)
{
	const char *largestring = "Foo Bar Baz";
	const char *smallstring = "Bar";
	int	size = 9;
	char *ptr;

	ptr = strnstr(largestring, smallstring, size);
	printf("%s\n", ptr);
	ptr = ft_strnstr(largestring, smallstring, size);
	printf("%s\n", ptr);
}*/
