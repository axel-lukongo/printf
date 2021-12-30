/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_address.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 15:27:28 by alukongo          #+#    #+#             */
/*   Updated: 2021/12/30 15:55:38 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	print_address(int nbr, char *base)
{
	int	len;

	len = 0;
	if (nbr != 0)
	{
		write(1, "0x", 2);
		ft_putnbr_hex(nbr, base);
		len += (nb_digit(nbr, 16) + 2);
	}
	else
		len = ft_putstr("(nil)");
	return (len);
}
