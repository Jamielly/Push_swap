/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luafranc <luafranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 12:31:18 by luafranc          #+#    #+#             */
/*   Updated: 2026/06/19 13:45:28 by luafranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_format(char character, va_list args)
{
	int	count;

	count = 0;
	if (character == 'c')
		count += ft_print_char(va_arg(args, int));
	else if (character == 's')
		count += ft_print_str(va_arg(args, char *));
	else if (character == 'u')
		count += ft_print_unsigned(va_arg(args, unsigned int));
	else if (character == 'i' || character == 'd')
		count += ft_print_nbr(va_arg(args, int));
	else if (character == 'x' || character == 'X')
		count += ft_print_hex(va_arg(args, unsigned int), character);
	else if (character == 'p')
		count += ft_print_ptr(va_arg(args, void *));
	else if (character == '%')
		count += ft_print_char('%');
	return (count);
}
