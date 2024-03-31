

#include "pipex.h"

void leaks()
{
	system("leaks -q a.out");
}
int main(int argc, char *argv[], char **envp)
{
    pid_t   pid; //process id
    int     fd[2]; //uno para entrada y otro para salida

	checkargs(argc);
    pipe(fd); // creamos la tuberia abre ambos fds y guarda sus valores en fd[0] leer y fd[1] escribir
	pid = fork(); //copia del proceso (el progranma) cuadno vale 0 abrikmos proceso hijo todo llo demas es volver a copiay y cerrar
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
