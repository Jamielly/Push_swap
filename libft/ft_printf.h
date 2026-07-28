/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luafranc <luafranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/14 13:33:51 by luafranc          #+#    #+#             */
/*   Updated: 2026/06/19 14:24:45 by luafranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_check_format(char character, va_list args);
int	ft_print_char(char c);
int	ft_print_unsigned(unsigned int nbr);
int	ft_print_nbr(int nbr);
int	ft_print_hex(unsigned int nb, char character);
int	ft_print_str(char *s);
int	ft_print_ptr(void *pointer);
int	ft_print_hex_ptr(unsigned long nb);

#endif
