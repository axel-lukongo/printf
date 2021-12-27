/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 15:35:54 by alukongo          #+#    #+#             */
/*   Updated: 2021/12/26 18:39:34 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
			i++;
	}
	return (i);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		ft_putchar(str[i++]);
	return (i);
}

int ft_putnbr(int nbr, int i,char *base)
{
  int lb;
  
  lb = 0;
  if(nbr > -1)
	{
		if(nbr < 0)
		{
			ft_putchar('-');
			nbr *= -1;
		}
		if(nbr > 0)
		{
			ft_putnbr(nbr/i,i,base);
			nbr = nbr%i;
			ft_putchar(base[nbr]);
		}
	}
	else
		write(1, "-1", 2);
	return(1);
}

int ft_tcheker(char *base, int i)
{
  i = 0;
  int tchek;
  tchek = 1;
  if(base[0] == '\0' || base[1] == '\0')
    return(1) ;
    
  while(base[i] != '\0')
    {
      if(base[i] <= 47 || base[i] >= 123 || base[i] >= ':' && base[i] <= '@')
	return(1);
  

      while(base[tchek] != '\0')
	{
	  if(base[tchek] == base[i])
	    return(1);
	  tchek++;
	}
      i++;
      tchek = i+1;
    }
  return(0);
}

void ft_putnbr_base(int nbr, char *base)
{
	int i;
	i = 0;
	if(ft_tcheker(base,i) == 1)
		return;
	//i=0;
	while(base[i] != '\0')
		i++;
	if(nbr > 0)
		ft_putnbr(nbr,i,base);
}
