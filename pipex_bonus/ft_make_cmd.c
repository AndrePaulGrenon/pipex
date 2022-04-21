/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:42:05 by agrenon           #+#    #+#             */
/*   Updated: 2022/03/07 17:07:09 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_pipe.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_pipe_loop(char **argv, char **env, int i, int at)
{
	char	*cmd;
	char	**argvec;

	if (at)
		at = i;
	argvec = malloc(sizeof(size_t) * 3);
	cmd = ft_command(argv, argvec, env, i);
	ft_execute_me(argvec, env, cmd, at);
	return ;
}

char	*ft_calloc_cmd(char *str, int c, int a)
{
	char	*str1;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(str) - a;
	str1 = malloc(len * sizeof(char) + 1);
	while (i < len + 1)
	{
		str1[i] = str[c];
		i++;
		c++;
	}
	str1[len] = '\0';
	return (str1);
}

char	*ft_make_cmd(char *str, char **flag_tab)
{
	int		a;
	int		i;
	char	*cmd;

	i = 0;
	a = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == ' ')
			a = i;
		i++;
	}
	if (a > 0)
		cmd = ft_calloc_cmd(str, 0, ft_strlen(str) - a);
	else
		cmd = ft_calloc_cmd(str, 0, 0);
	if (a > 0)
		flag_tab[0] = ft_calloc_cmd(str, a + 1, a);
	return (cmd);
}
