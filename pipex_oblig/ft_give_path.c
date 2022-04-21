/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_give_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:12:51 by agrenon           #+#    #+#             */
/*   Updated: 2022/03/07 13:58:33 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_pipe.h"

char	*ft_path(char *cmd, int start, int len, char *env)
{
	char	*temp;
	int		lenpath;
	int		i;
	int		j;

	lenpath = ft_strlen(cmd) + len + 1;
	temp = malloc(sizeof(char) * (lenpath + 2));
	i = 0;
	j = 0;
	while (i < len)
	{
		temp[i] = env[start];
		i++;
		start++;
	}
	temp[i++] = '/';
	while (i < lenpath)
		temp[i++] = cmd[j++];
	temp[lenpath] = '\0';
	return (temp);
}

char	*ft_give_path(char *cmd, char *env)
{
	int		i;
	int		start;
	char	*full_path;

	i = 5;
	start = i;
	if (access(cmd, F_OK) == 0)
		return (cmd);
	while (env[i])
	{
		if (env[i] == ':')
		{
			full_path = ft_path(cmd, start, i - start, env);
			if (access(full_path, F_OK) == 0)
			{
				free(cmd);
				return (full_path);
			}
			free(full_path);
			start = i + 1;
		}	
		i++;
	}
	free(cmd);
	return (0);
}
