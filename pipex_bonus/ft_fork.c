/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:24:13 by agrenon           #+#    #+#             */
/*   Updated: 2022/03/07 17:06:11 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_pipe.h"

void	ft_print_cmd(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	return ;
}

int	ft_find_env(char **env)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (env[i])
	{
		while (env[i][j] == ENV[j])
			j++;
		if (j == 5)
			break ;
		j = 0;
		i++;
	}
	return (i);
}

char	*ft_prep_cmd(char **argVec, char **env, char *argv)
{
	int		count;
	char	*flag[1];
	char	*cmd;

	argVec[0] = NULL;
	argVec[1] = NULL;
	flag[0] = NULL;
	count = ft_find_env(env);
	cmd = ft_make_cmd(argv, flag);
	cmd = ft_give_path(cmd, env[count]);
	count = 0;
	argVec[count++] = cmd;
	if (flag[0])
		argVec[count++] = flag[0];
	argVec[count] = NULL;
	return (cmd);
}

void	ft_execute_me(char **argvec, char **env, char *cmd, int i)
{
	int		fk;

	fk = fork();
	if (fk == 0)
	{
		if (i == 2)
		{
			dup2(3, 0);
			dup2(5, 1);
		}
		else if (i != 0)
			dup2(5, 1);
		else
			dup2(6, 1);
		if (execve(cmd, argvec, env) == -1)
			ft_perror(1, argvec, cmd);
	}
	dup2(4, 0);
	close(5);
	close(4);
	ft_free_argvec(argvec, cmd);
	return ;
}

char	*ft_command(char **argv, char **argvec, char **env, int i)
{
	char	*cmd;

	cmd = NULL;
	if (i == 2)
		cmd = ft_prep_cmd(argvec, env, argv[i]);
	else
		cmd = ft_prep_cmd(argvec, env, argv[i]);
	if (!cmd)
		ft_no_cmd(argv[i], argvec);
	return (cmd);
}
