/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 23:10:26 by vgoyzuet          #+#    #+#             */
/*   Updated: 2024/12/02 19:28:32 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*update_line(char *pre_line)
{
	char	*next_line;
	char	*tmp;

	tmp = ft_strchr(pre_line, '\n');
	next_line = ft_substr(tmp, 1, ft_strlen(tmp));
	return (free(pre_line), next_line);
}

char	*clean_line(char *pre_line)
{
	//return (line);
}

char	*read_line(int fd, char *pre_line)
{
	ssize_t	byte;
	char	*buffer;

	buffer = malloc(sizeof(char *) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	byte = 1;
	while (!ft_strchr(pre_line, '\n') && byte != 0)
	{
		byte = read(fd, buffer, BUFFER_SIZE);
		if (byte == 0)
			break ;
		if (byte == -1)
			return (free(buffer), free(pre_line), NULL);
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
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	pre_line = read_line(fd, pre_line);
	if (!pre_line)
		return (NULL);
	line = clean_line(pre_line);
	pre_line = update_line(pre_line);
	return (free(pre_line), line);
}
