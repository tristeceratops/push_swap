/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewoillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:34:06 by ewoillar          #+#    #+#             */
/*   Updated: 2024/02/21 18:58:14 by ewoillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	char	*str;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = ft_calloc(size, sizeof(char));
	if (!str)
		return (0);
	if (ft_strlen(s1) > 0)
		ft_strlcat(str, s1, size);
	if (ft_strlen(s2) > 0)
		ft_strlcat(str, s2, size);
	return (str);
}
