/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_variable_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 12:07:05 by donglee2          #+#    #+#             */
/*   Updated: 2023/07/15 15:52:41 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	init_args(char *argv[], int argc, t_args *args)
{
	args->infile_name = argv[1];
	args->outfile_name = argv[argc - 1];
	args->argv = argv;
	args->idx = 1;
	args->argc = argc;
	args->bonus_flag = 0;
}

static char	*make_new_file_name(t_args *args)
{
	char	*new_name;
	char	*str_added;
	int		idx;

	idx = 0;
	new_name = ft_strdup(args->infile_name);
	if (!new_name)
		exit(1);
	while (!access(new_name, F_OK))
	{
		free(new_name);
		str_added = ft_itoa(idx);
		if (!str_added)
			exit(1);
		new_name = ft_strjoin(args->infile_name, str_added);
		if (!new_name)
			exit(1);
		free(str_added);
		idx++;
	}
	free(args->infile_name);
	return (new_name);
}

void	init_args_here_doc(char *argv[], int argc, t_args *args)
{
	args->infile_name = ft_strdup("tmp");
	if (!(args->infile_name))
		exit(1);
	if (!access(args->infile_name, F_OK))
		args->infile_name = make_new_file_name(args);
	args->outfile_name = argv[argc - 1];
	args->argv = argv;
	args->idx = 2;
	args->argc = argc;
	args->bonus_flag = 1;
}

void	update_cmd_in_args(int idx, t_args *args, char **envp)
{
	char	*extracted_cmd;

	extracted_cmd = extract_cmd(args->argv[idx]);
	if (ft_strchr(extracted_cmd, '/'))
		args->cmd_path = find_cmd_path_absolute_case(extracted_cmd);
	else
		args->cmd_path = find_cmd_path(extracted_cmd, envp);
	free(extracted_cmd);
	args->split_cmd = ft_split(args->argv[idx], ' ');
}
