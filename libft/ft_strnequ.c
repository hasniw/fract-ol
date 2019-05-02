/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 12:44:41 by wahasni           #+#    #+#             */
/*   Updated: 2019/03/03 15:06:26 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int i;
	int size;

	i = 0;
	size = (size_t)n;
	if (s1 == 0 || s2 == 0)
		return (1);
	while ((s1[i] || s2[i]) && (i < size))
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}
