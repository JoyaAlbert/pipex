#include "pipex.h"

int	main(int argc, char *argv[], char **envp)
{
	pid_t	pid;
	int		fd[2];

	checkargs(argc);
	pipe(fd);
	pid = fork();
	if (pid == -1)
		errorpid();
	if (pid != 0)
	{
		pid = fork();
		if (pid == -1)
			errorpid();
		if (pid == 0)
			process_son(fd, argv, envp);
		close(fd[0]);
		close(fd[1]);
	}
	else
		process_father(fd, argv, envp);
	waitpid(pid, NULL, 0);
	return (0);
}
