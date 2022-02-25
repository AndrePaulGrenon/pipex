#include "lib_pipe.h"

void	ft_no_cmd(char **argv)
{
	ft_print_cmd("\nERREUR: COMMANDE -> ");
	ft_print_cmd(argv[2]);
	ft_print_cmd(" <- NON TROUVÉE\n");
	return ;
}

int main(int argc, char **argv, char **env)
{
	char	*cmd;
	char	*argVec[4];
	
	if (argc <= 3 || access(argv[1], F_OK) == -1)
	{
		ft_print_cmd("\nERREUR: Pas assez d'arguments ou fichier invalide !\n");
		return (0);
	}
	cmd = ft_prep_cmd(argVec, env, argv[2], argv[1]);
	if (!cmd )
	{
		ft_no_cmd(argv);
		return(0);
    }

	if (argVec[2])
		printf("Argvec0 :%s Argv1  %s  Arg2 %s \n",argVec[0], argVec[1], argVec[2]);
	else
		printf("Argvec0 :%s Argv1  %s  \n",argVec[0], argVec[1]);

	ft_forknpipe(argv, cmd, argVec, env);
	
	
	if(cmd)
		free(cmd);
	if (argVec[2])
		free(argVec[1]);
	return (0);
}
