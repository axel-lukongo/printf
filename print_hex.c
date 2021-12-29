/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 17:16:56 by alukongo          #+#    #+#             */
/*   Updated: 2021/12/29 18:32:46 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_hex(int nbr, int i, char *base)
{
	unsigned int	nb;

	if (nbr < 0)
		nb = (4294967295 - (-1 * nbr)) + 1;
	nb = (unsigned int)nbr;
	if (nb > 0)
	{
		ft_putnbr_hex(nb / i, i, base);
		nb = nb % i;
		ft_putchar(base[nb]);
	}
}

int	ft_tcheker(char *base, int i)
{
	int	tchek;

	i = 0;
	tchek = 1;
	if (base[0] == '\0' || base[1] == '\0')
		return (1);
	while (base[i] != '\0')
	{
		if (base[i] <= 47 || base[i] >= 123 || base[i] >= ':' && base[i] <= '@')
			return (1);
		while (base[tchek] != '\0')
		{
			if (base[tchek] == base[i])
				return (1);
			tchek++;
		}
		i++;
		tchek = i + 1;
	}
	return (0);
}

int	ft_putnbr_base(int nbr, char *base)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	if (ft_tcheker(base, i) == 1)
		return (len);
	i = ft_strlen(base);
	ft_putnbr_hex(nbr, i, base);
	len = nb_digit(nbr, 16);
	return (len);
}
