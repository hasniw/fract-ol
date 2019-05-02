/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:42:49 by wahasni           #+#    #+#             */
/*   Updated: 2018/11/17 05:47:42 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int i;
	int sign;
	int result;

	i = 0;
	result = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	sign = (str[i] == '-') ? -1 : 1;
	if (sign == -1 || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		if (sign == 1 && result > 214748364 && str[i] > 8)
			return (-1);
		else if (sign == -1 && result > 214748364 && str[i] > 7)
			return (0);
		result = (result * 10) + (str[i] - 48);
		i++;
	}
	return (result * sign);
}
