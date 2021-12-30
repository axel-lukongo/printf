/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 17:16:56 by alukongo          #+#    #+#             */
/*   Updated: 2021/12/30 15:52:36 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_hex(int nbr, char *base)
{
	unsigned int	nb;

	nb = (unsigned int)nbr;
	if (nb > 0)
	{
		ft_putnbr_hex(nb / 16, base);
		nb = nb % 16;
		ft_putchar(base[nb]);
	}
}

int	ft_putnbr_base(int nbr, char *base)
{
	int	len;

	len = 0;
	if (nbr != 0)
		ft_putnbr_hex(nbr, base);
	else
		ft_putchar(0 + '0');
	len = nb_digit(nbr, 16);
	return (len);
}
