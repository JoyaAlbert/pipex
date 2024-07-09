/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajoya-pi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:35:08 by ajoya-pi          #+#    #+#             */
/*   Updated: 2024/07/09 12:35:11 by ajoya-pi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	checkargs(int argc)
{
	if (argc != 5)
	{
		ft_printf("args needed-> inputfile command1 commnad2 outputfile\n");
		exit(EXIT_FAILURE);
	}
}

void	errorpid(void)
{
	ft_printf("ERROR while getting the pid\n");
	exit(EXIT_FAILURE);
}
