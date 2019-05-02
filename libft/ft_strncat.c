/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:37:29 by wahasni           #+#    #+#             */
/*   Updated: 2018/11/11 21:08:28 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	int i;
	int j;
	int size;

	i = 0;
	j = 0;
	size = (int)n;
	while (dst[i])
		i++;
	while ((j < size) && dst[i] == '\0' && src[j])
	{
		dst[i] = src[j];
		dst[i + 1] = '\0';
		j++;
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
