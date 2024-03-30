vamos a recrear el uso de los pipes en unix usando c

un pipe permite utilizar un comando como la entrada del siguiente , ejemplo

·   < a cat | sort > outfile 

esto hara un cat del fichero a y lo organizara por orden ascendente para despues ponerlo en el fichero outfile q creara si no existe

nuestros argumentos de entrada tienen que seguir la siguiente forma

./pipex input_file "comando1" "comando2" output_file 

//por lo que para recrear el pipe de arriba seria

./pipex a "cat" "sort" output

##################################################################
cada comando o programa que ejecutemos es un proceso q tiene asociado un identificador un pid
al crear un pipe se abren dos fd uno de entrada(lectura) y otro de salida(escritura) esta almacenado en un int *

esto se veria asi (pipex.c)
```c    
pid_t   pid; //nuestro procces id
int     fd[2]; //los fd del pipe
  
pipe(fd); // creamos la tuberia abre ambos fds y guarda sus valores en fd[0] leer y fd[1] escribir

```
#####################################################################

para poder trabajar con los procesos tenemos q copiarlos (coexisten a la vez) para eso usamos la funcion fork q dara valor a nuestros pid y nos permitira trabajar con los procesos segun su jerarquia
> si el pid es 0 proceso padre

> si el pid es mayor q 0 creara otro fork del proceso y hara el proceso hijo final

```c
    pid = fork(); //copiamos el proceso para hacer ambos comandos, dara otro valor ende tenemos dos pids
    if (pid != 0)
	{
		pid = fork(); //copiamos el proceso por ende realizamos el proceso hijo (segunddo comando)  cuando este pid vale 0 y cerramos los fds del pipe
		if (pid == -1)
			errorpid();
		if (pid == 0)
			process_son(fd, argv, envp); //segundo comando
		close(fd[0]);
		close(fd[1]);
	}
    else //pid == 0 hacemos el primer proceso (padre) (primer comando)
		  process_father(fd, argv, envp);
	waitpid(pid, NULL, 0); //esperamos a q el proceso acabe

```
##################
ahora vamos a ver los procesos 
##################

primero el padre

cerramos el fichero de lectura (fd[0]) de nuestr pipe para trabajar

y abrimos el fichero de entrada de nuestros argumentos
copiamos ese fd en la entrada estandar STDIN y cerramos el original para que la entrada de argumentos ahora este en nuestra entrada estandar

hacemos lo mismo pero con la salida de nuestro pipe

y ejecutamos el comando, para eso necesitamos la direccion del comando la entrada de argumentos y la entrada de envp, para el path lo veremos mas adelante

```c
void process_father(int *fd, char *argv[], char **envp)
{
	int	fd_input;
	char	**args;
    char    *path;

	close(fd[0]); //CERRAMOS ENTRADA DL PIPE
	fd_input = open(argv[1], O_RDONLY);
	if (fd_input == -1)
    {
        perror("inputfile does not exits");
		exit(EXIT_FAILURE);
    }
	dup2(fd_input, STDIN_FILENO); //copia del fd de inputfile en el stdin
	close(fd_input);
	dup2(fd[1], STDOUT_FILENO); //copia del fd de salida del pipe en la salida estandar
	close (fd[1]); //CERRAMOS EL PIPE
	args = ft_split(argv[2], ' '); //OBTENEMOS COAMNDO
	path = getpath(args[0], envp); //OBTENEMOS EL PATH DE LOS COMANDOS
    execution(path, args, envp); //lee en nuestra entrada abierta stdin q es el input y escribe en nuesta salida abierta q es la salida del pipe en nuestr stdout
}

```
##################
el proceso hijo sigue la siguiente estructura

cerramos la salida de nuestro pipe y abrimos nustro fichero output
si no existe lo creamos y le damos los permisos para leer y escribir 0666
copiamos el fd de la entrada del pipe en la entrada estandar STDIN
y el fd de nuestro fichero de salida en la salida estandar STDOUT
ahora discernimos segun nuestro comando, si ya indica un path o no y ejecutamos 

```c
void process_son(int *fd, char *argv[], char **envp)
{
    int fd_out;
    char    **args;
    char    *path;

    close(fd[1]);
    fd_out = open(argv[4], O_WRONLY | O_CREAT |O_TRUNC, 0666); //dejame escribir si no existe crealo 0666 es el permiso deja escribir y leer pero no ejecutar
    dup2(fd[0], STDIN_FILENO); //ENTRADA DEL PIPE EN ENTRADA ESTANDAR es la salida de nuestro padre 
    close(fd[0]);
    dup2(fd_out, STDOUT_FILENO); //FICHERO DE SALIDA EN SALIDA ESTANDAR
	close(fd_out);
    args = ft_split(argv[3], ' '); //COMANDO
    if (args[0][0] != '/')
    {
        path = getpath(args[0], envp); //AVERIGUA PATH
        execution(path, args, envp); //EJECUTA COMANDO
    }
    else
        execution(args[0], args, envp); //EJECUTA COMMANDO OBTENIDO
}
```
##################
>veamos como hemos obtenido el path y como ejecutamos
primero ejecutamos

exceve ejecuta el comando que le demos con su path adecuado devuelve -1 si  enceuntra algun error 
```c
void execution(char *path, char **argv, char **envp)
{
    int check;
    check = execve(path, argv, envp);
    if (check == -1)
    {
        matrixfree(argv);
        free(path);
        perror("ERROR while executing");
        exit(EXIT_FAILURE);
    }
}
```

para el path utilizamos el envp que dice todos los datos del sistema incluyendo las rutas para los comandos del sistema se enceuntran en una linea de la forma 
PATH=
solo nos queda serparar cada directorioy juntarlo con el comando que necesitamos
para obtener la ruta completa
por ejemplo el comado ls se encuentra en la ruta "/usr/bin/ls" q es lo que le tenemos q pasar a execve

########
para eso la estrategia es recoger el path entero de todos los comandos en un array
separar cada directorio y almacenarlos en una matriz
juntar cada comando con nuestro directorio y abrir ese fichero si no existe probamos con el siguiente directorio, asi hasta q lo encontremos
y devolvemos la ruta como en el ejemplo anterior del ls


```c
char	*getpatharray(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != 0)
	{
		if (ft_strnstr(envp[i], "PATH=", 5) != NULL)
			return (ft_strnstr(envp[i], "PATH=", 5));
		i++;	
	}
	return (NULL);
}

char *getpath(char *args, char *envp[])
{
	char	**paths;
	int i;
	char	*aux;
	char	*path;
	int	fd;
	i = 0;
	paths = ft_split(ft_strchr(getpatharray(envp), '/'), ':');
	while (paths[i] != NULL)
	{
		aux = ft_strjoin(paths[i], "/");
		path = ft_strjoin(aux, args);
		free(aux);
		fd = open(path, O_RDONLY);
		if (fd >= 0)
		{
			matrixfree(paths);
			close(fd);
			return (path);
		}
		free(path);
		i++;
	}
	matrixfree(paths);
	return (NULL);
}

```
