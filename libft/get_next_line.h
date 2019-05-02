/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 12:51:19 by wahasni           #+#    #+#             */
/*   Updated: 2019/04/14 16:01:21 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

# define BUFF_SIZE 10

typedef struct		s_gnl
{
	char			*text;
	char			*temp;
	struct s_gnl	*next;
	int				fd;
}					t_gnl;

int					get_next_line(const int fd, char **line);

#endif
