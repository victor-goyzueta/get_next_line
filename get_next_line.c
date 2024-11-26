/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 23:10:26 by vgoyzuet          #+#    #+#             */
/*   Updated: 2024/11/26 01:13:15 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *buffer_read(fd)
{
    //
}

static  *line_read(fd, line)
{
    if (!line)
        malloc(1);
        line = "";
    while (ft_strchr(line, '\n'))
        read(fd, *buffer_read, BUFFER_SIZE);
}

char	*get_next_line(int fd)
{
    char    *line;
    
    line_read(fd);
    return (line_read);
}
