/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: havyilma <havyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 15:13:09 by havyilma          #+#    #+#             */
/*   Updated: 2022/11/26 16:03:31 by havyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int		ft_strlen(char *s);
int		ft_newline(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_get_line(char *str);
char	*ft_rest_str(char *old);
char	*ft_lets_read(int fd, char *str);
char	*get_next_line(int fd);

#endif
