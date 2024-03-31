/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joya <joya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:23:03 by ajoya-pi          #+#    #+#             */
/*   Updated: 2023/12/22 10:04:06 by joya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	typeform(char c, va_list args)
{
	int	count;

	count = 0;
	if (c == '%')
		count = ft_putchar('%');
	else if (c == 's')
		count = ft_putstr(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		count = putstrn(ft_itoa(va_arg(args, int)));
	else if (c == 'c')
		count = ft_putchar(va_arg(args, int));
	else if (c == 'u')
		count = putstrn(ft_utoa(va_arg(args, unsigned int)));
	else if (c == 'x')
		count = putstrn(itoax(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (c == 'X')
		count = putstrn(itoax(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (c == 'p')
	{
		count = ft_putstr("0x");
		count = count + putstrn(ft_address(va_arg(args, void *)));
	}
	return (count);
}

int	putstrn(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	free(str);
	return (i);
}

static size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] != '\0' && i < (size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}
