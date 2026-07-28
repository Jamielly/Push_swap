/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luafranc <luafranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 12:31:18 by luafranc          #+#    #+#             */
/*   Updated: 2026/06/19 14:25:18 by luafranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int nb, char character)
{
	char	*base;
	int		count;

	count = 0;
	if (character == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (nb >= 16)
		count += ft_print_hex((nb / 16), character);
	count += write(1, &base[nb % 16], 1);
	return (count);
}
