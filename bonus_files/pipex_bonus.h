/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donglee2 <donglee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:33:53 by donglee2          #+#    #+#             */
/*   Updated: 2023/07/15 17:35:30 by donglee2         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
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

typedef struct s_list_gnl
{
	int					fd_num;
	char				*save;
	struct s_list_gnl	*next;
}	t_list_gnl;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 777
# endif

//exec_cmd.c
pid_t	fork_proc(t_args *args, int fds[2], char **envp);

//path_helper.c
char	*extract_cmd(char *str);
char	*find_path(char **envp);
char	*add_cmd_to_path(char *path, char *cmd);
void	free_all_splits(char **split_path);

//path.c
char	*find_cmd_path(char *cmd, char **envp);
char	*find_cmd_path_absolute_case(char *extracted_cmd);

//init_variable.c
void	init_args(char *argv[], int argc, t_args *args);
void	init_args_here_doc(char *argv[], int argc, t_args *args);
void	update_cmd_in_args(int idx, t_args *args, char **envp);

//get_next_line.c
char	*get_next_line(int fd);

//get_next_line_utils.c
ssize_t	ft_strchr_idx(char *s, int c);
ssize_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *src);
char	*ft_substr(char const *s, unsigned int start, size_t len);

//libft.c
char	*ft_itoa(int n);
int		ft_strcmp(char *s1, char *s2);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strchr(const char *s, int c);

//libft_ft_split_bonus.c
char	**ft_split(char const *s, char c);

#endif