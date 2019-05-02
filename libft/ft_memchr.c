/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:31:01 by wahasni           #+#    #+#             */
/*   Updated: 2018/11/28 15:36:25 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	const char		*schar;

	schar = (const char *)s;
	i = 0;
	while (i < n)
	{
		if ((schar[i]) == (const char)c)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}
