/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoyzuet <vgoyzuet@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 23:33:35 by vgoyzuet          #+#    #+#             */
/*   Updated: 2024/12/03 19:48:37 by vgoyzuet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;
	if(!s)//UPDATE REVISAR NO HABÍA ESTA COMPROBACIÓN
		return(0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s && *s != (unsigned char)c)
		s++;
	if (*s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;

	d = (unsigned char *)dest;
	if (!dest && !src)
		return (dest);
	while (n--)
		*d++ = *(const unsigned char *)src++;
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	s1len;
	size_t	s2len;

	if (!s1 && !s2)//UPDATE REVISAR ANTES ERA ||
		return (NULL);
	s1len = ft_strlen((char *)s1);
	s2len = ft_strlen((char *)s2);
	s = malloc(sizeof(char) * ((s1len + s2len) + 1));
	if (!s)
		return (NULL);
	ft_memcpy(s, s1, s1len);
	ft_memcpy(s + s1len, s2, s2len);
	s[s1len + s2len] = '\0';
	free((char *)s1);
	return (s);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	copy_len;

	src_len = ft_strlen((char *)src);
	if (size > 0)
	{
		if (src_len >= size)
			copy_len = size - 1;
		else
			copy_len = src_len;
		ft_memcpy(dst, src, copy_len);
		dst[copy_len] = '\0';
	}
	return (src_len);
}

char	*ft_strdup(const char *s)
{
	char	*cpy;
	size_t	len;

	if (s == NULL)
		return (NULL);
	len = ft_strlen((char *)s) + 1;
	cpy = (char *)malloc(len);
	if (cpy == NULL)
		return (NULL);
	ft_strlcpy(cpy, s, len);
	return (cpy);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ss;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen((char *)s);
	if (start >= slen)
		return (NULL); //UPDATE ANTES ERA UN FT_STRDUP("");
	if (len > slen - start)
		len = slen - start;
	ss = (char *)malloc(len + 1);
	if (!ss)
		return (NULL);
	ft_strlcpy(ss, (const char *)s + start, len + 1);
	return (ss);
}
