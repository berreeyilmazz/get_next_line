/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: havyilma <havyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 00:19:24 by havyilma          #+#    #+#             */
/*   Updated: 2022/11/12 05:15:13 by havyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

size_t	ft_strlen(char *str);
char	*ft_strjoin(char *str, char *tab);
char	*ft_get_line(char *str);
char	*ft_strchr(char *str, int c);
char	*ft_get_the_lastline(char *str);
char	*ft_buffer(int fd, char *str);
char	*get_next_line(int fd);


#endif
