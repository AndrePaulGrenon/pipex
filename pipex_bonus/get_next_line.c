/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 18:19:08 by agrenon           #+#    #+#             */
/*   Updated: 2022/03/03 12:01:43 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_pipe.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;

	str = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!str)
		return (0);
	(void) ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	(void) ft_strlcat(str, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	if (str[0] == '\0')
	{
		free(str);
		return (0);
	}
	return (str);
}

static char	*make_this_string_happen(int fd, char *str, ssize_t *err)
{
	int		read_numb;
	char	*new_str;
	char	*temp;

	new_str = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	read_numb = read(fd, new_str, BUFFER_SIZE);
	if (read_numb == -1)
	{
		*err = -1;
		free(new_str);
		return (0);
	}
	temp = ft_strjoin(str, new_str);
	return (temp);
}

static char	*ft_the_answer(char *temp, char **my_tab, ssize_t i, int fd)
{
	char	*next_line;

	if (temp[0] == '\0')
	{
		free(temp);
		return (0);
	}
	next_line = ft_substr(temp, 0, i + 1);
	my_tab[fd] = ft_substr(temp, i + 1, ft_strlen(&temp[i + 1]));
	free(temp);
	return (next_line);
}

char	*get_next_line(int fd)
{
	static char	*tab_of_str[OPEN_MAX];
	char		*temp;
	ssize_t		i;

	i = 0;
	temp = tab_of_str[fd];
	if (!tab_of_str[fd])
		temp = make_this_string_happen(fd, tab_of_str[fd], &i);
	if (i == -1 || !temp)
		return (0);
	while (temp[i] != '\n')
	{
		if (temp[i] == '\0')
			temp = make_this_string_happen(fd, temp, &i);
		if (!temp || temp[i] == '\0' || temp[i] == '\n')
			break ;
		i++;
	}
	if (!temp || temp[0] == '\0' || i == -1)
		return (0);
	return (ft_the_answer(temp, tab_of_str, i, fd));
}
