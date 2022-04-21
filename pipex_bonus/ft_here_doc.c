/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:04:09 by agrenon           #+#    #+#             */
/*   Updated: 2022/03/08 10:50:38 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_pipe.h"

int	ft_memcmp(char *s1, char *s2)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;
	size_t			n;

	n = ft_strlen(s1);
	if (n < ft_strlen(s2))
			n = ft_strlen(s2);
	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

char	*ft_magic_join(char *magic_mush, char *strline)
{
	size_t	len;
	char	*temp;
	size_t	i;
	int		j;

	j = 0;
	i = 0;
	len = ft_strlen(magic_mush) + ft_strlen(strline);
	temp = malloc(sizeof(char) * len + 1);
	while (i < ft_strlen(magic_mush))
		temp[i++] = magic_mush[j++];
	j = 0;
	while (i < len)
		temp[i++] = strline[j++];
	temp[i] = '\0';
	if (magic_mush)
		free(magic_mush);
	if (strline)
		free(strline);
	return (temp);
}

void	ft_pipe_here(char *magic_mush, char *strline, bool *is_here_doc)
{
	int		files[2];

	*is_here_doc = true;
	dup(0);
	pipe(files);
	write(files[1], magic_mush, ft_strlen(magic_mush));
	dup2(files[0], 0);
	close(files[0]);
	close(files[1]);
	if (magic_mush)
		free(magic_mush);
	if (strline)
		free(strline);
	return ;
}

int	ft_here_doc(char **argv, bool *is_here_doc)
{
	char	*strline;
	char	*magic_mush;
	int		i;

	i = 0;
	magic_mush = NULL;
	strline = NULL;
	if (!ft_memcmp("here_doc", argv[1]))
	{
		while (1)
		{
			strline = get_next_line(0);
			if (ft_memcmp(strline, argv[2]) == 10)
			{
				ft_pipe_here(magic_mush, strline, is_here_doc);
				i = 1;
				break ;
			}
			magic_mush = ft_magic_join(magic_mush, strline);
		}
	}
	else if (open(argv[1], O_RDONLY) == -1)
		ft_perror(0, NULL, NULL);
	return (i);
}
