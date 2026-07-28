/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luafranc <luafranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 12:31:18 by luafranc          #+#    #+#             */
/*   Updated: 2026/06/19 11:06:26 by luafranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(unsigned int nbr)
{
	int		count;
	char	c;

	count = 0;
	if (nbr > 9)
		count += ft_print_unsigned(nbr / 10);
	c = (nbr % 10) + '0';
	count += write(1, &c, 1);
	return (count);
}
