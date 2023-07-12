/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_variable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 12:07:05 by donglee2          #+#    #+#             */
/*   Updated: 2023/07/12 13:49:19 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	add_file_name_to_args(char *argv[], int argc, t_args *args)
{
	args->infile_name = argv[1];
	args->outfile_name = argv[argc - 1];
	args->argv = argv;
	args->idx = 1;
	args->argc = argc;
}

void	update_cmd_in_args(int idx, t_args *args, char **envp)
{
	char	*extracted;

	extracted = extract_cmd(args->argv[idx]);
	args->cmd_path = find_cmd_path(extracted, envp);
	args->split_cmd = ft_split(args->argv[idx], ' ');
}
