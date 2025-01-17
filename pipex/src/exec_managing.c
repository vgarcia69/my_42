/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_managing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgarcia <vgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:29:46 by vgarcia           #+#    #+#             */
/*   Updated: 2025/01/15 12:25:01 by vgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	exec_shell(char *av, char **env)
{
	char	**cmd;
	char	*path;

	cmd = ft_split_quote(av, ' ');
	if (cmd == NULL)
		return (error(127, "Command not found"));
	path = check_cmd(cmd[0], env);
	if (path == NULL)
		return (free_tab(cmd), error(127, "Command not found"));
	if (execve(path, cmd, env) == -1)
		return (free_tab(cmd), free(path), error(127, "Command not found"));
}

void	cmd_pipe(char *av, char **env)
{
	pid_t	pid;
	int		fd_pipe[2];

	if (pipe(fd_pipe) == -1)
		return (error(1, "Pipe"));
	pid = fork();
	if (pid == -1)
		return (close(fd_pipe[0]), close(fd_pipe[1]), error(1, "Fork"));
	else if (pid == 0)
	{
		close(fd_pipe[0]);
		if (dup2(fd_pipe[1], STDOUT_FILENO) == -1)
			return (close(fd_pipe[1]), error(1, "Dup2 failed"));
		close(fd_pipe[1]);
		exec_shell(av, env);
	}
	waitpid(pid, NULL, 0);
	close(fd_pipe[1]);
	if (dup2(fd_pipe[0], STDIN_FILENO) == -1)
		return (close(fd_pipe[0]), error(1, "Dup2 failed"));
	close(fd_pipe[0]);
}

void	cmd_outfile(int outfile, char *av, char **env)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return (close(outfile), error(1, "Fork"));
	else if (pid == 0)
		exec_shell(av, env);
	waitpid(pid, NULL, 0);
}
