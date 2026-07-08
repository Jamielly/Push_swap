/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamsilva <jamsilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 17:07:31 by jamsilva          #+#    #+#             */
/*   Updated: 2026/05/26 13:26:46 by jamsilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*s1;
	unsigned char		s2;

	s1 = (const unsigned char *)s;
	s2 = (unsigned char)c;
	while (n > 0)
	{
		if (*s1 == s2)
			return ((void *)s1);
		s1++;
		n--;
	}
	return (NULL);
}
