/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:42:30 by wahasni           #+#    #+#             */
/*   Updated: 2018/12/14 14:51:23 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void			ft_list_add_last(t_gnl **save, t_gnl *elem)
{
	t_gnl *list;

	list = *save;
	while (list->next != NULL)
		list = list->next;
	list->next = elem;
}

static t_gnl		*ft_create_list(int fd)
{
	t_gnl *list;

	if (!(list = (t_gnl*)malloc(sizeof(*list))))
		return (NULL);
	list->fd = fd;
	list->temp = ft_strnew(0);
	list->text = NULL;
	list->next = NULL;
	return (list);
}

static t_gnl		*ft_check_fd(t_gnl *save, int fd)
{
	t_gnl *tmp;
	t_gnl *d_list;

	tmp = NULL;
	d_list = save;
	while (d_list)
	{
		if (d_list->fd == fd)
			return (d_list);
		if (!(d_list->next))
		{
			tmp = ft_create_list(fd);
			ft_list_add_last(&d_list, tmp);
			return (tmp);
		}
		d_list = d_list->next;
	}
	return (NULL);
}

static int			ft_check(char *save, char **line)
{
	char	*fin;

	if (!save)
		return (0);
	fin = ft_strchr(save, '\n');
	if (fin != NULL)
	{
		*fin = '\0';
		*line = ft_strdup(save);
		ft_strncpy(save, &fin[1], ft_strlen(&fin[1]) + 1);
		return (1);
	}
	else if (ft_strlen(save) > 0)
	{
		*line = ft_strdup(save);
		*save = '\0';
		return (1);
	}
	return (0);
}

int					get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	static t_gnl	*save = NULL;
	t_gnl			*tmp;
	int				ret;

	if (!(save))
		save = ft_create_list(fd);
	if (fd == -1 || line == NULL || BUFF_SIZE <= 0)
		return (-1);
	tmp = ft_check_fd(save, fd);
	while (!(ft_strchr(tmp->temp, '\n')))
	{
		ret = read(fd, buf, BUFF_SIZE);
		if (ret == -1)
			return (-1);
		if (ret == 0)
			return (ft_check(tmp->text, line));
		buf[ret] = '\0';
		tmp->text = ft_strjoin(tmp->temp, buf);
		free(tmp->temp);
		tmp->temp = tmp->text;
	}
	return (ft_check(tmp->text, line));
}
