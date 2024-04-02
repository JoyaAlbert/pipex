/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajoya-pi <ajoya-pi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:41:13 by ajoya-pi          #+#    #+#             */
/*   Updated: 2023/10/23 14:27:38 by ajoya-pi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*exceptions(unsigned int nb)
{
	if (nb == 0)
		return (ft_itoa(nb));
	else
		return (ft_itoa(10));
}

static int	check(unsigned int nb)
{
	int	i;

	i = 1;
	while (nb / 16 != 0)
	{
		nb = nb / 16;
		i++;
	}
	return (i + 1);
}

char	*itoax(unsigned int nb, char *base)
{
	char	*a;
	int		i;

	i = check(nb);
	a = (char *)malloc(i * sizeof(char));
	if (a == NULL)
		return (NULL);
	if (nb == 0 || nb == 16)
	{
		free(a);
		return (exceptions(nb));
	}
	a[i - 1] = '\0';
	i--;
	while (nb != 0)
	{
		a[i - 1] = base[nb % 16];
		nb = nb / 16;
		i--;
	}
	return (a);
}
