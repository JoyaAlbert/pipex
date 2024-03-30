#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv, char **envp)
{
    int i = 0;
    fork(); // En este punto el programa crea un clon de si mismo

    printf("Hola mundo, mi identificador de proceso es: %d\n", getpid());
    while (envp[i] != NULL)
    {
        printf("%s\n", envp[i]);
        i++;
    }
    
}
