/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: havyilma <havyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 01:14:20 by havyilma          #+#    #+#             */
/*   Updated: 2022/11/22 01:25:41 by havyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int		ft_nlcheck(char *s1);
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_get_theline(char *str);
char	*ft_reststr(char *str);
char	*ft_rdfunction(int fd, char *str);
char	*get_next_line(int fd);
#endif
