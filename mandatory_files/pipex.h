/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:33:53 by donglee2          #+#    #+#             */
/*   Updated: 2023/07/12 13:51:29 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../00libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

typedef struct s_args
{
	int		idx;
	char	*cmd_path;
	char	**split_cmd;
	char	*infile_name;
	char	*outfile_name;
	char	**argv;
	int		argc;
}t_args;

//exec_cmd.c
void	exec_1st_cmd(char *file_name, int fds[2], t_args *args, char **envp);
void	exec_last_cmd(char *file_name, int fds[2], t_args *args, char **envp);
pid_t	exec_child_proc(t_args *args, int idx, int fds[2], char **envp);

//path.c
char	*extract_cmd(char *str);
char	*find_path(char **envp);
char	*add_cmd_to_path(char *path, char *cmd);
void	free_all_splits(char **split_path);
char	*find_cmd_path(char *cmd, char **envp);

//init_variable.c
void	add_file_name_to_args(char *argv[], int argc, t_args *args);
void	update_cmd_in_args(int idx, t_args *args, char **envp);

#endif