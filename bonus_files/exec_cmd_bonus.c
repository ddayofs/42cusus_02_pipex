/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 12:01:08 by donglee2          #+#    #+#             */
/*   Updated: 2023/07/14 17:12:34 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	exec_1st_cmd(int fds[2], t_args *args, char **envp)
{
	int	fd;

	fd = open(args->infile_name, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("bash: ", STDERR_FILENO);
		perror(args->infile_name);
		exit(1);
	}
	dup2(fd, STDIN_FILENO);
	close (fd);
	unlink("tmp");
	close(fds[0]);
	dup2(fds[1], STDOUT_FILENO);
	close(fds[1]);
	update_cmd_in_args(args->idx, args, envp);
	execve(args->cmd_path, args->split_cmd, envp);
	exit(1);
}

void	exec_mid_cmd(int tmp_fd, int fds[2], t_args *args, char **envp)
{
	dup2(tmp_fd, STDIN_FILENO);
	close(tmp_fd);
	dup2(fds[1], STDOUT_FILENO);
	close(fds[1]);
	close(fds[0]);
	update_cmd_in_args(args->idx, args, envp);
	execve(args->cmd_path, args->split_cmd, envp);
	exit(1);
}

void	exec_last_cmd(int tmp_fd, t_args *args, char **envp)
{
	int	fd;

	dup2(tmp_fd, STDIN_FILENO);
	close(tmp_fd);
	if (!(args->bonus_flag))
		fd = open(args->outfile_name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	else
		fd = open(args->outfile_name, O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fd == -1)
	{
		ft_putstr_fd("bash: ", STDERR_FILENO);
		perror(args->outfile_name);
		exit(1);
	}
	dup2(fd, STDOUT_FILENO);
	close (fd);
	update_cmd_in_args(args->idx, args, envp);
	execve(args->cmd_path, args->split_cmd, envp);
	exit(1);
}

pid_t	fork_proc(t_args *args, int fds[2], char **envp)
{
	pid_t			pid;
	static int		tmp_fd;

	pid = fork();
	if (pid < 0)
		exit(1);
	if ((pid == 0 && args->idx == 2 && !(args->bonus_flag))
		|| (pid == 0 && args->idx == 3 && args->bonus_flag))
		exec_1st_cmd(fds, args, envp);
	else if (pid == 0 && args->idx == args->argc - 2)
		exec_last_cmd(tmp_fd, args, envp);
	else if (pid == 0)
		exec_mid_cmd(tmp_fd, fds, args, envp);
	else
	{
		if ((args->idx > 2 && !(args->bonus_flag))
			|| (args->idx > 3 && args->bonus_flag))
			close(tmp_fd);
		close (fds[1]);
		tmp_fd = fds[0];
		if (args->idx < args->argc - 2)
			pipe(fds);
	}
	return (pid);
}
