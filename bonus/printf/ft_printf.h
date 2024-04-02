/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajoya-pi <ajoya-pi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:14:34 by ajoya-pi          #+#    #+#             */
/*   Updated: 2023/10/25 12:24:30 by ajoya-pi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int				ft_printf(char const *s, ...);
int				typeform(char c, va_list args);
int				ft_putchar(char c);
int				ft_putstr(char *c);
int				putstrn(char *str);
int				ft_putnbr(int nb);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
char			*ft_utoa(unsigned int nb);
char			*ft_itoa(int nb);
char			*itoax(unsigned int nb, char *base);
char			*ft_lutoax(unsigned long int nb, char *base);
char			*ft_address(void *p);
#endif
