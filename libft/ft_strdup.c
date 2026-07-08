/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamsilva <jamsilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 17:07:45 by jamsilva          #+#    #+#             */
/*   Updated: 2026/06/04 11:55:51 by jamsilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const unsigned char	*s1;
	unsigned char		s2;

	s1 = (const unsigned char *)s;
	s2 = (unsigned char)c;
	while (*s1 != '\0')
	{
		if (*s1 == s2)
			return ((char *)s1);
		s1++;
	}
	if (*s1 == s2)
		return ((char *)s1);
	return (NULL);
}
