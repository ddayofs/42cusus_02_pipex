/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 14:14:25 by donglee2          #+#    #+#             */
/*   Updated: 2023/07/15 15:56:16 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*extract_cmd(char *str)
{
	char	**split_str;
	char	*tmp;

	split_str = ft_split(str, ' ');
	if (!split_str)
		exit(1);
	tmp = ft_strdup(split_str[0]);
	if (!tmp)
		exit(1);
	free_all_splits(split_str);
	return (tmp);
}

char	*find_path(char **envp)
{
	while (*envp)
	{
		if (*(*envp + 1) == 'A' && *(*envp + 2) == 'T')
			return (*envp + 5);
		envp++;
	}
	return (NULL);
}

char	*add_cmd_to_path(char *path, char *cmd)
{
	char	*tmp;

	tmp = ft_strjoin(path, "/");
	if (!tmp)
		exit(1);
	free(path);
	path = ft_strjoin(tmp, cmd);
	free (tmp);
	if (!path)
		exit(1);
	return (path);
}

void	free_all_splits(char **split_path)
{
	int	i;

	i = -1;
	while (split_path[++i])
		free(split_path[i]);
	free(split_path);
}
