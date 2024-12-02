/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 23:10:26 by vgoyzuet          #+#    #+#             */
/*   Updated: 2024/12/02 16:29:51 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*char	*update_buffer(char *pre_line)
{
	char *next_line;

	next_line = ft_strchr(pre_line, '\n');
	if (!line)
		return (free(next_line), NULL);
	return(next_line);
}*/

char	*clean_line(char *pre_line)
{
	char *line;

	line = ft_strchr(pre_line, '\n');
	if (!line)
		return (free(line), NULL);
	return(line);
}

char	*read_line(int fd, char *pre_line)
{
	ssize_t	byte;
	char	*buffer;

	byte = 1;
	buffer = malloc(sizeof(char *) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(pre_line, '\n') && byte != 0)
	{
		byte = read(fd, buffer, BUFFER_SIZE);
		if (byte == 0)
			break ;
		if (byte == -1)
			return (free(buffer), free (pre_line), NULL);
		buffer[byte] = '\0';
		pre_line = ft_strjoin(pre_line, buffer);
		if (!pre_line)
			return (free(buffer), NULL);
	}
	return (free(buffer), pre_line);
}

char	*get_next_line(int fd)
{
	static char	*line = NULL;
	char		*pre_line;

	pre_line = NULL;
	pre_line = read_line(fd, pre_line);
	line = clean_line(pre_line);
	return (line);
}
