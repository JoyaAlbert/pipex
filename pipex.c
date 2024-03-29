#include "pipex.h"

void executation(char *path, char **atgs, char **envp)
{

} 
void start_child(int *fd, char *argv[], char **envp)
{
	int	fd_input;
	char	**args;
	int check;

	close(fd[0]);
	fd_input = open(argv[1], O_RDONLY);
	if (fd_input == -1)
		exit;
	dup2(fd_input, stdin); //copia del fd de entrada en el stdin
	close(fd_input);
	dup2(fd[1], stdout); //copia del fd de salida en la salida estandar
	close (fd[1]);
	args = ft_split(argv[2], ' ');
	//conseguit path
	//check = execve();
}

int main(int argc, char *argv[], char **envp)
{
    pid_t   pid; //process id
    int     fd[2]; //uno para entrada y otro para salida
    pipe(fd); // creamos la tuberia abre ambos fds y guarda sus va.lores en fd[0] leer y fd[1] escribir
    pid = fork(); //copia del proceso (el progranma) cuadno vale 0 abrikmos proceso hijo todo llo demas es volver a copiay y cerrar
    if (pid == -1)
        return (-1);
    if (pid != 0)
        return 0;//copiar proceeso  cerrar elhijo y cerrar fds
    else
		start_child(fd, argv, envp);
}