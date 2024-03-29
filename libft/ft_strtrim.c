/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewoillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:26:13 by ewoillar          #+#    #+#             */
/*   Updated: 2024/02/26 15:30:53 by ewoillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

static char	*trim_left(char const *s, char const *set)
{
	size_t	start;

	start = 0;
	while (s[start] && is_in_set(s[start], set))
		start++;
	return ((char *)&s[start]);
}

static char	*trim_right(char const *s, char const *set)
{
	size_t	len;
	char	*trimmed_str;
	size_t	i;

	len = 0;
	while (s[len])
		len++;
	while (len > 0 && is_in_set(s[len - 1], set))
		len--;
	trimmed_str = malloc((len + 1) * sizeof(char));
	if (!trimmed_str)
		return (0);
	i = 0;
	while (i < len)
	{
		trimmed_str[i] = s[i];
		i++;
	}
	trimmed_str[len] = '\0';
	return (trimmed_str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed_left;
	char	*trimmed_both;

	trimmed_left = trim_left(s1, set);
	if (!trimmed_left)
		return (0);
	trimmed_both = trim_right(trimmed_left, set);
	if (!trimmed_both)
		return (0);
	return (trimmed_both);
}
