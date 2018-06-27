/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshih <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 21:44:37 by sshih             #+#    #+#             */
/*   Updated: 2018/06/11 21:45:30 by sshih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

int		check_new_line(char **store, char **line)
{
	char	*str;

	if (!**store)
		return(0);
	if (ft_strchr(*store, '\n'))
	{
		*(ft_strchr(*store, '\n')) = '\0';
		*line = ft_strdup(*store);
		str =  ft_strdup(ft_strchr(*store, '\0') + 1);
		ft_memdel((void **)store);
		*store = str;
	}
	else
	{
		*line = ft_strdup(*store);
		ft_memdel((void **)store);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char		*save_buff[MAX_FD];
	char			buf[BUFF_SIZE + 1];
	char			*tmp;
	int				read_buff;

	if (fd < 0 || read(fd, buf, 0) < 0 || !line)
		return (-1);
	if (!save_buff[fd])
		save_buff[fd] = ft_strnew(0);
	while (!ft_strchr(save_buff[fd], '\n') && (read_buff = read(fd, buf, BUFF_SIZE)))
	{
		if (read_buff == 0)
			break;
		else
			buf[read_buff] = '\0';
		tmp = ft_strjoin(save_buff[fd], buf);
		free(save_buff[fd]);
		save_buff[fd] = tmp;
	}
	return (check_new_line(&save_buff[fd], line));
}