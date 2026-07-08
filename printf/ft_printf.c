/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamsilva <jamsilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 19:28:52 by jamsilva          #+#    #+#             */
/*   Updated: 2026/06/12 15:16:08 by jamsilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "ft_printf.h"

int	handle_pointer(va_list ap)
{
	unsigned long long	ptr;
	int					count;

	count = 0;
	ptr = (unsigned long long)va_arg(ap, void *);
	if (!ptr)
		return (ft_print_str("(nil)"));
	count += write(1, "0x", 2);
	count += ft_putnbr_base_unsigned(ptr, 16, "0123456789abcdef");
	return (count);
}

int	print_format(char specifier, va_list ap)
{
	if (specifier == 'c')
		return (ft_print_char(va_arg(ap, int)));
	else if (specifier == 's')
		return (ft_print_str(va_arg(ap, char *)));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	else if (specifier == 'u')
		return (ft_putnbr_base_unsigned(
				va_arg(ap, unsigned int), 10, "0123456789"));
	else if (specifier == 'x')
		return (ft_putnbr_base_unsigned(
				va_arg(ap, unsigned int), 16, "0123456789abcdef"));
	else if (specifier == 'X')
		return (ft_putnbr_base_unsigned(
				va_arg(ap, unsigned int), 16, "0123456789ABCDEF"));
	else if (specifier == 'p')
		return (handle_pointer(ap));
	else if (specifier == '%')
		return (ft_print_char('%'));
	return (ft_print_char(specifier));
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			count;

	if (!format)
		return (-1);
	va_start(ap, format);
	count = 0;
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			count += print_format(*format, ap);
		}
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (count);
}
