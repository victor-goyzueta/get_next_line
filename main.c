/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 23:34:47 by vgoyzuet          #+#    #+#             */
/*   Updated: 2024/12/04 19:10:12 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argc, char *argv[])
{
	int		fd;
	char	*line;

	if (argc < 2)
		fd = fileno(stdin);
	else
	{
		fd = open("file.txt", O_RDONLY);
		if (fd == -1)
			return (perror("Error al abrir el archivo"), 1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	if (fd != fileno(stdin))
		if(close(fd) == -1)
			return (perror("Error al cerrar el archivo"), 1);
	return (0);
}
