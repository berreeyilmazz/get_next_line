/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: havyilma <havyilma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 05:05:27 by havyilma          #+#    #+#             */
/*   Updated: 2022/11/12 05:15:56 by havyilma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main()
{
	char *metin;
	int fd = open("deneme.txt", O_CREAT | O_RDWR, 0777);

	metin = get_next_line(fd);
	while (metin)
	{
		printf("%s", metin);
		free(metin);
		metin = get_next_line(fd);
	}
}
