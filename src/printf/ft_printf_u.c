/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joya <joya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:34:45 by ajoya-pi          #+#    #+#             */
/*   Updated: 2023/12/22 10:04:00 by joya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check(unsigned int nb)
{
	int	i;

	i = 1;
	while (nb / 10 != 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i + 1);
}

static char	*exceptions(unsigned int nb, int i, char *a)
{
	if (nb == 0)
	{
		ft_strlcpy(a, "0", i);
		return (a);
	}
	return (NULL);
}

char	*ft_utoa(unsigned int nb)
{
	char	*a;
	int		i;

	i = check(nb);
	a = (char *)malloc(i * sizeof(char));
	if (a == NULL)
		return (NULL);
	if (nb == 0)
		return (exceptions(nb, i, a));
	a[i - 1] = '\0';
	i--;
	while (nb != 0 && i != 0)
	{
		a[i - 1] = (nb % 10) + '0';
		nb = nb / 10;
		i--;
	}
	return (a);
}
