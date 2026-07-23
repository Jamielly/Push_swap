/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luafranc <luafranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 11:55:59 by luafranc          #+#    #+#             */
/*   Updated: 2026/06/02 15:24:56 by luafranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dest_new;
	const unsigned char	*src_new;

	if (!dest && !src)
		return (dest);
	i = 0;
	dest_new = (unsigned char *)dest;
	src_new = (unsigned char *)src;
	while (i < n)
	{
		dest_new[i] = src_new[i];
		i++;
	}
	return (dest);
}
