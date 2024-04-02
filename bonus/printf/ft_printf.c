/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajoya-pi <ajoya-pi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:01:59 by ajoya-pi          #+#    #+#             */
/*   Updated: 2023/10/23 13:50:26 by ajoya-pi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *s, ...)
{
	int		i;
	int		counter;
	va_list	args;

	i = 0;
	va_start(args, s);
	counter = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			i++;
			counter = counter + typeform(s[i], args);
		}
		else
			counter = counter + ft_putchar(s[i]);
		i++;
	}
	va_end(args);
	return (counter);
}
