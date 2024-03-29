/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewoillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:23:01 by ewoillar          #+#    #+#             */
/*   Updated: 2024/02/21 11:40:40 by ewoillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;
	unsigned char		uc;

	p = s;
	uc = c;
	while (n-- > 0)
	{
		if (*p == uc)
			return ((void *)p);
		p++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*s = "Le roi des pirates, ce sera moi";
	char	c = 'd';
	unsigned int	n = 6;

	printf("%s\n",(char *)memchr(s, c, n));
	printf("%s\n", (char *)ft_memchr(s, c, n));
}*/
