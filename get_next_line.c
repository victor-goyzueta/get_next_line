/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 23:10:26 by vgoyzuet          #+#    #+#             */
/*   Updated: 2024/12/02 14:40:17 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	clean_lines(char **read_line, char **line)
{
	size_t	len;

	len = ft_strlen(read_line[0]);
	while (!ft_strchr(read_line[0], '\n'));
	line[0] = ft_substr(read_line[0], 0, len);
	
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
		// if (byte == -1)
		//	return (free(buffer), free (line), NULL);
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

	pre_line = read_line(fd, pre_line);
	clean_lines(&pre_line, &line);
	return (line);
}
