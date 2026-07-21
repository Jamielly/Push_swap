/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luafranc <luafranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 14:09:28 by luafranc          #+#    #+#             */
/*   Updated: 2026/06/12 10:17:37 by luafranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(long n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	long	nb;
	char	*asc;

	nb = n;
	if (n == 0)
		return (ft_strdup("0"));
	len = count_digits(nb);
	asc = (char *)malloc((len + 1) * sizeof(char));
	if (!asc)
		return (NULL);
	asc[len] = '\0';
	if (nb < 0)
	{
		asc[0] = '-';
		nb *= (-1);
	}
	while (nb > 0)
	{
		len--;
		asc[len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (asc);
}
