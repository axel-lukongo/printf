/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 15:36:04 by alukongo          #+#    #+#             */
/*   Updated: 2021/12/26 15:39:36 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void conv(char c, va_list args)
{
	if(c == 's')
		ft_putstr(va_arg(args, char *));
	else if(c == 'd' || c == 'i')
		ft_putnbr(va_arg(args, int), 10, "0123456789");
	else if(c == 'x')
		ft_putnbr_base(va_arg(args, int), "0123456789abcdef");
	else if(c == 'u')
		ft_unsigned(va_arg(args, unsigned int));
	else if(c == 'c')
		ft_putchar(va_arg(args, int));
	else if(c == 'p')
	{
		write(1, "0x", 2);
		ft_putnbr_base(va_arg(args, int), "0123456789abcdef");
	}
	else if(c == '%')
		ft_putchar('%');
}

int	ft_printf(const char *str, ...)
{
	va_list args;
	int	i;

	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if(str[i] == '%')
			conv(str[++i], args);
		else
			ft_putchar(str[i]);
		i++;
	}
	va_end(args);
}

int main()
{
	char tab[6] = "ca va";
	int i = 42;
	ft_printf("%p\n", i);
	printf("%p", i);
}