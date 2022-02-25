/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_give_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:12:51 by agrenon           #+#    #+#             */
/*   Updated: 2022/02/24 17:17:44 by agrenon          ###   ########.fr       */
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
	printf("FULL PATH MAKING : %s\n", temp);
	return (temp);
}

char	*ft_give_path(char *cmd, char *env)
{
	int		i;
	int		start;
	char	*full_path;

	i = 5;
	start = i;
	while (env[i])
	{
		if (env[i] == ':')
		{
			full_path = ft_path(cmd, start, i - start, env);
			if (access(full_path, F_OK) == 0)
			{
				free(cmd);
				printf("FULL PATH found: %s\n", full_path);
				return (full_path);
			}
			free(full_path);
			printf(" Access not found\n");
			start = i + 1;
		}	
		i++;
	}
	free(cmd);
	return (0);
}
