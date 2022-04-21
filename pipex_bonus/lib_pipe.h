/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_pipe.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrenon <agrenon@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 11:58:59 by agrenon           #+#    #+#             */
/*   Updated: 2022/03/07 16:46:18 by agrenon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_PIPE_H
# define LIB_PIPE_H

# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <errno.h>
# include <stddef.h>
# include <limits.h>
# include <stdbool.h>

# define BUFFER_SIZE 1
# define ENV "PATH="

void	ft_perror(int i, char **argvec, char *cmd);
char	*ft_calloc(size_t count, size_t size);
char	*ft_substr(char *s, unsigned int start, size_t len);
void	ft_err_message(void);
void	ft_pipe_loop(char **argv, char **env, int i, int at);
size_t	ft_strlcpy(char *dst, char *src, size_t dsize);
size_t	ft_strlcat(char *dst, char *src, size_t dstsize);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
int		ft_here_doc(char **argv, bool *is_here_doc);
size_t	ft_strlen(char	*str);
int		ft_find_env(char **env);
void	ft_print_cmd(char *str);
void	ft_free_argvec(char **argvec, char *cmd);
char	*ft_command(char **argv, char **argvec, char **env, int i);
void	ft_execute_me(char	**argvec, char **env, char *cmd, int i);
char	*ft_give_path(char *cmd, char	*env);
char	*ft_calloc_cmd(char *str, int i, int a);
void	ft_no_cmd(char *argv, char **argvec);
char	*ft_make_cmd(char	*str, char **flag);
char	*ft_prep_cmd(char **argVec, char **env, char *argv);

#endif
