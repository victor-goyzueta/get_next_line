/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 23:34:47 by vgoyzuet          #+#    #+#             */
/*   Updated: 2024/12/05 18:58:44 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main()
{
	int		fd;
	char	*line;

	fd = open("file1.txt", O_RDONLY);
	if (fd == -1)
		return (perror("Error opening the file"), 1);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	if (close(fd) == -1)
		return (perror("Error closing the file"), 1);
	return (0);
}
