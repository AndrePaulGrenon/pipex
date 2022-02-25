/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:24:13 by agrenon           #+#    #+#             */
/*   Updated: 2022/02/25 17:37:42 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_pipe.h"

void	ft_print_cmd(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
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

char	*ft_prep_cmd(char **argVec, char **env, char *argv, char *fichier)
{
	int		count;
	char	*flag[1];
	char	*cmd;

	count = ft_find_env(env);
	flag[0] = NULL;
	cmd = ft_make_cmd(argv, flag);
	cmd = ft_give_path(cmd, env[count]);
	count = 0;
	argVec[count++] = cmd;
	if (flag[0])
		argVec[count++] = flag[0];
	if (fichier)
		argVec[count++] = fichier;
	argVec[count] = NULL;
	return (cmd);
}

void	ft_execute_me(int *files, char **argVec, char **env, char *arg)
{
	char	*cmd;

	cmd = NULL;
	close (files[1]);
	dup2(files[0], 0);
	cmd = ft_prep_cmd(argVec, env, arg, 0);
	if (!cmd)
	{
		dup2(6, 1);
		free(argVec[0]);
		free(argVec[1]);
		ft_no_cmd(arg, argVec);
		exit(0);
	}	
	execve(cmd, argVec, env);
	return ;
}

void	ft_forknpipe(char **argv, char *cmd, char **argVec, char **env)
{
	int		fk0;
	int		fk1;
	int		files[2];

	pipe(files);
	fk0 = fork();
	if (fk0 == 0)
	{
		dup2(files[1], 1);
		execve(cmd, argVec, env);
	}
	fk1 = fork();
	if (fk1 == 0)
	{
		fk1 = open(argv[4], O_WRONLY | O_CREAT, 0777);
		dup(1);
		dup2(fk1, 1);
		ft_execute_me(files, argVec, env, argv[3]);
	}
	close (files[0]);
	close (files[1]);
	waitpid(fk1, NULL, 0);
	waitpid(fk0, NULL, 0);
	return ;
}
