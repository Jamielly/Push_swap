/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamsilva <jamsilva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 17:07:49 by jamsilva          #+#    #+#             */
/*   Updated: 2026/05/29 14:09:45 by jamsilva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	destlen;
	size_t	srclen;

	destlen = 0;
	while (destlen < size && dst[destlen])
		destlen++;
	srclen = 0;
	while (src[srclen])
		srclen++;
	if (destlen == size)
		return (size + srclen);
	i = 0;
	while (src[i] && (destlen + i + 1) < size)
	{
		dst[destlen + i] = src[i];
		i++;
	}
	if (destlen + i < size)
		dst[destlen + i] = '\0';
	return (destlen + srclen);
}
