/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:04:58 by donglee2          #+#    #+#             */
/*   Updated: 2023/07/13 18:20:11 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	wait_child_proc(pid_t last_pid, int argc, int *status)
{
	pid_t	pid;
	int		i;
	int		parent_status;

	i = -1;
	while (++i < argc - 3)
	{
		pid = waitpid(-1, status, 0);
		if (pid == last_pid)
			parent_status = WEXITSTATUS(*status);
	}
	exit (parent_status);
}

int	main(int argc, char *argv[], char **envp)
{
	int		status;
	int		fds[2];
	pid_t	pid;
	t_args	args;

	if (argc < 5)
		return (1);
	if (pipe(fds) == -1)
		return (1);
	init_args(argv, argc, &args);
	while (++args.idx < argc - 1)
		pid = fork_proc(&args, fds, envp);
	wait_child_proc(pid, argc, &status);
}
