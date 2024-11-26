/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 23:34:47 by vgoyzuet          #+#    #+#             */
/*   Updated: 2024/11/26 21:01:47 by vgoyzuet         ###   ########.fr       */
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
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			return (perror("Error al abrir el archivo"), 1);
	}
	while (*(line = get_next_line(fd)) != '\n')
	{
		printf("%s", line);
		free(line);
	}
	if (line == NULL)
	{
		if (fd != fileno(stdin))
			close(fd);
		printf("Fin de entrada alcanzado.\n");
	}
	return (0);
}
