/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 12:01:08 by donglee2          #+#    #+#             */
/*   Updated: 2023/07/12 13:49:10 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_1st_cmd(char *file_name, int fds[2], t_args *args, char **envp)
{
	int	fd;

	fd = open (file_name, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("bash: ", STDERR_FILENO);
		perror(file_name);
		exit(1);
	}
	dup2(fd, STDIN_FILENO);
	close (fd);
	close(fds[0]);
	dup2(fds[1], 1);
	close(fds[1]);
	update_cmd_in_args(args->idx, args, envp);
	execve(args->cmd_path, args->split_cmd, envp);
	exit(1);
}

void	exec_last_cmd(char *file_name, int fds[2], t_args *args, char **envp)
{
	int	fd;

	close(fds[1]);
	dup2(fds[0], 0);
	close(fds[0]);
	fd = open(file_name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1)
	{
		ft_putstr_fd("bash: ", STDERR_FILENO);
		perror(file_name);
		exit(1);
	}
	dup2(fd, STDOUT_FILENO);
	close (fd);
	update_cmd_in_args(args->idx, args, envp);
	execve(args->cmd_path, args->split_cmd, envp);
	exit(1);
}

pid_t	exec_child_proc(t_args *args, int idx, int fds[2], char **envp)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		exit(1);
	if (pid == 0 && idx == 2)
		exec_1st_cmd(args->infile_name, fds, args, envp);
	else if (pid == 0)
		exec_last_cmd(args->outfile_name, fds, args, envp);
	return (pid);
}
