/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 09:34:22 by sslaoui           #+#    #+#             */
/*   Updated: 2024/02/29 15:10:35 by sslaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_print_1(const char *str, int max, int i, va_list ap)
{
	if (str[i] == 'd' || str[i] == 'i')
	{
		max = (int)va_arg(ap, int);
		ft_putnbr(max);
	}
	if (str[i] == 'u')
	{
		max = (unsigned int)va_arg(ap, unsigned int);
		ft_unsigned_putnbr(max);
	}
	if (str[i] == 'c')
	{
		max = (char)va_arg(ap, char *);
		write(1, &max, 1);
	}
	if (str[i] == 'x' || str[i] == 'X')
	{
		max = va_arg(ap, unsigned int);
		if (str[i] == 'x')
			ft_hexa_putnbr((unsigned int)max, 0);
		if (str[i] == 'X')
			ft_hexa_putnbr((unsigned int)max, 1);
	}
	return (max);
}

char	*ft_print_2(const char *str, int i, char *c, va_list ap)
{
	if (str[i] == 'd' || str[i] == 'u' || str[i] == 'c')
		i++;
	if (str[i] == 'X' || str[i] == 'x' || str[i] == 'i')
		i++;
	if (str[i] == '%')
		write(1, "%", 1);
	else if (str[i] == 's')
	{
		c = va_arg(ap, char *);
		write(1, &c[0], ft_strlen(c));
	}
	else if (str[i] == 'p')
	{
		write(1, "0x", 2);
		c = va_arg(ap, void *);
		ft_hexa_putnbr((unsigned long)&c[0], 0);
	}
	else
		write(1, &str[i], 1);
	return (c);
}

int	ft_printf(const char *str, ...)
{
	char	*c;
	int		max;
	int		i;
	va_list	ap;

	i = 0;
	max = 0;
	c = NULL;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			while (str[i] == ' ')
				i++;
			ft_print_1(str, max, i, ap);
			ft_print_2(str, i, c, ap);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
	va_end(ap);
	return (max);
}
