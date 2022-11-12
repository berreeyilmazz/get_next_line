/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: havyilma <havyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 00:24:26 by havyilma          #+#    #+#             */
/*   Updated: 2022/11/12 05:16:19 by havyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_buffer(int fd, char *str)
{
	int		rd;
	char	*buff;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	rd = 1;
	while (!ft_strchr(str, '\n') && rd != 0)
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd == -1)
		{
			free(str);
			free(buff);
			return (NULL);
		}
		buff[rd] = 0;
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return(str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_buffer(fd, str);
	if (!str)
		return (NULL);
	line = ft_get_line(str);
	str = ft_get_the_lastline(str);
	return (line);
}
