/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewoillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:10:01 by ewoillar          #+#    #+#             */
/*   Updated: 2024/02/21 11:43:12 by ewoillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (src[count])
		count++;
	if (size < 1)
		return (count);
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (count);
}
/*
#include <stdio.h>

int	main(void)
{
	char test[50] = "Hello";

	char *dest = "";
	printf("%s\n", dest);
	unsigned int i = ft_strlcpy(dest, test, 0);
	printf("%s\n", dest);
	printf("%d\n", i);
}*/
