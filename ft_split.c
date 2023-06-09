/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amentag <amentag@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 13:11:35 by amentag           #+#    #+#             */
/*   Updated: 2022/10/19 13:14:08 by amentag          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
static	void	free_all(char **s, size_t i)
{
	i--;
	while (i >= 0)
	{
		free(s[i]);
		i--;
	}
	free(s);
}

static	size_t	calculate_nub_string(char const *s, char c)
{
	size_t	i;
	size_t	nub;
	size_t	found;
	size_t	len;

	len = ft_strlen(s);
	found = 1;
	nub = 0;
	i = 0;
	while (s[i] == c)
		i++;
	while (i < len)
	{
		if (s[i] == c)
			found = 1;
		else
		{
			if (found == 1)
				nub++;
			found = 0;
		}
		i++;
	}
	return (nub);
}

static	void	ft_copie_words(char **res, size_t nb_wor, char const *s, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (*s && i < nb_wor)
	{
		len = 0;
		while (*s && *s == c)
			s++;
		while (s[len] != '\0' && s[len] != c)
			len++;
		res[i] = malloc(len + 1);
		if (res[i] == NULL)
		{
			free_all(res, i);
			return ;
		}
		ft_strlcpy(res[i], s, len + 1);
		s += len;
		i++;
	}
	res[i] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	nub_words;

	if (s == NULL)
		return (NULL);
	while (*s && *s == c)
		s++;
	nub_words = calculate_nub_string(s, c);
	result = malloc((nub_words + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	ft_copie_words(result, nub_words, s, c);
	return (result);
}