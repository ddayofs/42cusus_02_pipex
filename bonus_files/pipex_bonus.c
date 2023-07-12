/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:04:58 by donglee2          #+#    #+#             */
/*   Updated: 2023/07/12 20:56:00 by donglee2         ###   ########seoul.kr  */
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

// not freed yet
void	make_2arrs(int ***fds_ptr_ptr)
{
	int	i;

	*fds_ptr_ptr = (int **)malloc(sizeof(int *) * 2);
	if (!*fds_ptr_ptr)
		exit(1);
	i = -1;
	while (++i < 2)
	{
		*(*fds_ptr_ptr + i) = (int *)malloc(sizeof(int) * 2);
		if (!(*fds_ptr_ptr)[i])
			exit(1);
	}
}

int	make_tmp_heredoc_file(char *str)
{
	int		fd;
	char	*new_line;

	fd = open("tmp_heredoc", O_RDWR | O_TRUNC | O_CREAT, 0644);
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
	int		**fds_ptr;
	pid_t	pid;
	t_args	args;
	int		bonus_fd;

	if (argc < 5)
		return (1);
	make_2arrs(&fds_ptr);
	init_args(argv, argc, &args);
	if (!ft_strncmp(argv[1], "here_doc", 5))
	{
		make_tmp_heredoc_file(argv[2]);
		bonus_fd = open("tmp_heredoc", O_RDONLY);
		if (bonus_fd == -1)
			exit(1);
		printf("bonus_fd == %d", bonus_fd);
		args.idx = 2;
		args.infile_name = "tmp_heredoc";
		args.bonus_flag = 1;
		if (pipe(fds_ptr[1]) == -1)  
			return (1);
	}
	else
	{
		if (pipe(fds_ptr[0]) == -1) 
			return (1); 
	}
	while (++args.idx < argc - 1)
		pid = exec_child_proc(&args, fds_ptr, bonus_fd, envp);
	wait_child_proc(pid, argc, &status);
}

