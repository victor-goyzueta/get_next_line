/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:25:37 by vgoyzuet          #+#    #+#             */
/*   Updated: 2024/12/05 18:54:58 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	all_read( int *fd_finish, int argn)
{
	while(argn--)
	{
		if (fd_finish[argn] == 0)
			return (0);
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	int		fd[argc - 1];
	int		fd_finish[argc - 1];
	char	*line;
	int     i;

	i = 0;
	while (i < (argc - 1))
	{
		fd[i] = open(argv[i + 1], O_RDONLY);
		if (fd[i] == -1)
			return (perror("Error opening the file"), 1);
		fd_finish[i] = 0;
		i++;
	}
	while (1)
	{
		i = 0;
		while (i < argc - 1)
		{
			line = get_next_line(fd[i]);
			if (line)
				printf("file [%i] line: %s", fd[i], line);
			else
				fd_finish[i] = 1;
			free(line);
			i++;
		}
		if (all_read(fd_finish, argc - 1))
			break ;
	}
	i = 0;
	while (i < argc - 1)
	{
		if (close(fd[i]) == -1)
			return (perror("Error closing the file"), 1);
		i++;
	}
	return (0);
}
