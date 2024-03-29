/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewoillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:53:52 by ewoillar          #+#    #+#             */
/*   Updated: 2024/02/21 11:42:14 by ewoillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;
	size_t				i;

	p1 = s1;
	p2 = s2;
	i = 0;
	while (i < n)
	{
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	const char s1[] = "atoms\0\0\0\0";  // extra null bytes at end
	const char s2[] = "atoms\0abc";     // embedded null byte
	const char s3[] = "atomsaaa";
	int	size = 7;
	printf("%d\n", memcmp(s1, s2, size));
	printf("%d\n", ft_memcmp(s1, s2, size));
}*/
