/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 10:00:02 by sslaoui           #+#    #+#             */
/*   Updated: 2024/02/29 11:29:11 by sslaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar(char a)
{
	write(1, &a, 1);
}

void	ft_putnbr(int n)
{
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n == -2147483648)
		write(1, "2147483648", 10);
	else if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + '0');
}

void	ft_unsigned_putnbr(unsigned int n)
{
	if (n >= 10)
	{
		ft_unsigned_putnbr(n / 10);
		ft_unsigned_putnbr(n % 10);
	}
	else
		ft_putchar(n + '0');
}

void	ft_hexa_putnbr(unsigned long n, int state)
{
	char	*str;

	if (state == 0)
		str = "0123456789abcdef";
	else if (state == 1)
		str = "0123456789ABCDEF";
	if (n >= 16 && state == 0)
	{
		ft_hexa_putnbr(n / 16, 0);
		ft_hexa_putnbr(n % 16, 0);
	}
	else if (n >= 16 && state == 1)
	{
		ft_hexa_putnbr(n / 16, 1);
		ft_hexa_putnbr(n % 16, 1);
	}
	else
		ft_putchar(str[n]);
}
