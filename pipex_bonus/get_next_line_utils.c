/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@student.42quebec.>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 18:45:06 by agrenon           #+#    #+#             */
/*   Updated: 2022/03/07 15:52:24 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lib_pipe.h"

char	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;

	ptr = malloc(size * count);
	if (ptr == 0)
		return (0);
	i = 0;
	while (i < size * count)
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (0);
	i = start;
	if (start >= (ft_strlen(s)))
		return (str);
	while (s[i] && j < len)
	{
		str[j] = s[i];
		j++;
		i++;
	}
	return (str);
}

size_t	ft_strlcpy(char *dst, char *src, size_t dsize)
{
	size_t	i;

	i = 0;
	if (dsize <= 0 || !src)
		return (0);
	while (src[i] && i < dsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = ft_strlen(dst);
	j = 0;
	k = i;
	if (dstsize <= 0)
		return (ft_strlen(src));
	if (ft_strlen(dst) >= dstsize)
		return (ft_strlen(src) + dstsize);
	while (i < dstsize - 1 && src[j])
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	dst[i] = '\0';
	return (k + ft_strlen(src));
}
