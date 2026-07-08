/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamsilva <jamsilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 21:27:09 by jamsilva          #+#    #+#             */
/*   Updated: 2026/06/10 21:27:09 by jamsilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprint.h"

int print_char(int	c)
{
	return write(1, &c, 1);
}

int print_str(char *str)
{
	int count;

	if (!str)
		return (write(1, "(null)", 6));
	count = 0;
	while (*str)
	{
		print_char((int)*str);
		++count;
		++str;
	}
	return (count);
}

int ft_putnbr_base(long nbr, int base, char *symbols)
{
	int count;

	if (nbr < 0)
	{
		write(1, "-", 1);
		return ft_putnbr_base(-nbr, base, symbols) + 1;
	}
	else if (nbr < base)
		return print_char(symbols[nbr]);
	else
	{
		count = ft_putnbr_base(nbr / base, base, symbols);
		return (count + ft_putnbr_base(nbr % base, base, symbols));
	}
    return (count);
}
