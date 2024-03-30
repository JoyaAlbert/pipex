/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joya <joya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:50:00 by ajoya-pi          #+#    #+#             */
/*   Updated: 2024/03/30 11:00:21 by joya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_strnstr(char *hay, char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[0] == '\0')
		return ((char *)hay);
	else if (len == 0)
		return (NULL);
	while (hay[i] != '\0' && (i < len))
	{
		j = 0;
		while (hay[i + j] == needle[j] && hay[i + j] != '\0'
			&& i + j < len)
			j++;
		if (needle[j] == '\0')
			return ((char *)hay + i);
		i++;
	}
	return (NULL);
}
