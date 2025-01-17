/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgarcia <vgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 08:37:15 by vgarcia           #+#    #+#             */
/*   Updated: 2025/01/17 11:32:42 by vgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	setup_outfile(t_fd *fd, char **av, char *t)
{
	int	i;

	i = 0;
	while (av[i + 1])
		i++;
	if (t)
		fd->outfile = open(av[i], O_APPEND | O_CREAT | O_WRONLY, 0777);
	else
		fd->outfile = open(av[i], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (fd->outfile == -1)
		error(1, "Invalid outfile");
	if (dup2(fd->outfile, STDOUT_FILENO) == -1)
		error(1, "dup2 failed");
	close(fd->outfile);
}

static int	setup_infile(t_fd *fd, char **av)
{
	int	fd_error[2];

	fd->infile = open(av[0], O_RDONLY);
	if (fd->infile == -1)
	{
		ft_putstr_fd("Error : Invalid infile\n", 2);
		if (pipe(fd_error) == -1)
			error(1, "Pipe");
		if (dup2(fd_error[0], STDIN_FILENO) == -1)
		{
			close(fd_error[1]);
			error(1, "dup2 failed");
		}
		close(fd_error[0]);
		close(fd_error[1]);
		return (-1);
	}
	if (dup2(fd->infile, STDIN_FILENO) == -1)
		error(1, "dup2 failed");
	close(fd->infile);
	return (0);
}

void	program(char **av, char **env)
{
	t_fd	fd;
	char	*limiter;
	int		i;

	i = 0;
	limiter = NULL;
	if (ft_strncmp("here_doc", av[0], 9) == 0)
	{
		limiter = av[++i];
		here_doc(limiter);
	}
	else if (setup_infile(&fd, av) == -1)
		++i;
	while (av[++i + 2])
		cmd_pipe(av[i], env);
	setup_outfile(&fd, av, limiter);
	cmd_outfile(fd.outfile, av[i], env);
	wait(NULL);
}

int	main(int ac, char **av, char **env)
{
	if (ac < 5)
		return (error(127, "Wrong amount of arguments."), -1);
	program(&av[1], env);
	return (0);
}
