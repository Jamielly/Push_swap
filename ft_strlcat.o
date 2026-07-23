/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luafranc <luafranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 13:30:13 by luafranc          #+#    #+#             */
/*   Updated: 2026/06/04 14:34:44 by luafranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	size_total;

	if (!s1 || !s2)
		return (NULL);
	size_total = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = malloc(size_total);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, size_total);
	ft_strlcat(str, s2, size_total);
	return (str);
}
