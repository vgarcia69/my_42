/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgarcia <vgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:32:29 by vgarcia           #+#    #+#             */
/*   Updated: 2025/01/17 08:37:37 by vgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	here_loop(char *limiter, int fd_pipe[2])
{
	char	*str;

	while (1)
	{
		str = get_next_line(0);
		if (str == NULL)
		{
			close(fd_pipe[0]);
			close(fd_pipe[1]);
			error(12, "Gnl failed");
		}
		if (ft_strncmp (limiter, str, ft_strlen(limiter)) == 0
			&& str[ft_strlen(limiter)] == '\n')
			break ;
		ft_putstr_fd(str, fd_pipe[1]);
		free(str);
	}
	close(fd_pipe[0]);
	close(fd_pipe[1]);
	free(str);
}

void	here_doc(char *limiter)
{
	pid_t	pid;
	int		fd_pipe[2];

	if (pipe(fd_pipe) == -1)
		return (error(1, "Pipe"));
	pid = fork();
	if (pid == -1)
		return (close(fd_pipe[0]), close(fd_pipe[1]), error(1, "Fork"));
	if (pid == 0)
	{
		here_loop(limiter, fd_pipe);
		exit (0);
	}
	waitpid(pid, NULL, 0);
	if (dup2(fd_pipe[0], STDIN_FILENO) == -1)
		return (close(fd_pipe[1]), error(1, "dup2 failed"));
	close(fd_pipe[1]);
	close(fd_pipe[0]);
}
