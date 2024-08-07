/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joya <joya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:35:43 by ajoya-pi          #+#    #+#             */
/*   Updated: 2024/07/10 23:31:40 by joya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "printf/ft_printf.h"
# include <sys/types.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <string.h>

//utils
char			**ft_split(char *s, char c);
int				ft_strlen(char *str);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
char			*ft_strnstr(char *hay, char *needle, size_t len);
char			*ft_strchr(char *s, int c);
char			*ft_strjoin(char *s1, char *s2);
void			checkargs(int argc);
void			errorpid(void);

//process
void			process_father(int *fd, char *argv[], char **envp);
void			process_son(int *fd, char *argv[], char **envp);
//paths
char			*getpath(char *args, char *envp[]);
void			matrixfree(char	**matrix);

#endif
