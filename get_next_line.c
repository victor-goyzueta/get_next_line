/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 23:10:26 by vgoyzuet          #+#    #+#             */
/*   Updated: 2024/11/26 21:01:12 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*line_read(fd)
{
	char		*buffer_;
	ssize_t		bytes_read;

	buffer_ = malloc(BUFFER_SIZE + 1);
	{
		if (!buffer_)
			return (NULL);
	}
	bytes_read = read(fd, buffer_, BUFFER_SIZE);
	buffer_[bytes_read] = '\0';
	return(buffer_);
}

char	*get_next_line(int fd)
{
	char	*line;

	line = line_read(fd);
	return (line);
}
