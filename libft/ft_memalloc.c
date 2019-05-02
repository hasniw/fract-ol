/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 01:30:43 by wahasni           #+#    #+#             */
/*   Updated: 2018/11/27 16:53:32 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*mem;
	int		i;

	i = 0;
	if (!(mem = (char*)malloc((size) * sizeof(char))))
		return (0);
	while (size)
	{
		mem[i] = '\0';
		size--;
		i++;
	}
	return ((void *)mem);
}
