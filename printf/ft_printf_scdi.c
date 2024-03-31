/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_scdi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joya <joya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:28:26 by ajoya-pi          #+#    #+#             */
/*   Updated: 2023/12/22 10:00:18 by joya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;

	if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

static int	check(int nb)
{
	int	i;

	i = 1;
	if (nb == -2147483648)
		return (12);
	if (nb < 0)
		i++;
	while (nb / 10 != 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i + 1);
}

static char	*exceptions(int nb, int i, char *a)
{
	if (nb == 0)
	{
		ft_strlcpy(a, "0", i);
		return (a);
	}
	else if (nb == -2147483648)
	{
		ft_strlcpy(a, "-2147483648", i);
		return (a);
	}
	return (NULL);
}

char	*ft_itoa(int nb)
{
	char	*a;
	int		i;

	i = check(nb);
	a = (char *)malloc(i * sizeof(char));
	if (a == NULL)
		return (NULL);
	if (nb == 0 || nb == -2147483648)
		return (exceptions(nb, i, a));
	if (nb < 0 && nb != -2147483648)
	{
		a[0] = '-';
		nb = nb * (-1);
	}
	a[i - 1] = '\0';
	i--;
	while (nb != 0 && nb != -2147483648 && i != 0)
	{
		a[i - 1] = (nb % 10) + '0';
		nb = nb / 10;
		i--;
	}
	return (a);
}
