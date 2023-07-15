/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:05:56 by donglee2          #+#    #+#             */
/*   Updated: 2023/07/15 16:03:15 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	print_err(char *extracted_cmd)
{
	ft_putstr_fd("bash: ", STDERR_FILENO);
	ft_putstr_fd(extracted_cmd, STDERR_FILENO);
	ft_putstr_fd(": command not found\n", STDERR_FILENO);
}

static char	*chk_all_paths(char **split_path, char *extracted_cmd)
{
	int		i;
	char	*ret;

	i = -1;
	while (split_path[++i])
	{
		split_path[i] = add_cmd_to_path(split_path[i], extracted_cmd);
		if (!access(split_path[i], X_OK))
		{
			ret = ft_strdup(split_path[i]);
			if (!ret)
				exit(1);
			free_all_splits(split_path);
			return (ret);
		}
	}
	return (NULL);
}

char	*find_cmd_path(char *extracted_cmd, char **envp)
{
	char	*path;
	char	**split_path;
	char	*ret;

	path = find_path(envp);
	if (!path)
		exit(1);
	split_path = ft_split(path, ':');
	if (!split_path)
		exit (1);
	ret = chk_all_paths(split_path, extracted_cmd);
	if (ret)
		return (ret);
	print_err(extracted_cmd);
	exit(127);
}

char	*find_cmd_path_absolute_case(char *extracted_cmd)
{
	char	*cmd_path;

	if (!access(extracted_cmd, X_OK))
	{
		cmd_path = ft_strdup(extracted_cmd);
		if (!cmd_path)
			exit(1);
		return (cmd_path);
	}
	else
	{
		print_err(extracted_cmd);
		exit(127);
	}
}
