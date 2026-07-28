/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luafranc <luafranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 14:20:59 by luafranc          #+#    #+#             */
/*   Updated: 2026/06/02 13:58:12 by luafranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	strlen_dst;
	size_t	strlen_src;
	size_t	i;
	size_t	j;

	i = 0;
	strlen_src = ft_strlen(src);
	while (dst[i] && i < size)
	{
		i++;
	}
	strlen_dst = i;
	if (size <= strlen_dst)
	{
		return (strlen_src + size);
	}
	j = 0;
	while (src[j] && (strlen_dst + j) < (size - 1))
	{
		dst[strlen_dst + j] = src[j];
		j++;
	}
	dst[strlen_dst + j] = '\0';
	return (strlen_src + strlen_dst);
}
