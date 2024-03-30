intento de explicar mi pipex

vamos a recrear el uso de los pipes en unix usando c

un pipe permite utilizar un comando como la entrada del siguiente , es decir

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

para poder trabajar con los procesos tenemos q copiarlos para eso usamos la funcion fork q dara valor a nuestros pid y nos permitira trabajar con los procesos segun su jerarquia
> si el pid es 0 proceso hijo

> si el pid es mayor q 0 creara otro fork del proceso y hara el proceso hijo final

```c
    pid = fork(); //copiamos el proceso para hacer ambos comandos, dara otro valor ende tenemos dos pids
    if (pid != 0)
	{
		pid = fork(); //copiamos el proceso por ende realizamos el proceso hijo (segunddo comando) y cerramos los fds del pipe
		if (pid == -1)
			errorpid();
		if (pid == 0)
			end_child(fd, argv, envp); //segundo comando
		close(fd[0]);
		close(fd[1]);
	}
    else //pid == 0 hacemos el primer proceso hijo (padre) (primer comando)
		  start_child(fd, argv, envp);
	waitpid(pid, NULL, 0); //e esperamos a q el proceso acabe

```

ahora vamos a ver los procesos primero el pa
