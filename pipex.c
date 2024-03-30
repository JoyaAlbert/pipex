

#include "pipex.h"

int main(int argc, char *argv[], char **envp)
{
    pid_t   pid; //process id
    int     fd[2]; //uno para entrada y otro para salida

    pipe(fd); // creamos la tuberia abre ambos fds y guarda sus valores en fd[0] leer y fd[1] escribir
    pid = fork(); //copia del proceso (el progranma) cuadno vale 0 abrikmos proceso hijo todo llo demas es volver a copiay y cerrar
    if (pid == -1)
        return (-1);
    if (pid != 0)
	{
		pid = fork();
		if (pid == -1)
        	return (-1);
		if (pid == 0)
			end_child(fd, argv, envp);
		close(fd[0]);
		close(fd[1]);
	}
    else
		start_child(fd, argv, envp);
	waitpid(pid, NULL, 0);
	return (0);
}
