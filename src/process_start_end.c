/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_start_end.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajoya-pi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:35:59 by ajoya-pi          #+#    #+#             */
/*   Updated: 2024/07/09 12:36:01 by ajoya-pi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execution(char *path, char **argv, char **envp)
{
	int	check;

	check = execve(path, argv, envp);
	if (check == -1)
	{
		matrixfree(argv);
		free(path);
		ft_printf("ERROR while executing\n");
		exit(EXIT_FAILURE);
	}
}

void	executionpathgiven(char *path, char **argv, char **envp)
{
	int	check;

	check = execve(path, argv, envp);
	if (check == -1)
	{
		matrixfree(argv);
		ft_printf("ERROR while executing\n");
		exit(EXIT_FAILURE);
	}
}

void	process_father(int *fd, char *argv[], char **envp)
{
	int		fd_input;
	char	**args;
	char	*path;

	close(fd[0]);
	fd_input = open(argv[1], O_RDONLY);
	if (fd_input == -1)
	{
		ft_printf("inputfile does not exits\n");
		exit(EXIT_FAILURE);
	}
	dup2(fd_input, STDIN_FILENO);
	close(fd_input);
	dup2(fd[1], STDOUT_FILENO);
	close (fd[1]);
	args = ft_split(argv[2], ' ');
	if (args[0][0] != '/' && args[0][0] != '.')
	{
		path = getpath(args[0], envp);
		execution(path, args, envp);
	}
	else
		executionpathgiven(args[0], args, envp);
}

void	process_son(int *fd, char *argv[], char **envp)
{
	int		fd_out;
	char	**args;
	char	*path;

	close(fd[1]);
	fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd_out == -1)
	{
		ft_printf("CAN NOT WRITE ON OUTFILE\n");
		exit(EXIT_FAILURE);
	}
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	dup2(fd_out, STDOUT_FILENO);
	close(fd_out);
	args = ft_split(argv[3], ' ');
	if (args[0][0] != '/' && args[0][0] != '.')
	{
		path = getpath(args[0], envp);
		execution(path, args, envp);
	}
	else
		executionpathgiven(args[0], args, envp);
}
