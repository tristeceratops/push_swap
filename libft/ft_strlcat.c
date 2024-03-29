/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewoillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 10:21:34 by ewoillar          #+#    #+#             */
/*   Updated: 2024/02/21 11:20:41 by ewoillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
#include <stdio.h>
#include <bsd/string.h>
*/
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_size;
	size_t	src_size;

	dst_size = 0;
	src_size = ft_strlen(src);
	while (*dst && size > 0)
	{
		dst++;
		dst_size++;
		size--;
	}
	while (*src && size > 1)
	{
		*dst++ = *src++;
		size--;
	}
	if (size == 1 || *src == 0)
		*dst = '\0';
	return (src_size + dst_size);
}
/*
int	main(void)
{
	char	str1[10] = "Hello";
	char	str2[10] = " World";
	char	str3[10] = "Hello";
	char	str4[10] = " World";
	int	size = 45;
	unsigned int	i = strlcat(str1, str2, size);

	printf("%d / %s\n", i, str1);

	i = ft_strlcat(str3, str4, size);

	printf("%d / %s\n", i, str3);
}*/
