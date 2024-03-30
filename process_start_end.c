#include "pipex.h"

void execution(char *path, char **argv, char **envp)
{
    int check;
    check = execve(path, argv, envp);
    if (check == -1)
    {
        matrixfree(argv);
        free(path);
    }
}
void start_child(int *fd, char *argv[], char **envp)
{
	int	fd_input;
	char	**args;
    char    *path;

	close(fd[0]);
	fd_input = open(argv[1], O_RDONLY);
	if (fd_input == -1)
		exit;
	dup2(fd_input, STDIN_FILENO); //copia del fd de entrada en el stdin
	close(fd_input);
	dup2(fd[1], STDOUT_FILENO); //copia del fd de salida en la salida estandar
	close (fd[1]);
	args = ft_split(argv[2], ' ');
	path = getpath(args[0], envp);
    execution(path, args, envp);
}

void end_child(int *fd, char *argv[], char **envp)
{
    int fd_out;
    char    **args;
    char    *path;

    close(fd[1]);
    fd_out = open(argv[4], O_WRONLY | O_CREAT , 0666); //dejame escribir si no existe crealo 0666 es el permiso deja escribir y leer pero no ejecutar
    dup2(fd[0], STDIN_FILENO);
    close(fd[0]);
    dup2(fd_out, STDOUT_FILENO);
    args = ft_split(argv[3], ' ');
    if (args[0][0] != '/')
    {
        path = getpath(args[0], envp);
        execution(path, args, envp);
        free(path);
    }
    else
        execution(args[0], args, envp);
}