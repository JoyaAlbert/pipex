/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajoya-pi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:35:30 by ajoya-pi          #+#    #+#             */
/*   Updated: 2024/07/09 12:35:36 by ajoya-pi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char **envp)
{
	pid_t	pid;
	int		fd[2];

	checkargs(argc);
	pipe(fd);
	pid = fork();
	if (pid == -1)
		errorpid();
	if (pid != 0)
		process_son(fd, argv, envp);
	else
		process_father(fd, argv, envp);
	waitpid(pid, NULL, 0);
	return (0);
}
