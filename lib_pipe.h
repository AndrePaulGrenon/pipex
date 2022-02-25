/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_pipe.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 11:58:59 by agrenon           #+#    #+#             */
/*   Updated: 2022/02/25 16:32:16 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_PIPE_H
# define LIB_PIPE_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdlib.h>

# define ENV "PATH="

int		ft_strlen(char	*str);
int		ft_find_env(char **env);
void	ft_print_cmd(char *str);
char	*ft_give_path(char *cmd, char	*env);
char	*ft_calloc(char *str, int i, int a);
void	ft_no_cmd(char *argv, char **argvec);
char	*ft_make_cmd(char	*str, char **flag);
char	*ft_prep_cmd(char **argVec, char **env, char *argv, char *fichier);
void	ft_forknpipe(char **argv, char *cmd, char **argVec, char **env);

#endif
