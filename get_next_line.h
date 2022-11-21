/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berreyilmaz <berreyilmaz@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:40:25 by berreyilmaz       #+#    #+#             */
/*   Updated: 2022/11/18 18:53:28 by berreyilmaz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#  ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#  ifndef BUFFER_SIZE
# define BUFFER_SIZE 42

# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

size_t  ft_strlen(char *s);
int     ft_check_nl(char *s);
char    *ft_strjoin(char *s1, char *s2);
char    *ft_newline(char *str);
char    *ft_reststr(char *str);
char    *get_next_line(int fd);
char    *ft_rdfunction(int fd, char *str);


# endif