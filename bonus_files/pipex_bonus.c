/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:04:58 by donglee2          #+#    #+#             */
/*   Updated: 2023/07/15 17:10:42 by donglee2         ###   ########seoul.kr  */
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

int	make_tmp_here_doc_file(char *eof, t_args *args)
{
	int		fd;
	char	*tmp;
	char	*new_line;

	tmp = ft_strjoin(eof, "\n");
	if (!tmp)
		exit(1);
	fd = open(args->infile_name, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd == -1)
		exit(1);
	new_line = get_next_line(0);
	while (new_line && ft_strcmp(tmp, new_line))
	{
		ft_putstr_fd(new_line, fd);
		free(new_line);
		new_line = get_next_line(0);
	}
	free(new_line);
	free(tmp);
	close(fd);
	return (fd);
}

int	main(int argc, char *argv[], char **envp)
{
	int		status;
	int		fds[2];
	pid_t	pid;
	t_args	args;

	if (argc < 5 || pipe(fds) == -1)
		return (1);
	if (!ft_strcmp(argv[1], "here_doc"))
	{
		init_args_here_doc(argv, argc, &args);
		make_tmp_here_doc_file(argv[2], &args);
	}
	else
		init_args(argv, argc, &args);
	while (++args.idx < argc - 1)
		pid = fork_proc(&args, fds, envp);
	wait_child_proc(pid, argc, &status);
}
