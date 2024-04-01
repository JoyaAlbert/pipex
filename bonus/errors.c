
#include "pipex.h"

void    checkargs(int argc)
{
    if (argc < 5)
    {
        ft_printf("args needed at least-> ./pipex inputfile command1 commnad2 outputfile\n");
        exit(EXIT_FAILURE);
    }
}

void errorpid()
{
    	ft_printf("ERROR while getting the pid\n");
		exit(EXIT_FAILURE);
}