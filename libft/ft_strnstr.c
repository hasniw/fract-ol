/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 18:48:05 by wahasni           #+#    #+#             */
/*   Updated: 2018/11/13 18:54:07 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (haystack[i] && (i < len))
	{
		while ((haystack[i + j] == needle[j]) && needle[j] && ((i + j) < len))
			j += 1;
		if (!needle[j])
			return ((char *)&haystack[i]);
		j = 0;
		i = i + 1;
	}
	if (!needle[0])
		return ((char *)&haystack[i]);
	return (NULL);
}
