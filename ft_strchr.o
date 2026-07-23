/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luafranc <luafranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 09:30:46 by luafranc          #+#    #+#             */
/*   Updated: 2026/06/09 13:24:40 by luafranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(const char *s, char c)
{
	size_t	i;
	size_t	count;

	if (!s)
		return (0);
	i = 0;
	count = 0;
	while (s[i])
	{
		if ((i == 0 || s[i - 1] == c) && s[i] != c)
			count++;
		i++;
	}
	return (count);
}

static char	**ft_allocate_words(const char *s, char c)
{
	char	**words;
	size_t	count_words;

	if (!s)
		return (NULL);
	count_words = ft_count_words(s, c);
	words = (char **)malloc((count_words + 1) * sizeof(char *));
	if (!words)
		return (NULL);
	words[count_words] = NULL;
	return (words);
}

static void	*free_words(char **words, size_t j)
{
	while (j)
		free(words[--j]);
	free(words);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	char	**words;
	size_t	i;
	size_t	j;
	size_t	pos_word;

	words = ft_allocate_words(s, c);
	if (!words)
		return (NULL);
	i = 0;
	pos_word = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (!s[i])
			break ;
		j = i;
		while (s[j] && s[j] != c)
			j++;
		words[pos_word] = ft_substr(s, i, j - i);
		if (!words[pos_word++])
			return (free_words(words, pos_word - 1));
		i = j;
	}
	return (words);
}
