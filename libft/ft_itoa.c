/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 19:23:49 by wahasni           #+#    #+#             */
/*   Updated: 2019/01/30 19:14:04 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	size_t		i;
	size_t		n_size;
	static char	str[12];
	char		*min_int;

	i = 0;
	ft_bzero(str, 12);
	n_size = ft_nbrlen(n, 10);
	if (n == -2147483648)
		return (min_int = "-2147483648");
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
		i += 1;
	}
	while (i < n_size--)
	{
		str[n_size] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
