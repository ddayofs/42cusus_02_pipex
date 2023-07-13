/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:04:58 by donglee2          #+#    #+#             */
/*   Updated: 2023/07/13 20:37:10 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

// int	chk_name_dup(char *file_name)
// {
// 	if (!access(file_name, F_OK))
// 	{
// 		ft_strlen(filen)
// 	}
// }

int	make_tmp_here_doc_file(char *str)
{
	int		fd;
	char	*new_line;

	fd = open("tmp", O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd == -1)
		exit(1);
	new_line = get_next_line(0);
	while (ft_strncmp(str, new_line, ft_strlen(str)))
	{
		ft_putstr_fd(new_line, fd);
		free(new_line);
		new_line = get_next_line(0);
	}
	free(new_line);
	close(fd);
	return (fd);
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
	if (!ft_strncmp(argv[1], "here_doc", 5))
	{
		make_tmp_here_doc_file(argv[2]);
		init_args_here_doc(argv, argc, &args);
	}
	else
		init_args(argv, argc, &args);
	while (++args.idx < argc - 1)
		pid = fork_proc(&args, fds, envp);
	unlink("tmp");
	wait_child_proc(pid, argc, &status);
}
