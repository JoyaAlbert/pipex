/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajoya-pi <ajoya-pi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:08:01 by ajoya-pi          #+#    #+#             */
/*   Updated: 2023/10/23 14:23:49 by ajoya-pi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_address(void *p)
{
	return (ft_lutoax((unsigned long int)p, "0123456789abcdef"));
}

static char	*exceptions(unsigned long int nb)
{
	if (nb == 0)
		return (ft_itoa(nb));
	else
		return (ft_itoa(10));
}

static int	check(unsigned long int nb)
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

char	*ft_lutoax(unsigned long int nb, char *base)
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
