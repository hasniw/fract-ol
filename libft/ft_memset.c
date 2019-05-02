/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 23:36:57 by wahasni           #+#    #+#             */
/*   Updated: 2018/11/13 14:17:21 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	int				i;
	char			*schar;
	unsigned char	cchar;

	i = 0;
	cchar = (unsigned char)c;
	schar = (char *)s;
	while (len)
	{
		schar[i] = cchar;
		len--;
		i++;
	}
	return (s);
}
