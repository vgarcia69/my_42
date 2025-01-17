/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_access_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgarcia <vgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:32:33 by vgarcia           #+#    #+#             */
/*   Updated: 2025/01/15 09:42:47 by vgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static int	find_path_line(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp("PATH", env[i], 4))
			break ;
		++i;
	}
	return (i);
}

static char	**join_cmd(char **all_paths, char *cmd)
{
	char	**all_cmd;
	int		i;

	i = 0;
	while (all_paths[i] != NULL)
		++i;
	all_cmd = malloc(sizeof(char *) * (i + 1));
	if (all_cmd == NULL)
		return (free_tab(all_paths), NULL);
	i = 0;
	while (all_paths[i] != NULL)
	{
		all_cmd[i] = ft_strjoin(all_paths[i], cmd);
		if (!all_cmd[i])
			return (free_tab(all_paths), free(all_cmd), NULL);
		++i;
	}
	all_cmd[i] = NULL;
	free_tab(all_paths);
	return (all_cmd);
}

static int	choose_path(char **all_paths, char **path)
{
	int	i;

	i = 0;
	while (all_paths[i] != NULL)
	{
		if (access(all_paths[i], X_OK) == 0)
		{
			*path = ft_strjoin("", all_paths[i]);
			if (!*path)
				return (-1);
			return (0);
		}
		++i;
	}
	return (1);
}

char	*check_cmd(char *cmd, char **env)
{
	char	*path;
	char	**all_paths;

	if (!cmd)
		return (NULL);
	path = NULL;
	all_paths = ft_split(&env[find_path_line(env)][5], ':');
	if (!all_paths)
		return (NULL);
	all_paths = join_cmd(all_paths, "/");
	if (!all_paths)
		return (NULL);
	all_paths = join_cmd(all_paths, cmd);
	if (!all_paths)
		return (NULL);
	choose_path(all_paths, &path);
	free_tab(all_paths);
	return (path);
}
