/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 13:46:13 by wahasni           #+#    #+#             */
/*   Updated: 2018/11/14 13:49:16 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_wordlen(const char *s, char c)
{
	unsigned int	i;
	size_t			len;

	i = 0;
	len = 0;
	while (s[i] == c)
		i += 1;
	while (s[i] != c && s[i++])
		len += 1;
	return (len);
}
