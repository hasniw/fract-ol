/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 19:14:42 by wahasni           #+#    #+#             */
/*   Updated: 2018/12/16 20:49:08 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*blst;
	t_list	*nextlst;

	nextlst = NULL;
	blst = *alst;
	nextlst = blst->next;
	while (nextlst)
	{
		nextlst = blst->next;
		del((blst->content), (blst->content_size));
		free(blst);
		blst = nextlst;
	}
	*alst = NULL;
}
