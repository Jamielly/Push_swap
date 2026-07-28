/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luafranc <luafranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 12:31:18 by luafranc          #+#    #+#             */
/*   Updated: 2026/06/19 14:01:48 by luafranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex_ptr(unsigned long nb)
{
	int			count;
	char		*base;

	base = "0123456789abcdef";
	count = 0;
	if (nb >= 16)
		count += ft_print_hex_ptr(nb / 16);
	count += write(1, &base[nb % 16], 1);
	return (count);
}

int	ft_print_ptr(void *pointer)
{
	int				count;
	unsigned long	addr;

	if (!pointer)
		return (write(1, "(nil)", 5));
	count = 0;
	count += write(1, "0x", 2);
	addr = (unsigned long)pointer;
	count += ft_print_hex_ptr(addr);
	return (count);
}
