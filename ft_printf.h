/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslaoui <sslaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 09:58:26 by sslaoui           #+#    #+#             */
/*   Updated: 2024/02/29 14:02:33 by sslaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

void	ft_putchar(char a);
void	ft_putnbr(int n);
void	ft_unsigned_putnbr(unsigned int n);
void	ft_hexa_putnbr(unsigned long n, int state);
int		ft_strlen(char	*str);
int		ft_printf(const char *str, ...);