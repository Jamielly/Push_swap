/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luafranc <luafranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 16:07:45 by luafranc          #+#    #+#             */
/*   Updated: 2026/06/09 15:52:35 by luafranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1_new;
	const unsigned char	*s2_new;
	size_t				i;

	i = 0;
	s1_new = (const unsigned char *)s1;
	s2_new = (const unsigned char *)s2;
	while (i < n && (s1_new[i] == s2_new[i]))
		i++;
	if (i == n)
		return (0);
	return (s1_new[i] - s2_new[i]);
}
