/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ele-lean <ele-lean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:02:29 by ele-lean          #+#    #+#             */
/*   Updated: 2024/10/16 16:30:54 by ele-lean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			count++;
			while (*s != c && *s)
				s++;
		}
	}
	return (count);
}

static char	*malloc_word(const char *s, char c)
{
	int		len;
	char	*word;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	word = (char *)malloc(len + 1);
	if (!word)
		return (0);
	word[len] = '\0';
	while (len > 0)
	{
		len--;
		word[len] = s[len];
	}
	return (word);
}

void	free_split(char **split, int words)
{
	int	i;

	i = 0;
	while (i < words)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	fill_array(char const *s, char c, char **split)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			split[index] = malloc_word(s + i, c);
			if (!split[index])
			{
				free_split(split, index);
				return (0);
			}
			index++;
		}
		while (s[i] != c && s[i])
			i++;
	}
	split[index] = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	if (!s)
		return (0);
	split = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!split)
		return (0);
	if (!fill_array(s, c, split))
		return (0);
	return (split);
}
