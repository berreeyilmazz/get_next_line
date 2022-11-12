/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: havyilma <havyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 00:24:21 by havyilma          #+#    #+#             */
/*   Updated: 2022/11/12 05:01:12 by havyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *str, char *tab)
{
	size_t	i;
	size_t	j;
	char	*newstr;

	i = 0;
	j = 0;
	if (!str || !tab)
	/*
	{
		if(!str)
		{
			str = malloc(sizeof(char));
			str[0] = 0;
			return (NULL);
		if (!tab)
			return (NULL);
	}   */
		return (0);
	newstr = malloc(sizeof(char) * (ft_strlen(str) + ft_strlen(tab) + 1));
	if (!newstr)
		return (NULL);
	while (str[i] != 0)
		newstr[i++] = str[j++];
	j = 0;
	while (tab[i] != 0)
		newstr[i++] = tab[j++];
	newstr[i] = 0;
	free(str);
	//neden???
	return (newstr);
}

char	*ft_get_line(char *str)
{
	int		i;
	int		idx;
	char	*newline;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	newline = malloc(sizeof(char) * i + 2);
	if (!newline)
		return (0);
	idx = 0;
	while (str[idx] && str[idx] != '\n')
	{
		newline[idx] = str[idx];
		idx++;
	}
	if (str[idx] == '\n')
		newline[idx] = '\n';
	idx++;
	newline[idx] = 0;
	return (newline);
}

char	*ft_strchr(char *str, int c)
{
	int	idx;

	if (!str)
		return (0);
	idx = 0;
	if (c == '\0')
		return (NULL);
	while (str[idx] != 0)
	{
		if (str[idx] == c)
			return (&str[idx]);
		idx++;
	}
	return (0);
}

char	*ft_get_the_lastline(char *str)
{
	char	*newline;
	int		previous;
	int		all;
	int		i;

	previous = 0;
	while (str[previous] && str[previous] != '\n')
		previous++;
	if (!str[previous])
	{
		free(str);
		return (NULL);
	}
	all = ft_strlen(str);
	newline = malloc(sizeof(char) * (all - previous + 1));
	if (!newline)
		return (NULL);
	previous++;
	i = 0;
	while (str[previous])
		newline[i++] = str[previous++];
	newline[i] = 0;
	free(str);
	return (newline);
}
