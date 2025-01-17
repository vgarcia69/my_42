/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgarcia <vgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 08:37:40 by vgarcia           #+#    #+#             */
/*   Updated: 2025/01/15 09:38:23 by vgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>

typedef struct s_fd
{
	int	infile;
	int	outfile;
}	t_fd;

void	error(int status, char *s);
void	cmd_pipe(char *av, char **env);
void	cmd_outfile(int outfile, char *av, char **env);
char	*check_cmd(char *cmd, char **env);
void	exec_shell(char *av, char **env);

char	**ft_split_quote(char *str, char c);
void	here_doc(char *limiter);
int		is_valid_quote(char *str);
char	*cut_quote(char *str);
#endif
