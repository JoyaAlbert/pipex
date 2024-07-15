/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joya <joya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:35:30 by ajoya-pi          #+#    #+#             */
/*   Updated: 2024/07/15 20:53:40 by joya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char **envp)
{
	pid_t	pid;
	pid_t	pid1;
	int		fd[2];

	checkargs(argc);
	pipe(fd);
	pid = fork();
	if (pid == -1)
		errorpid();
	if (pid == 0)
		process_father(fd, argv, envp);
	pid1 = fork();
	if (pid1 == -1)
		errorpid();
	if (pid1 == 0)
		process_son(fd, argv, envp);
	waitpid(pid, NULL, 0);
	return (0);
}
