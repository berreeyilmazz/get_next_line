/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berreyilmaz <berreyilmaz@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:40:25 by berreyilmaz       #+#    #+#             */
/*   Updated: 2022/11/19 14:55:34 by berreyilmaz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *ft_rdfunction(int fd, char *str)
{
    int     rd;
    char    *buffer;

    buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer)
        return (0);
    rd = 1;
    while(!ft_check_nl(str) && rd != 0)
    {
        rd = read(fd, buffer, BUFFER_SIZE);
        if (rd == -1)
        {
            free(str);
            free(buffer);
            return (0);
        }
        *(buffer + rd) = 0;
        str = ft_strjoin(str, buffer);
    }
    free (buffer);
    return (str);
}

char    *get_next_line(int fd)
{
    static char     *read;
    char            *line;

    if (fd < 0 && BUFFER_SIZE <= 0)
        return (0);
    read = ft_rdfunction(fd, read);
    if (!read)
        return (0);
    line = ft_newline(read);
    read = ft_reststr(read);
    return (line);
}