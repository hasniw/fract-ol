/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:54:02 by wahasni           #+#    #+#             */
/*   Updated: 2019/03/03 15:05:22 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;
	int		size;
	int		i;

	i = 0;
	size = (size_t)n;
	d = (char *)dest;
	s = (char *)src;
	while (i < size)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}
