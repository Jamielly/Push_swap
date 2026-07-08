/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamsilva <jamsilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 19:51:10 by jamsilva          #+#    #+#             */
/*   Updated: 2026/06/12 15:16:26 by jamsilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);

int	ft_print_char(int c);
int	print_format(char specifier, va_list ap);
int	handle_pointer(va_list ap);
int	ft_putnbr_base_unsigned(unsigned long long nbr, int base, char *symbols);
int	ft_putnbr(int nb);
int	ft_print_str(char	*str);

#endif
