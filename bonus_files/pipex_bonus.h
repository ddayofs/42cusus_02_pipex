/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:33:53 by donglee2          #+#    #+#             */
/*   Updated: 2023/07/13 17:03:04 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

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
	int		bonus_flag;
}t_args;

//exec_cmd.c
void	exec_1st_cmd(int fds[2], t_args *args, char **envp);
void	exec_last_cmd(int tmp_fd, t_args *args, char **envp);
void	exec_mid_cmd(int tmp_fd, int fds[2], t_args *args, char **envp);
pid_t	fork_proc(t_args *args, int fds[2], char **envp);

//path.c
char	*extract_cmd(char *str);
char	*find_path(char **envp);
char	*add_cmd_to_path(char *path, char *cmd);
void	free_all_splits(char **split_path);
void	print_err(char *extracted_cmd);
char	*find_cmd_path(char *cmd, char **envp);

//init_variable.c
void	init_args(char *argv[], int argc, t_args *args);
void	init_args_here_doc(char *argv[], int argc, t_args *args);
void	update_cmd_in_args(int idx, t_args *args, char **envp);

#endif