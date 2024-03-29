#include <stdio.h>
#include <unistd.h>

int main(void)
{
    fork(); // En este punto el programa crea un clon de si mismo

    printf("Hola mundo, mi identificador de proceso es: %d\n", getpid());
}