/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berreyilmaz <berreyilmaz@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:40:25 by berreyilmaz       #+#    #+#             */
/*   Updated: 2022/11/19 15:25:04 by berreyilmaz      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t ft_strlen(char *s)
{
    size_t i;
    
    i = 0;
    while(*(s + i))
        i++;
    return (i);
}

int ft_check_nl(char *s)
{
    int i;
    
    i = 0;
    if (!s)
        return(0);
    while (*(s + i))
    {
        if (*(s + i) == '\n')
            return(0);
        i++;
    }
    return (1);
}

char    *ft_strjoin(char *s1, char *s2)
{
    size_t  k;
    size_t  i;
    char    *newstr;

    if (!s1)
    {
        s1 = malloc(sizeof(char) * 1);
        s1[0] = '\0';
    }
    if (!s1 || !s2)
        return (0);
    newstr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
    if (!newstr)
        return (0);
    i = 0;
    k = 0;
    while(*(s1 + i++))
        *(newstr + k++) = *(s1 + i);
    i = 0;
    while(*(s2 + i++))
        *(newstr + k++) = *(s2 + i);
    *(newstr + k) = '\0';
    free(s1);
    return (newstr);
}

char    *ft_newline(char *str)
{
    int     i;
    int     k;
    char    *line;

    i = 0;
    if(!*str || !str)
        return (0);
    while (*(str + i) && *(str + i) != '\n')
       i++;
    line = malloc(sizeof(char) * (i + 2));
    if (!line)
        return (0);
    k = 0;
    while (*(str + k) != '\n' && *(str + k) && k <= i)
    {
        *(line + k) = *(str + k);
        k++;
    }   
    if (*(str + k) == '\n')
        *(line + k++) = '\n';
    *(line + k) = '\0';
    return(line);
}

char    *ft_reststr(char *str)
{
    int     i;
    int     k;
    int     howlong;
    char    *newrest;

    howlong = ft_strlen(str);
    i = 0;
    while (*(str + i) && *(str + i) != '\n')
       i++;
    if (!*(str + i))
    {
        free (str);
        return (0);
    }
    newrest = malloc(sizeof(char) * (howlong - i + 1));
    if (!newrest)
        return (0);
    k = 0;
    while (*(str + i))
        *(newrest + k++) = *(str + i++);
    *(newrest + k) = 0;
    free(str);
    return (newrest);
}