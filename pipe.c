/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:54:03 by agrenon           #+#    #+#             */
/*   Updated: 2022/02/25 17:22:26 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_pipe.h"

void	ft_err_message(void)
{
	ft_print_cmd("\nERREUR: Mauvais nombre d'arguments");
	ft_print_cmd(" ou fichier invalide !\n");
	ft_print_cmd("\n- UTILISEZ: ./pipex input_text.txt ");
	ft_print_cmd("CMD CMD output_text.txt\n");
	ft_print_cmd("\n- VERIFIER : input_text.txt est valide\n");
	ft_print_cmd("             CMD est existante\n\n");
	return ;
}

void	ft_no_cmd(char *argv, char **argvec)
{
	ft_print_cmd("\nERREUR: COMMANDE -> ");
	ft_print_cmd(argv);
	ft_print_cmd(" <- NON TROUVÉE\n\n");
	if (argvec)
		free(argvec);
	return ;
}

int	main(int argc, char **argv, char **env)
{
	char	*cmd;
	char	**argvec;

	if (argc != 5 || access(argv[1], F_OK) == -1)
	{
		ft_err_message();
		return (0);
	}
	argvec = malloc(sizeof(size_t) * 4);
	cmd = ft_prep_cmd(argvec, env, argv[2], argv[1]);
	if (!cmd)
	{
		ft_no_cmd(argv[2], argvec);
		return (0);
	}
	ft_forknpipe(argv, cmd, argvec, env);	
	if (cmd)
		free(cmd);
	if (argvec && argvec[2])
		free(argvec[1]);
	free(argvec);
	return (0);
}
