/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luafranc <luafranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 09:15:30 by luafranc          #+#    #+#             */
/*   Updated: 2026/06/04 13:29:41 by luafranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	s_len;
	size_t	rest;
	size_t	real_size;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	rest = s_len - start;
	if (len < rest)
		real_size = len;
	else
		real_size = rest;
	sub = (char *)malloc(real_size + 1);
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, s + start, real_size + 1);
	return (sub);
}
