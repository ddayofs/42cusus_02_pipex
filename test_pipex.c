#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "./00libft/libft.h"
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

// int main(int argc, char *argv[])
// {
// 	(void )argv;
// 	printf("argc == %d\n", argc);	
// }

// int main(int argc, char *argv[])
// {
// 	int fds[2];			// an array that will hold two file descriptors
// 	pipe(fds);			// populates fds with two file descriptors
// 	pid_t pid = fork(); // create child process that is a clone of the parent

// 	if (pid == 0)
// 	{										   // if pid == 0, then this is the child process
// 		dup2(fds[0], STDIN_FILENO);			   // fds[0] (the read end of pipe) donates its data to file descriptor 0
// 		close(fds[0]);						   // file descriptor no longer needed in child since stdin is a copy
// 		close(fds[1]);						   // file descriptor unused in child
// 		char *argv[] = {(char *)"sort", NULL}; // create argument vector
// 		if (execvp(argv[0], argv) < 0)
// 			exit(0); // run sort command (exit if something went wrong)
// 	}

// 	// if we reach here, we are in parent process
// 	close(fds[0]); // file descriptor unused in parent
// 	const char *words[] = {"pear", "peach", "apple"};
// 	// write input to the writable file descriptor so it can be read in from child:
// 	size_t numwords = sizeof(words) / sizeof(words[0]);
// 	for (size_t i = 0; i < numwords; i++)
// 	{
// 		dprintf(fds[1], "%s\n", words[i]);
// 	}

// 	// send EOF so child can continue (child blocks until all input has been processed):
// 	close(fds[1]);

// 	int status;
// 	pid_t wpid = waitpid(pid, &status, 0); // wait for child to finish before exiting
// 	return wpid == pid && WIFEXITED(status) ? WEXITSTATUS(status) : -1;
// }

// int main()
// {
// 	int **fds;
// 	int	argc = 5;
// 	fds = (int **)malloc(sizeof(int *) * argc);
// 	for (int i = 0; i < argc; i++)
// 		fds[i] = (int *)malloc(sizeof(int) * 2);
// 	for (int i = 0; i < argc; i++)
// 	{
// 		pipe(fds[i]);
// 		for (int j = 0; j < 2; j++)
// 			printf("fds[%d][%d] == %d\n", i, j, fds[i][j]);
// 	}
// }


// return value of pipe()
// int main()
// {
// 	int	fds[2];
// 	int fds2[2];
// 	int	fail[1];
// 	int	fd_num;
// 	int dup_num;

// 	fd_num = pipe(fds);
// 	printf("fd_num == %d\nfds[0] == %d\nfds[1] == %d\n", fd_num, fds[0], fds[1]);
// 	dup_num = dup2(fds[0], 1);
// 	printf("dup_num == %d\n", dup_num);
// 	// fd_num = pipe(fds2);
// 	// printf("fd_num == %d\nfds2[0] == %d\nfds2[1] == %d\n", fd_num, fds2[0], fds2[1]);
// 	// fd_num = pipe(fail);
// 	// printf("fd_num == %d\nfail[0] == %d\n", fd_num, fail[0]);
// }
// }


// int	main(int argc, char *argv[], char **envp)
// {
// 	(void)argc;
// 	(void)argv;
// 	while(*envp)
// 	{
// 		if (*(*envp + 1)== 'A' && *(*envp + 2) == 'T')
// 			printf("%s\n", *envp + 5);
// 		envp++;
// 	}
// }

// //access 함수 예제
// #include <unistd.h>
// #include <stdio.h>

// int main(int argc, char **argv)
// {
//     if (access(argv[1], X_OK) != 0)
//         perror("파일이 존재하지 않음 : ");
//     else
//         printf("파일 존재함\n");
// }

// //exit(1) 언제 사용할 수 있을까
// void	leak()
// {
// 	system("leaks a.out");
// }


// void	test()
// {
// 	char *tmp;

// 	tmp = (char *)malloc(sizeof(char));
// 	exit(1);
// }

// void	test2()
// {
// 	char *tmp;

// 	tmp = (char *)malloc(sizeof(char));
// 	if (tmp)
// 		exit(1);
// }

// int	main()
// {
// 	atexit(leak);
// 	test2();
// 	test();
// 	exit(1);
// }


// int main(int argc, char*argv[])
// {
// 	(void)argv;
// 	printf("%d\n", argc);
// }

// #include <fcntl.h>
// #include <unistd.h>

// int main() {
//     int fd = open("tmp.txt", O_WRONLY);
//     if (fd == -1) {
//         // 파일 열기 실패
//         return 1;
//     }

//     const char* data = "Hello, World!\n\n\n";
//     write(fd, data, strlen(data));

//     close(fd);
//     return 0;
// }

// int	main()
// {
// 	int fd1;
// 	int fd2;

// 	fd1 = open("file1", O_RDONLY);
// 	fd2 = open("file1", O_WRONLY);

// 	printf("%d\n", fd1);
// 	printf("%d\n", fd2);
// 	printf("%d\n", dup(fd1));
// 	printf("%d\n", dup2(fd2, fd1));
	
// }

// void print_argv1_again(char **argv)
// {
// 	printf("%s\n", argv[1]);
// }
// void print_argv1(char *argv[])
// {
// 	printf("%s\n", argv[1]);
// }

// int main(int argc, char *argv[])
// {
// 	(void)argc;
// 	print_argv1(argv);	
// 	system("leaks a.out");
// }

// int main()
// {
// 	int		status;
// 	pid_t	pid;

// 	for(int i = 0; i < 3; i++)
// 	{
// 		pid = fork();
// 		if (pid == 0)
// 		{
// 			printf("i'm child proc\nchild pid is %d\n", getpid());
// 			printf("fork() ret == %d\n\n", pid);
// 			exit(0);
// 		}
// 		else
// 		{
// 			printf("i'm parent proc\nparent pid is %d\n", getpid());
// 			printf("fork() ret == %d\n\n", pid);
// 		}
// 	}
// 	for (int k = 0; k < 3; k++)
// 	{
// 		if(pid == waitpid(-1, &status, 0))
// 			exit(WEXITSTATUS(status));
// 	}
// }

//make 2pipes---------------------------------------------------
//*****************************************************
// void make_2pipes(int ***fds)
// {
// 	int i;

// 	*fds = (int **)malloc(sizeof(int *) * 2);
// 	if (!*fds)
// 		exit(1);
// 	i = -1;
// 	while (++i < 2)
// 	{
// 		// (*fds)[i] = (int *)malloc(sizeof(int) * 2);
// 		*(*fds + i) = (int *)malloc(sizeof(int) * 2);
// 		if (!(*fds)[i])
// 			exit(1);
// 	}
// 	i = -1;
// 	while (++i < 2)
// 		pipe((*fds)[i]);
// }


// int main()
// {
// 	int	**fds;

// 	make_2pipes(&fds);
// 	for (int i = 0; i < 2; i++)
// 	{
// 		for (int j = 0; j < 2; j++)
// 		{
// 			printf("fds[%d][%d] == %d\n", i, j, fds[i][j]);
// 		}
// 		printf("\n");
// 	}
// }

//arr copy
// int main()
// {
// 	int fds[2] = {3, 4};
// 	int	*tmp;

// 	tmp = fds;
// 	for (int i = 0; i < 2; i++)
// 		printf("%d\n", *(tmp + i));
// 	printf("%p\n", tmp);
// 	printf("%p\n", fds);
// }

// // pointer of pipes
// int main()
// {
// 	int fds[2];
// 	int	*tmp;
// 	int	fds_2[2];

// 	pipe(fds);
// 	tmp= fds;
// 	printf("before:\n");
// 	for(int i = 0; i < 2; i++)
// 		printf("fds[%d] == %d\n", i, fds[i]);
// 	close(tmp[0]);
// 	close(tmp[1]);
// 	pipe(fds_2);
// 	printf("\nafter:\n");
// 	for(int i = 0; i < 2; i++)
// 		printf("fds_2[%d] == %d\n", i, fds_2[i]);
// 	printf("\nafter:\n");
// 	for(int i = 0; i < 2; i++)
// 		printf("fds[%d] == %d\n", i, fds[i]);
// 	close(fds[0]);
// 	close(fds[1]);
// }

// int main()
// {
// 	char str[6] = "angel";
// 	int a = ft_strncmp(str, "angel", 5);
// 	int	b = ft_strncmp(str, "orange", 5);

// 	printf("%d\n%d\n", a, b);
// }

// //heredoc
// int	make_tmp_heredoc_file(char *str)
// {
// 	int		fd;
// 	char	*new_line;

// 	fd = open("tmp_heredoc", O_WRONLY | O_TRUNC | O_CREAT, 0644);
// 	if (fd == -1)
// 		exit(1);
// 	new_line = get_next_line(0);
// 	while (ft_strncmp(str, new_line, ft_strlen(str)))
// 	{
// 		ft_putstr_fd(new_line, fd);
// 		free(new_line);
// 		new_line = get_next_line(0);
// 	}
// 	return (fd);
// }

// int	main()
// {
// 	make_tmp_heredoc_file("orange");
// }

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

// char	*make_new_file_name(t_args *args)
// {
// 	char	*new_name;
// 	char	*str_added;
// 	int		idx;

// 	idx = 0;
// 	new_name = ft_strdup(args->infile_name);
// 	if (!new_name)
// 		exit(1);
// 	while (!access(new_name, F_OK))
// 	{
// 		free(new_name);
// 		str_added = ft_itoa(idx);
// 		if (!str_added)
// 			exit(1);
// 		new_name = ft_strjoin(args->infile_name, str_added);
// 		if (!new_name)
// 			exit(1);
// 		free(str_added);
// 		idx++;
// 	}
// 	free(args->infile_name);
// 	system("leaks a.out");
// 	return (new_name);
// }
// void leak()
// {
// 	system("leaks a.out");
// }
// int main()
// {
// 	t_args	args;

// 	args.infile_name = ft_strdup("orange");
// 	if (!(args.infile_name))
// 		exit(1);
// 	if (!access(args.infile_name, F_OK))
// 		args.infile_name = make_new_file_name(&args);
// 	int fd = open(args.infile_name, O_RDONLY | O_CREAT, 0644);
// 	close (fd);
// 	system("leaks a.out");
// 	return (0);
// }


void	free_all_splits(char **split_path)
{
	int	i;

	i = -1;
	while (split_path[++i])
		free(split_path[i]);
	free(split_path);
}
char	*extract_cmd(char *str)
{
	char	**split_str;
	char	*tmp;

	split_str = ft_split(str, ' ');
	if (!split_str)
		exit(1);
	tmp = ft_strdup(split_str[0]);
	if (!tmp)
		exit(1);
	free_all_splits(split_str);
	return (tmp);
}

char	*find_path(char **envp)
{
	while (*envp)
	{
		if (*(*envp + 1) == 'A' && *(*envp + 2) == 'T')
			return (*envp + 5);
		envp++;
	}
	return (NULL);
}

char	*add_cmd_to_path(char *path, char *cmd)
{
	char	*tmp;

	tmp = ft_strjoin(path, "/");
	if (!tmp)
		exit(1);
	free(path);
	path = ft_strjoin(tmp, cmd);
	free (tmp);
	if (!path)
		exit(1);
	return (path);
}


void	print_err(char *extracted_cmd)
{
	ft_putstr_fd("bash: ", STDERR_FILENO);
	ft_putstr_fd(extracted_cmd, STDERR_FILENO);
	ft_putstr_fd(": command not found\n", STDERR_FILENO);
}

char	*find_cmd_path(char *extracted_cmd, char **envp)
{
	char	*path;
	char	**split_path;
	int		i;
	char	*ret;

	path = find_path(envp);
	if (!path)
		exit(1);
	split_path = ft_split(path, ':');
	if (!split_path)
		exit (1);
	i = -1;
	while (split_path[++i])
	{
		split_path[i] = add_cmd_to_path(split_path[i], extracted_cmd);
		if (!access(split_path[i], X_OK))
		{
			ret = ft_strdup(split_path[i]);
			if (!ret)
				exit(1);
			free_all_splits(split_path);
			return (ret);
		}
	}
	print_err(extracted_cmd);
	exit(127);
}

void	init_args(char *argv[], int argc, t_args *args)
{
	args->infile_name = argv[1];
	args->outfile_name = argv[argc - 1];
	args->argv = argv;
	args->idx = 1;
	args->argc = argc;
	args->bonus_flag = 0;
}

int main(int argc, char *argv[], char **envp)
{
	argc = 0;
	argv =NULL;
	char *extracted_cmd = extract_cmd("./ls");
	char *ret = find_cmd_path(extracted_cmd, envp);
	printf("%s\n", ret);
}