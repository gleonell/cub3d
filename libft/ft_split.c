/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleonell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 16:06:21 by gleonell          #+#    #+#             */
/*   Updated: 2020/05/31 05:08:13 by gleonell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(char const *s, char c)
{
	int i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i + 1);
}

static int	ft_spnum(char const *s, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	while (s[i] == c && s[i + 1] == c)
		i++;
	if (s[i + 1] == '\0')
		return (0);
	while (s[i] != '\0')
	{
		i++;
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			j++;
	}
	if (i == j + 1)
		return (0);
	return (j + 2);
}

static void	free_words(int n_word, char **words)
{
	int i;

	i = 0;
	while (i < n_word)
	{
		free(words[i]);
		i++;
	}
	free(words);
}

static char	**make_words(char const *s, char c, char **mas, int k)
{
	int		i;
	int		j;

	j = 0;
	while (k != j && *s != '\0')
	{
		i = 0;
		while (*s == c && *s != '\0')
			s++;
		mas[j] = (char*)malloc(ft_len(s, c) * sizeof(char));
		if (!mas[j])
		{
			free_words(j + 1, mas);
			return (NULL);
		}
		while (*s != c && *s != '\0')
			mas[j][i++] = *s++;
		mas[j++][i] = '\0';
		while (*s == c && *s != '\0')
			s++;
	}
	mas[j] = NULL;
	return (mas);
}

char		**ft_split(char const *s, char c)
{
	char	**mas;
	int		k;

	k = ft_spnum(s, c);
	mas = (char**)malloc(ft_spnum(s, c) * sizeof(char*));
	if (!mas)
		return (NULL);
	return (make_words(s, c, mas, k));
}
