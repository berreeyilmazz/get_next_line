/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: havyilma <havyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 01:13:27 by havyilma          #+#    #+#             */
/*   Updated: 2022/11/22 01:23:04 by havyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_rdfunction(int fd, char *str)
{
	char	*buff;
	int		rdbyte;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	rdbyte = 1;
	while (!ft_nlcheck(str) && rdbyte != 0)
	{
		rdbyte = read(fd, buff, BUFFER_SIZE);
		if (rdbyte == -1)
		{
			free(str);
			free(buff);
			return (NULL);
		}
		*(buff + rdbyte) = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = ft_rdfunction(fd, str);
	if (!str)
		return (NULL);
	line = ft_get_theline(str);
	str = ft_reststr(str);
	return (line);
}
