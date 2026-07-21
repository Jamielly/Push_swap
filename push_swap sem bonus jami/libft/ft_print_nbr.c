/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luafranc <luafranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 12:31:18 by luafranc          #+#    #+#             */
/*   Updated: 2026/06/19 14:28:41 by luafranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbr(int nbr)
{
	long	nb;
	int		count;
	char	c;

	count = 0;
	nb = nbr;
	if (nb < 0)
	{
		nb *= -1;
		count += write(1, "-", 1);
	}
	if (nb > 9)
		count += ft_print_nbr(nb / 10);
	c = (nb % 10) + '0';
	count += write(1, &c, 1);
	return (count);
}
