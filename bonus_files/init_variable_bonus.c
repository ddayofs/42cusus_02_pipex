/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_variable_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 12:07:05 by donglee2          #+#    #+#             */
/*   Updated: 2023/07/13 19:02:23 by donglee2         ###   ########seoul.kr  */
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

void	init_args_here_doc(char *argv[], int argc, t_args *args)
{
	args->infile_name = "tmp";
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
	args->cmd_path = find_cmd_path(extracted_cmd, envp);
	free(extracted_cmd);
	args->split_cmd = ft_split(args->argv[idx], ' ');
}
