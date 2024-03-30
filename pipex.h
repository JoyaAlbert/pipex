#ifndef PIPEX_H
# define PIPEX_H

# include <sys/types.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>



//utils
char	**ft_split(char *s, char c);
int     ft_strlen(char *str);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
char	*ft_strnstr(char *hay, char *needle, size_t len);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);

//process
void start_child(int *fd, char *argv[], char **envp);
void end_child(int *fd, char *argv[], char **envp);
//paths
char *getpath(char *args, char *envp[]);
void matrixfree(char	**matrix);

#endif