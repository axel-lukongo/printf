/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 15:36:04 by alukongo          #+#    #+#             */
/*   Updated: 2021/12/29 18:30:34 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	conv(char c, va_list args)
{
	int	len;

	len = 0;
	if (c == 's')
		len = ft_putstr(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		len = ft_putnbr(va_arg(args, int), 10, "0123456789");
	else if (c == 'x')
		len = ft_putnbr_base(va_arg(args, int), "0123456789abcdef");
	else if (c == 'u')
		len = ft_unsigned(va_arg(args, unsigned int));
	else if (c == 'c')
		len = ft_putchar(va_arg(args, int));
	else if (c == 'p')
	{
		write(1, "0x", 2);
		len = ft_putnbr_base(va_arg(args, int), "0123456789abcdef") + 2;
	}
	else if (c == '%')
		len = ft_putchar('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	len = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
			len += conv(str[++i], args);
		else
		{
			ft_putchar(str[i]);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}
/*
int main()
{
	//char tab[6] = "ca va";
	int i = -123;
	int nb;
	int re;
	re = printf("reel %x\n", i);
	nb = ft_printf("other %x\n", i);
	
	printf("printf = %d myprintf = %d", re, nb);
}*/