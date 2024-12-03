/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 23:34:47 by vgoyzuet          #+#    #+#             */
/*   Updated: 2024/12/03 19:11:06 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main()
{
    int     fd;
    char *line;

    fd = open("file.txt", O_RDONLY);  // Abre el archivo en modo solo lectura
    if (fd == -1)  // Manejo de errores al abrir el archivo
    {
        perror("Error al abrir el archivo");
        return (1);
    }

    // Llamadas a get_next_line para leer el archivo línea por línea
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);  // Imprime la línea devuelta por get_next_line
        free(line);          // Libera la memoria asignada por get_next_line
    }

    // Cierra el archivo al finalizar
    if (close(fd) == -1)
    {
        perror("Error al cerrar el archivo");
        return (1);
    }

    return (0);  // Retorno exitoso
}
