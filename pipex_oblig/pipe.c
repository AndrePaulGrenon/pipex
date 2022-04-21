/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:54:03 by agrenon           #+#    #+#             */
/*   Updated: 2022/03/07 17:10:58 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_pipe.h"

void	ft_free_argvec(char **argvec, char *cmd)
{
	if (argvec)
	{
		if (argvec[0])
		{
			free(argvec[0]);
			cmd = NULL;
		}
		if (argvec[1])
			free(argvec[1]);
		free (argvec);
	}
	if (cmd)
		free (cmd);
	return ;
}

void	ft_perror(int i, char **argvec, char *cmd)
{
	if (i == 0)
		perror("open");
	else if (i == 1)
		perror("execve");
	ft_free_argvec(argvec, cmd);
	exit(-1);
	return ;
}

void	ft_err_message(void)
{	
	ft_print_cmd("\n Erreur: Mauvais nombre d'arguments\n");
	ft_print_cmd("\n- UTILISEZ: ./pipex input_text.txt ");
	ft_print_cmd("CMD CMD output_text.txt\n\n");
	exit(0);
	return ;
}

void	ft_no_cmd(char *argv, char **argvec)
{
	ft_print_cmd("\nERREUR: COMMANDE -> ");
	ft_print_cmd(argv);
	ft_print_cmd(" <- NON TROUVÉE\n");
	ft_print_cmd("\n Veuillez entrer une commande valide\n\n");
	ft_free_argvec(argvec, NULL);
	exit(0);
	return ;
}

int	main(int argc, char **argv, char **env)
{
	int		i;
	int		files[2];

	if (argc != 5)
		ft_err_message();
	i = 2;
	if (open(argv[1], O_RDONLY) == -1)
		ft_perror(0, NULL, NULL);
	while (i < argc - 1)
	{
		pipe(files);
		if (i == argc - 2)
		{
			if (open(argv[argc -1], O_RDWR | O_CREAT | O_TRUNC, 0777) == -1)
				ft_perror(0, NULL, NULL);
			ft_pipe_loop(argv, env, i, 0);
			break ;
		}
		ft_pipe_loop(argv, env, i, 1);
		i++;
	}
	return (0);
}
