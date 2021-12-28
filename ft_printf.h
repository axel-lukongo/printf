/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alukongo <alukongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 15:36:07 by alukongo          #+#    #+#             */
/*   Updated: 2021/12/28 19:16:44 by alukongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_PRINTF_H
# define _FT_PRINTF_H
# include<unistd.h>
# include<stdlib.h>
# include<stdio.h>
# include<stdarg.h>

int		ft_printf(const char *, ...);
int		ft_strlen(char *s);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr(int nbr, int i, char *base);
int		ft_putnbr_base(int nbr, char *base);
int		ft_unsigned(unsigned int nb);
char	*ft_uitoa(unsigned int nb);
int		nb_digit(unsigned int nb, int base);
#endif