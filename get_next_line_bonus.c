/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: havyilma <havyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 15:15:39 by havyilma          #+#    #+#             */
/*   Updated: 2022/11/26 16:00:34 by havyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_lets_read(int fd, char *str)
{
	int		rdbyt;
	char	*buff;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	rdbyt = 1;
	while (!ft_newline(str) && rdbyt != 0)
	{
		rdbyt = read(fd, buff, BUFFER_SIZE);
		if (rdbyt == -1)
		{
			free(str);
			free (buff);
			return (NULL);
		}
		buff[rdbyt] = '\0';
		str = ft_strjoin(str, buff);
	}
	free (buff);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str[256];
	char		*lne;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str[fd] = ft_lets_read(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	lne = ft_get_line(str[fd]);
	str[fd] = ft_rest_str(str[fd]);
	return (lne);
}
