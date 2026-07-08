/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamsilva <jamsilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 21:27:09 by jamsilva          #+#    #+#             */
/*   Updated: 2026/06/12 15:16:20 by jamsilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c)
{
	return (write(1, &c, 1));
}

int	ft_print_str(char	*str)
{
	int	count;

	if (!str)
		return (write(1, "(null)", 6));
	count = 0;
	while (*str)
	{
		ft_print_char((int)*str);
		++count;
		++str;
	}
	return (count);
}

int	ft_putnbr(int nb)
{
	long	n;
	int		count;

	n = nb;
	count = 0;
	if (n < 0)
	{
		count += write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		count += ft_putnbr(n / 10);
	count += ft_print_char((n % 10) + '0');
	return (count);
}

int	ft_putnbr_base_unsigned(unsigned long long nbr, int base, char *symbols)
{
	int	count;

	if (nbr < (unsigned long long)base)
		return (ft_print_char(symbols[nbr]));
	count = ft_putnbr_base_unsigned(nbr / base, base, symbols);
	return (count + ft_putnbr_base_unsigned(nbr % base, base, symbols));
}
