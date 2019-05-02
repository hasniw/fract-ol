/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 00:00:52 by wahasni           #+#    #+#             */
/*   Updated: 2019/02/09 16:39:07 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char		*d;
	const char	*s;
	int			i;

	i = 0;
	if (dst <= src)
		ft_memcpy(dst, src, n);
	else
	{
		d = dst + n - 1;
		s = src + n - 1;
		while (n--)
		{
			d[i] = s[i];
			i--;
		}
	}
	return (dst);
}
