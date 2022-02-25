#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdlib.h>

#ifndef LIB_PIPE
# define LIB_PIPE

#define ENV "PATH"

int		ft_strlen(char	*str);
int		ft_find_env(char **env);
void	ft_print_cmd(char *str);
char	*ft_give_path(char *cmd, char	*env);
char	*ft_calloc(char *str, int	i, int	a);
char	*ft_make_cmd(char	*str, char **flag);
char	*ft_prep_cmd(char **argVec, char **env, char *argv, char *fichier);
void	ft_forknpipe(char **argv, char *cmd, char **argVec, char **env);

#endif
