
#include "pipex.h"

void    checkargs(int argc)
{
    if (argc != 5)
    {
        perror("args needed-> ./pipex inputfile command1 commnad2 outputfile");
        exit(EXIT_FAILURE);
    }
}

void errorpid()
{
    	perror("ERROR while getting the pid");
		exit(EXIT_FAILURE);
}