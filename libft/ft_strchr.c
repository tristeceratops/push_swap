/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewoillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:23:30 by ewoillar          #+#    #+#             */
/*   Updated: 2024/02/21 15:09:48 by ewoillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	ch;

	ch = (char) c;
	while (*s != '\0' && *s != ch)
		s++;
	if (*s == ch)
		return ((char *) s);
	else
		return (0);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char *s = "Salut ici on est à 42 !";

	char c = 'z';

	printf("%s\n", strchr(s, c));
	printf("%s\n", ft_strchr(s, c));
}*/
