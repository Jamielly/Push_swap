/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamsilva <jamsilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 17:07:39 by jamsilva          #+#    #+#             */
/*   Updated: 2026/06/04 11:57:02 by jamsilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*s2;
	unsigned char		*s1;

	if (!dest && !src)
		return (NULL);
	s1 = (unsigned char *)dest;
	s2 = (const unsigned char *)src;
	if (s1 <= s2)
		ft_memcpy(dest, src, n);
	else
	{
		while (n--)
			s1[n] = s2[n];
	}
	return (dest);
}
